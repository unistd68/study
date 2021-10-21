/*
 * @Author: your name
 * @Date: 2021-10-21 20:02:56
 * @LastEditTime: 2021-10-21 23:38:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\libs\src\sm3.c
 */
#include "includes.h"
#include "sm3.h"
#include "../tools/tools.h"

#define SM3_BLOCK_SIZE (64)

typedef struct
{
    /*!< number of bytes processed  */
    uint32_t total[2];

    /*!< int32_termediate digest state  */
    uint32_t state[8];

    /*!< data block being processed */
    uint8_t buffer[SM3_BLOCK_SIZE];

    /*!< HMAC: inner padding        */
    uint8_t ipad[SM3_BLOCK_SIZE];

    /*!< HMAC: outer padding        */
    uint8_t opad[SM3_BLOCK_SIZE];

} sm3_ctx_t;

#define FF0(x, y, z) ((x) ^ (y) ^ (z))
#define FF1(x, y, z) (((x) & (y)) | ((x) & (z)) | ((y) & (z)))

#define GG0(x, y, z) ((x) ^ (y) ^ (z))
#define GG1(x, y, z) (((x) & (y)) | ((~(x)) & (z)))

#define SHL(x, n) (((x)&0xFFFFFFFF) << n)
#define ROTL(x, n) (SHL((x), n) | ((x) >> (32 - n)))

#define P0(x) ((x) ^ ROTL((x), 9) ^ ROTL((x), 17))
#define P1(x) ((x) ^ ROTL((x), 15) ^ ROTL((x), 23))

static inline uint32_t load_u32_be(const uint8_t *b)
{
    return b[0] << 24 | b[1] << 16 | b[2] << 8 | b[3];
}

static inline void store_u32_be(uint32_t v, uint8_t *b)
{
    b[0] = (uint8_t)(v >> 24);
    b[1] = (uint8_t)(v >> 16);
    b[2] = (uint8_t)(v >> 8);
    b[3] = (uint8_t)(v);
}

static void sm3_process(sm3_ctx_t *ctx, uint8_t *data)
{
    uint32_t SS1, SS2, TT1, TT2, w[68], w1[SM3_BLOCK_SIZE];
    uint32_t A, B, C, D, E, F, G, H;
    uint32_t t[SM3_BLOCK_SIZE];
    uint32_t temp1, temp2, temp3, temp4, temp5;
    int32_t i, j;

    for (j = 0; j < 16; j++)
    {
        t[j] = 0x79CC4519;
    }

    for (j = 16; j < SM3_BLOCK_SIZE; j++)
    {
        t[j] = 0x7A879D8A;
    }

    for (j = 0, i = 0; j < 16; j++, i += 4)
    {
        w[j] = load_u32_be(data + i);
    }

    for (j = 16; j < 68; j++)
    {
        temp1 = w[j - 16] ^ w[j - 9];
        temp2 = ROTL(w[j - 3], 15);
        temp3 = temp1 ^ temp2;
        temp4 = P1(temp3);
        temp5 = ROTL(w[j - 13], 7) ^ w[j - 6];
        w[j] = temp4 ^ temp5;
    }

    for (j = 0; j < SM3_BLOCK_SIZE; j++)
    {
        w1[j] = w[j] ^ w[j + 4];
    }

    A = ctx->state[0];
    B = ctx->state[1];
    C = ctx->state[2];
    D = ctx->state[3];
    E = ctx->state[4];
    F = ctx->state[5];
    G = ctx->state[6];
    H = ctx->state[7];

    for (j = 0; j < 16; j++)
    {
        SS1 = ROTL((ROTL(A, 12) + E + ROTL(t[j], j)), 7);
        SS2 = SS1 ^ ROTL(A, 12);
        TT1 = FF0(A, B, C) + D + SS2 + w1[j];
        TT2 = GG0(E, F, G) + H + SS1 + w[j];
        D = C;
        C = ROTL(B, 9);
        B = A;
        A = TT1;
        H = G;
        G = ROTL(F, 19);
        F = E;
        E = P0(TT2);
    }

    for (j = 16; j < SM3_BLOCK_SIZE; j++)
    {
        SS1 = ROTL((ROTL(A, 12) + E + ROTL(t[j], j)), 7);
        SS2 = SS1 ^ ROTL(A, 12);
        TT1 = FF1(A, B, C) + D + SS2 + w1[j];
        TT2 = GG1(E, F, G) + H + SS1 + w[j];
        D = C;
        C = ROTL(B, 9);
        B = A;
        A = TT1;
        H = G;
        G = ROTL(F, 19);
        F = E;
        E = P0(TT2);
    }

    ctx->state[0] ^= A;
    ctx->state[1] ^= B;
    ctx->state[2] ^= C;
    ctx->state[3] ^= D;
    ctx->state[4] ^= E;
    ctx->state[5] ^= F;
    ctx->state[6] ^= G;
    ctx->state[7] ^= H;
}

static void sm3_update(sm3_ctx_t *ctx, uint8_t *input, uint32_t ilen)
{
    uint32_t fill;
    uint32_t left;

    if (ilen <= 0)
    {
        return;
    }

    left = ctx->total[0] & 0x3F;
    fill = SM3_BLOCK_SIZE - left;

    ctx->total[0] += ilen;
    ctx->total[0] &= 0xFFFFFFFF;

    if (ctx->total[0] < ilen)
    {
        ctx->total[1]++;
    }

    if (left && ilen >= fill)
    {
        memcpy(ctx->buffer + left, input, fill);
        sm3_process(ctx, ctx->buffer);
        input += fill;
        ilen -= fill;
        left = 0;
    }

    while (ilen >= SM3_BLOCK_SIZE)
    {
        sm3_process(ctx, input);
        input += SM3_BLOCK_SIZE;
        ilen -= SM3_BLOCK_SIZE;
    }

    if (ilen > 0)
    {
        memcpy(ctx->buffer + left, input, ilen);
    }
}

static uint8_t sm3_padding[SM3_BLOCK_SIZE] =
    {
        0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static void sm3_finish(sm3_ctx_t *ctx, uint8_t *output)
{
    uint32_t last, padn;
    uint32_t high, low, idx;
    uint8_t msglen[8];

    high = (ctx->total[0] >> 29) | (ctx->total[1] << 3);
    low = ctx->total[0] << 3;

    store_u32_be(high, msglen);
    store_u32_be(low, msglen + 4);

    last = ctx->total[0] & 0x3F;
    padn = last < 56 ? 56 - last : 120 - last;

    sm3_update(ctx, sm3_padding, padn);
    sm3_update(ctx, msglen, 8);

    for (idx = 0; idx < 8; idx++, output += 4)
    {
        store_u32_be(ctx->state[idx], output);
    }
}

static void sm3_starts(sm3_ctx_t *ctx)
{
    ctx->total[0] = 0;
    ctx->total[1] = 0;

    ctx->state[0] = 0x7380166F;
    ctx->state[1] = 0x4914B2B9;
    ctx->state[2] = 0x172442D7;
    ctx->state[3] = 0xDA8A0600;
    ctx->state[4] = 0xA96F30BC;
    ctx->state[5] = 0x163138AA;
    ctx->state[6] = 0xE38DEE4D;
    ctx->state[7] = 0xB0FB0E4E;
}

void sm3_proc(uint8_t *input, int32_t ilen, uint8_t *output)
{
    sm3_ctx_t ctx;

    sm3_starts(&ctx);
    sm3_update(&ctx, input, ilen);
    sm3_finish(&ctx, output);
}

static void sm3_hmac_starts(sm3_ctx_t *ctx, uint8_t *key, int32_t keylen)
{
    int32_t i;
    uint8_t sum[32];

    if (keylen > SM3_BLOCK_SIZE)
    {
        sm3_proc(key, keylen, sum);
        keylen = 32;
        key = sum;
    }

    memset(ctx->ipad, 0x36, SM3_BLOCK_SIZE);
    memset(ctx->opad, 0x5C, SM3_BLOCK_SIZE);

    for (i = 0; i < keylen; i++)
    {
        ctx->ipad[i] = ctx->ipad[i] ^ key[i];
        ctx->opad[i] = ctx->opad[i] ^ key[i];
    }

    sm3_starts(ctx);
    sm3_update(ctx, ctx->ipad, SM3_BLOCK_SIZE);
}

static void sm3_hmac_update(sm3_ctx_t *ctx, uint8_t *input, int32_t ilen)
{
    sm3_update(ctx, input, ilen);
}

static void sm3_hmac_finish(sm3_ctx_t *ctx, uint8_t *output)
{
    int32_t hlen = 32;
    uint8_t tmpbuf[32];

    sm3_finish(ctx, tmpbuf);
    sm3_starts(ctx);
    sm3_update(ctx, ctx->opad, SM3_BLOCK_SIZE);
    sm3_update(ctx, tmpbuf, hlen);
    sm3_finish(ctx, output);
}

void sm3_hmac(uint8_t *key, int32_t keylen, uint8_t *input, int32_t ilen, uint8_t *output)
{
    sm3_ctx_t ctx;

    sm3_hmac_starts(&ctx, key, keylen);
    sm3_hmac_update(&ctx, input, ilen);
    sm3_hmac_finish(&ctx, output);
}

static int32_t show_hex(int8_t* title, void* buf, uint32_t total)
{
	uint32_t idx;
	uint8_t* data = buf;

	printf("%s(%d):\n\t", title, total);
	for (idx = 0; idx < total; idx++) {
		printf("%02hhx", data[idx]);
		printf("%s", 15 == (idx & 15) ? "\n\t" : ", ");
	}
	printf("\n");
	
	return 0;
}

int ASCII2SM3(unsigned char *in, int len, unsigned char *out)
{
    unsigned char temp[1024] = {0};
    int len = ascii2HexArray(in, strlen(in), temp);
    uint8_t buf[64];

    sm3_proc(temp, len, buf);
    show_hex("data", td, sizeof(td));
    show_hex("buf", buf, 32);
}

int HEX2SM3(unsigned char *in, int len, unsigned char *out)
{
    len = sm3_pad_message(in, len);

    //print_str(str, len);

    len = sm3_str_group(in, len);

    //print_str(str, len);

    sm3_str_summ(in, out, len);

    //print_str(str, len);

    print_str(out, 32);
    return 0;
}
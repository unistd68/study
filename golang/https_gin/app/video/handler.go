/*
 * @Author: your name
 * @Date: 2021-11-08 10:39:41
 * @LastEditTime: 2021-11-14 17:40:10
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\app\shop\handler.go
 */

 package video

 import (
	"fmt"
	"github.com/gin-gonic/gin"
	"encoding/json"
	"net/http"

	model "https_gin/app/model"
	dbmysql "https_gin/app/mysql"
 )

func getVideoMsg(c *gin.Context) {
	sqlStr := "select * from tb_address_info"
	buf,err := dbmysql.QueryDB(sqlStr);
	if err != nil {
        panic(err)
    }
    println(string(buf))
	// c.String(http.StatusOK, string(buf))
	var respBuff = "{\"data\":[{\"Id\":1,\"no\":\"01\",\"title\":\"20年200大进球\",\"type\":\"mp4\",\"url\":\"http://192.168.1.113:9000/video/%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83/%28%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83%2920%E5%B9%B4%C2%B7200%E5%A4%A7%E8%BF%9B%E7%90%83%20%E6%AC%A3%E8%B5%8F%E9%82%A3%E4%BA%9B%E7%BE%8E%E5%A6%99%E8%BF%9B%E7%90%83.mp4?X-Amz-Algorithm=AWS4-HMAC-SHA256\\u0026X-Amz-Credential=R6BAM3HAOXM0NGA9S7AD%2F20211127%2Fus-east-1%2Fs3%2Faws4_request\\u0026X-Amz-Date=20211127T060857Z\\u0026X-Amz-Expires=604799\\u0026X-Amz-Security-Token=eyJhbGciOiJIUzUxMiIsInR5cCI6IkpXVCJ9.eyJhY2Nlc3NLZXkiOiJSNkJBTTNIQU9YTTBOR0E5UzdBRCIsImV4cCI6MTYzNzk5NjYyNSwicG9saWN5IjoiY29uc29sZUFkbWluIn0.3T60EyAgkZZ4gBLc4hxCrIg6AEajLSp0H44QOk0IEDF6GwYLSji7A6Y28VwnzDmr_wE-seRfs0FI0FG8XOCKjQ\\u0026X-Amz-SignedHeaders=host\\u0026versionId=null\\u0026X-Amz-Signature=3c08c1531b59f63711385cd6fddc3b8c4235ab129370b4736725ef5d9b24d61d\"},{\"Id\":2,\"no\":\"02\",\"title\":\"20年20大纪录\",\"type\":\"mp4\",\"url\":\"http://192.168.1.113:9000/video/%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83/%28%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83%2920201109%2020%E5%B9%B420%E5%A4%A7%E7%BA%AA%E5%BD%95.mp4?X-Amz-Algorithm=AWS4-HMAC-SHA256\\u0026X-Amz-Credential=R6BAM3HAOXM0NGA9S7AD%2F20211127%2Fus-east-1%2Fs3%2Faws4_request\\u0026X-Amz-Date=20211127T060840Z\\u0026X-Amz-Expires=604799\\u0026X-Amz-Security-Token=eyJhbGciOiJIUzUxMiIsInR5cCI6IkpXVCJ9.eyJhY2Nlc3NLZXkiOiJSNkJBTTNIQU9YTTBOR0E5UzdBRCIsImV4cCI6MTYzNzk5NjYyNSwicG9saWN5IjoiY29uc29sZUFkbWluIn0.3T60EyAgkZZ4gBLc4hxCrIg6AEajLSp0H44QOk0IEDF6GwYLSji7A6Y28VwnzDmr_wE-seRfs0FI0FG8XOCKjQ\\u0026X-Amz-SignedHeaders=host\\u0026versionId=null\\u0026X-Amz-Signature=05b45845b07c0209f1e3799d46d751c8ab9b909592fcf5dd2994141d0442a959\"},{\"Id\":3,\"no\":\"03\",\"title\":\"那些年，我们一起追的球星：亨利\",\"type\":\"mp4\",\"url\":\"http://192.168.1.113:9000/video/%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83/%28%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83%29%E9%82%A3%E4%BA%9B%E5%B9%B4%EF%BC%8C%E6%88%91%E4%BB%AC%E4%B8%80%E8%B5%B7%E8%BF%BD%E7%9A%84%E7%90%83%E6%98%9F%EF%BC%9A%E4%BA%A8%E5%88%A9.mp4?X-Amz-Algorithm=AWS4-HMAC-SHA256\\u0026X-Amz-Credential=R6BAM3HAOXM0NGA9S7AD%2F20211127%2Fus-east-1%2Fs3%2Faws4_request\\u0026X-Amz-Date=20211127T060947Z\\u0026X-Amz-Expires=604799\\u0026X-Amz-Security-Token=eyJhbGciOiJIUzUxMiIsInR5cCI6IkpXVCJ9.eyJhY2Nlc3NLZXkiOiJSNkJBTTNIQU9YTTBOR0E5UzdBRCIsImV4cCI6MTYzNzk5NjYyNSwicG9saWN5IjoiY29uc29sZUFkbWluIn0.3T60EyAgkZZ4gBLc4hxCrIg6AEajLSp0H44QOk0IEDF6GwYLSji7A6Y28VwnzDmr_wE-seRfs0FI0FG8XOCKjQ\\u0026X-Amz-SignedHeaders=host\\u0026versionId=null\\u0026X-Amz-Signature=1641565209634e961bf8faa89e0885cce6db3f3032dfedeb30c53047a572c251\"},{\"Id\":4,\"no\":\"04\",\"title\":\"那些年，我们一起追的球星：卡卡\",\"type\":\"mp4\",\"url\":\"http://192.168.1.113:9000/video/%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83/%28%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83%29%E9%82%A3%E4%BA%9B%E5%B9%B4%EF%BC%8C%E6%88%91%E4%BB%AC%E4%B8%80%E8%B5%B7%E8%BF%BD%E7%9A%84%E7%90%83%E6%98%9F%EF%BC%9A%E5%8D%A1%E5%8D%A1.mp4?X-Amz-Algorithm=AWS4-HMAC-SHA256\\u0026X-Amz-Credential=R6BAM3HAOXM0NGA9S7AD%2F20211127%2Fus-east-1%2Fs3%2Faws4_request\\u0026X-Amz-Date=20211127T061001Z\\u0026X-Amz-Expires=604799\\u0026X-Amz-Security-Token=eyJhbGciOiJIUzUxMiIsInR5cCI6IkpXVCJ9.eyJhY2Nlc3NLZXkiOiJSNkJBTTNIQU9YTTBOR0E5UzdBRCIsImV4cCI6MTYzNzk5NjYyNSwicG9saWN5IjoiY29uc29sZUFkbWluIn0.3T60EyAgkZZ4gBLc4hxCrIg6AEajLSp0H44QOk0IEDF6GwYLSji7A6Y28VwnzDmr_wE-seRfs0FI0FG8XOCKjQ\\u0026X-Amz-SignedHeaders=host\\u0026versionId=null\\u0026X-Amz-Signature=7b319ec89a1dffc2642d6edf7d7875dafd45e8e58369fdca11a42b503a554663\"},{\"Id\":5,\"no\":\"05\",\"title\":\"那些年，我们一起追的球星：克洛泽\",\"type\":\"mp4\",\"url\":\"http://192.168.1.113:9000/video/%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83/%28%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83%29%E9%82%A3%E4%BA%9B%E5%B9%B4%EF%BC%8C%E6%88%91%E4%BB%AC%E4%B8%80%E8%B5%B7%E8%BF%BD%E7%9A%84%E7%90%83%E6%98%9F%EF%BC%9A%E5%85%8B%E6%B4%9B%E6%B3%BD.mp4?X-Amz-Algorithm=AWS4-HMAC-SHA256\\u0026X-Amz-Credential=R6BAM3HAOXM0NGA9S7AD%2F20211127%2Fus-east-1%2Fs3%2Faws4_request\\u0026X-Amz-Date=20211127T061013Z\\u0026X-Amz-Expires=604799\\u0026X-Amz-Security-Token=eyJhbGciOiJIUzUxMiIsInR5cCI6IkpXVCJ9.eyJhY2Nlc3NLZXkiOiJSNkJBTTNIQU9YTTBOR0E5UzdBRCIsImV4cCI6MTYzNzk5NjYyNSwicG9saWN5IjoiY29uc29sZUFkbWluIn0.3T60EyAgkZZ4gBLc4hxCrIg6AEajLSp0H44QOk0IEDF6GwYLSji7A6Y28VwnzDmr_wE-seRfs0FI0FG8XOCKjQ\\u0026X-Amz-SignedHeaders=host\\u0026versionId=null\\u0026X-Amz-Signature=f026589b6b4731248c50114ad472535995d36f3e8e048c027f9c986bcf539720\"}]}"
	var respBuff2 = "{\"data\":" + string(buf) + "}"
	str:=[]byte(string(respBuff))
	var videos model.Video
	err = json.Unmarshal(str,&videos)
	if err!=nil{
        fmt.Println(err)
    }
	fmt.Println("ok1")

	str=[]byte(string(respBuff2))
	err = json.Unmarshal(str,&videos)
	if err!=nil{
        fmt.Println(err)
    }
	fmt.Println("ok2")

	var videos2 model.Video2
	str=[]byte(string(buf))
	err = json.Unmarshal(str,&videos2)
	if err!=nil{
        fmt.Println(err)
    }
	fmt.Println("ok3")

	fmt.Println("%v",&videos2)
	c.JSON(http.StatusOK,videos2)
}

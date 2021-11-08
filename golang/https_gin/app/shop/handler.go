/*
 * @Author: your name
 * @Date: 2021-11-08 10:39:41
 * @LastEditTime: 2021-11-08 15:01:24
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\app\shop\handler.go
 */

 package shop

 import (
	"fmt"
	"github.com/gin-gonic/gin"
 )

func goodsHandler(e *gin.Engine) {
	fmt.Println("this is goodsHandler\n")
}

func checkoutHandler(e *gin.Engine) {
	fmt.Println("this is checkoutHandler\n")
}
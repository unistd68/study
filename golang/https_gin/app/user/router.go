/*
 * @Author: your name
 * @Date: 2021-11-08 10:39:49
 * @LastEditTime: 2021-11-08 16:06:31
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\app\shop\router.go
 */
 package user

 import (
	"fmt"
	"github.com/gin-gonic/gin"
  )



 func Routers(e *gin.Engine) {
	e.GET("/login", user_login)
	e.GET("/testdb", testdb)
	e.GET("/testjson", testjson)
}
/*
 * @Author: your name
 * @Date: 2021-11-08 10:39:49
 * @LastEditTime: 2021-11-14 17:24:40
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\app\shop\router.go
 */
 package user

 import (
	"github.com/gin-gonic/gin"
  )



 func Routers(e *gin.Engine) {
	e.POST("/api/login/account", userLogin)
	e.GET("/api/currentUser", currentUser)
	e.GET("/api/notices", userNotices)
	e.POST("/api/outLogin", outLogin)
	e.GET("/testdb", testdb)
	e.GET("/testjson", testjson)
}
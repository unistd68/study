/*
 * @Author: your name
 * @Date: 2021-11-08 10:39:29
 * @LastEditTime: 2021-11-08 14:57:01
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\app\blog\router.go
 */
 package blog

 import (
	"github.com/gin-gonic/gin"
  )

 func Routers(e *gin.Engine) {
	e.GET("/post", postHandler)
	e.GET("/comment", commentHandler)
}
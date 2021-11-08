/*
 * @Author: your name
 * @Date: 2021-11-08 10:39:20
 * @LastEditTime: 2021-11-08 14:27:04
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\app\blog\handler.go
 */

 package blog

 import (
	 "net/http"
	 "github.com/gin-gonic/gin"
	 "fmt"
 )

 func LoadBlog(e *gin.Engine) {
	e.GET("/post", postHandler)
  e.GET("/comment", commentHandler)
}

func postHandler(e *gin.Engine) {
	fmt.Println("this is postHandler\n")
}

func commentHandler(e *gin.Engine) {
	fmt.Println("this is commentHandler\n")
}
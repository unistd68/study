/*
 * @Author: your name
 * @Date: 2021-11-08 10:39:49
 * @LastEditTime: 2021-11-08 15:10:30
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\app\shop\router.go
 */
 package shop

 import (
	"github.com/gin-gonic/gin"
  )

  func test2(e *gin.Engine) {
	fmt.Println("this is test2\n")
}

 func Routers(e *gin.Engine) {
	// e.GET("/goods", goodsHandler)
	// e.GET("/checkout", checkoutHandler)
	e.GET("/test2", test2)
}
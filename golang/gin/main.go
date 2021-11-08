/*
 * @Author: your name
 * @Date: 2021-11-08 09:56:58
 * @LastEditTime: 2021-11-08 13:30:53
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\main.go
 */
 package main

 import (
	 "net/http"
	 "github.com/gin-gonic/gin"
	 "fmt"
 )
 
//  func initServ(c *gin.Context,ip int,port int)
//  {
// 	 // 1.创建路由
//    // 默认使用了2个中间件Logger(), Recovery()
//    r := gin.Default()
//    // 路由组1 ，处理GET请求
//    v1 := r.Group("/v1")
//    // {} 是书写规范
//    {
//       v1.GET("/login", login)
//       v1.GET("submit", submit)
//    }
//    v2 := r.Group("/v2")
//    {
//       v2.POST("/login", login)
//       v2.POST("/submit", submit)
//    }
//    var url string
//    fmt.Sprintf(url,ip,":", port)
//    r.Run(url)
//  }

//  func main() {
// 	 // 1.创建路由
// 	r := gin.Default()
// 	// 2.绑定路由规则，执行的函数
// 	// gin.Context，封装了request和response
// 	r.GET("/", func(c *gin.Context) {
// 	   c.String(http.StatusOK, "hello World!")
// 	})
// 	// 3.监听端口，默认在8080
// 	// Run("里面不指定端口号默认为8080") 
// 	r.Run(":8888")
//  }

 func main() {
	// 加载多个APP的路由配置
	routers.Include(shop.Routers, blog.Routers)
	// 初始化路由
	r := routers.Init()
	if err := r.Run(":8888"); err != nil {
		fmt.Println(" startup service failed, err:%v\n", err)
	}
}


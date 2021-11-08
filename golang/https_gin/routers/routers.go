/*
 * @Author: your name
 * @Date: 2021-11-08 10:40:28
 * @LastEditTime: 2021-11-08 14:56:50
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\routers\routers.go
 */

 package routers

 import (
	"github.com/gin-gonic/gin"
 )
 
 type Option func(*gin.Engine)

 var options = []Option{}
 
 // 注册app的路由配置
 func Include(opts ...Option) {
	 options = append(options, opts...)
 }
 
 // 初始化
 func Init() *gin.Engine {
	 r := gin.Default()
	 for _, opt := range options {
		 opt(r)
	 }
	 return r
 }
/*
 * @Author: your name
 * @Date: 2021-11-08 10:39:49
 * @LastEditTime: 2021-12-02 16:11:24
 * @LastEditors: Ace
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\app\shop\router.go
 */
 package menu

 import (
	"github.com/gin-gonic/gin"
  )



 func Routers(e *gin.Engine) {
	e.GET("/api/rule", getRule)
	e.POST("/api/rule", postRule)

	e.GET("/api/tags", getRule)
	e.POST("/api/fake_list", postRule)
	e.GET("/api/card_fake_list", getRule)
	e.POST("/api/profile/basic/", postRule)
	e.GET("/api/profile/advanced", getRule)
	e.POST("/api/currentUserDetail", postRule)
	e.GET("/api/accountSettingCurrentUser", getRule)
	e.POST("/api/geographic/province", postRule)
}

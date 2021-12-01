/*
 * @Author: your name
 * @Date: 2021-11-08 10:39:49
 * @LastEditTime: 2021-11-14 17:24:40
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\app\shop\router.go
 */
 package chart

 import (
	"github.com/gin-gonic/gin"
  )



 func Routers(e *gin.Engine) {
	e.GET("/api/fake_workplace_chart_data", getWorkChartData)
	e.GET("/api/fake_analysis_chart_data/", getAnalysisChartData)
	e.GET("/api/activities", getActivities)
	e.GET("/api/project/notice", getProNotices)
}
/*
 * @Author: your name
 * @Date: 2021-11-08 10:39:41
 * @LastEditTime: 2021-11-14 17:40:10
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\app\shop\handler.go
 */

 package menu

 import (
	"fmt"
	"github.com/gin-gonic/gin"
	"encoding/json"
	"net/http"
	// "path"
	// "io/ioutil"
	// "path/filepath"
	// "strings"

	model "https_gin/app/model"
	// dbmysql "https_gin/app/mysql"
 )

func getRule(c *gin.Context) {
	// str := getRuleTest()
	str := "{\"data\":[{\"key\":99,\"disabled\":false,\"href\":\"https://ant.design\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/udxAbMEhpwthVVcjLXik.png\",\"name\":\"TradeCode 99\",\"owner\":\"曲丽丽\",\"desc\":\"这是一段描述\",\"callNo\":716,\"status\":\"0\",\"updatedAt\":\"2021-12-01T10:17:31.353Z\",\"createdAt\":\"2021-12-01T10:17:31.353Z\",\"progress\":78},{\"key\":98,\"disabled\":false,\"href\":\"https://ant.design\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/eeHMaZBwmTvLdIwMfBpg.png\",\"name\":\"TradeCode 98\",\"owner\":\"曲丽丽\",\"desc\":\"这是一段描述\",\"callNo\":945,\"status\":\"0\",\"updatedAt\":\"2021-12-01T10:17:31.353Z\",\"createdAt\":\"2021-12-01T10:17:31.353Z\",\"progress\":37},{\"key\":97,\"disabled\":false,\"href\":\"https://ant.design\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/udxAbMEhpwthVVcjLXik.png\",\"name\":\"TradeCode 97\",\"owner\":\"曲丽丽\",\"desc\":\"这是一段描述\",\"callNo\":69,\"status\":\"2\",\"updatedAt\":\"2021-12-01T10:17:31.353Z\",\"createdAt\":\"2021-12-01T10:17:31.353Z\",\"progress\":21},{\"key\":96,\"disabled\":true,\"href\":\"https://ant.design\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/eeHMaZBwmTvLdIwMfBpg.png\",\"name\":\"TradeCode 96\",\"owner\":\"曲丽丽\",\"desc\":\"这是一段描述\",\"callNo\":80,\"status\":\"0\",\"updatedAt\":\"2021-12-01T10:17:31.353Z\",\"createdAt\":\"2021-12-01T10:17:31.353Z\",\"progress\":28},{\"key\":95,\"disabled\":false,\"href\":\"https://ant.design\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/udxAbMEhpwthVVcjLXik.png\",\"name\":\"TradeCode 95\",\"owner\":\"曲丽丽\",\"desc\":\"这是一段描述\",\"callNo\":686,\"status\":\"1\",\"updatedAt\":\"2021-12-01T10:17:31.353Z\",\"createdAt\":\"2021-12-01T10:17:31.353Z\",\"progress\":35},{\"key\":94,\"disabled\":false,\"href\":\"https://ant.design\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/eeHMaZBwmTvLdIwMfBpg.png\",\"name\":\"TradeCode 94\",\"owner\":\"曲丽丽\",\"desc\":\"这是一段描述\",\"callNo\":910,\"status\":\"0\",\"updatedAt\":\"2021-12-01T10:17:31.353Z\",\"createdAt\":\"2021-12-01T10:17:31.353Z\",\"progress\":100},{\"key\":93,\"disabled\":false,\"href\":\"https://ant.design\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/udxAbMEhpwthVVcjLXik.png\",\"name\":\"TradeCode 93\",\"owner\":\"曲丽丽\",\"desc\":\"这是一段描述\",\"callNo\":858,\"status\":\"0\",\"updatedAt\":\"2021-12-01T10:17:31.353Z\",\"createdAt\":\"2021-12-01T10:17:31.353Z\",\"progress\":61},{\"key\":92,\"disabled\":false,\"href\":\"https://ant.design\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/eeHMaZBwmTvLdIwMfBpg.png\",\"name\":\"TradeCode 92\",\"owner\":\"曲丽丽\",\"desc\":\"这是一段描述\",\"callNo\":713,\"status\":\"1\",\"updatedAt\":\"2021-12-01T10:17:31.353Z\",\"createdAt\":\"2021-12-01T10:17:31.353Z\",\"progress\":39},{\"key\":91,\"disabled\":false,\"href\":\"https://ant.design\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/udxAbMEhpwthVVcjLXik.png\",\"name\":\"TradeCode 91\",\"owner\":\"曲丽丽\",\"desc\":\"这是一段描述\",\"callNo\":180,\"status\":\"3\",\"updatedAt\":\"2021-12-01T10:17:31.353Z\",\"createdAt\":\"2021-12-01T10:17:31.353Z\",\"progress\":33},{\"key\":90,\"disabled\":true,\"href\":\"https://ant.design\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/eeHMaZBwmTvLdIwMfBpg.png\",\"name\":\"TradeCode 90\",\"owner\":\"曲丽丽\",\"desc\":\"这是一段描述\",\"callNo\":826,\"status\":\"3\",\"updatedAt\":\"2021-12-01T10:17:31.353Z\",\"createdAt\":\"2021-12-01T10:17:31.353Z\",\"progress\":75}],\"total\":100,\"success\":true,\"pageSize\":10,\"current\":1}"
	byteStr:=[]byte(string(str))
	var menus model.MenutsResp
	err := json.Unmarshal(byteStr,&menus)
	if err!=nil{
        fmt.Println(err)
    }
	
	fmt.Printf("getRule: %+v\n",&menus)
	c.JSON(http.StatusOK,menus)
}

func postRule(c *gin.Context) {
	recvJson := make(map[string]interface{}) //注意该结构接受的内容
	c.ShouldBind(&recvJson)
	fmt.Printf("postRule:%+v\n",&recvJson)

	c.JSON(http.StatusOK, gin.H{
		"status": "ok",
	})
}
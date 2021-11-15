/*
 * @Author: your name
 * @Date: 2021-11-08 10:39:41
 * @LastEditTime: 2021-11-14 17:40:10
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\app\shop\handler.go
 */

 package user

 import (
	"fmt"
	"github.com/gin-gonic/gin"
	"encoding/json"
	"net/http"

	model "https_gin/app/model"
	dbmysql "https_gin/app/mysql"
 )

func userLogin(c *gin.Context) {
	loginJson := model.AccountLogin{}
	c.BindJSON(&loginJson)
	fmt.Println("%v",&loginJson)
	
	if loginJson.Passwd == "admin" {
		c.JSON(http.StatusOK, gin.H{
			"status": "ok",
			"type": loginJson.Type,
			"currentAuthority": "admin",
		})
		fmt.Println("login success")
	} else {
		c.JSON(http.StatusOK, gin.H{
			"status": "error",
			"type": loginJson.Type,
			"currentAuthority": "guest",
		})
		fmt.Println("login fail")
	}
	
}

func currentUser(c *gin.Context) {
	recvJson := make(map[string]interface{}) //注意该结构接受的内容
	c.BindJSON(&recvJson)
	fmt.Println("%v",&recvJson)
	c.JSON(http.StatusOK, "{\"data\":{\"name\":\"Serati Ma\",\"avatar\":\"https://gw.alipayobjects.com/zos/antfincdn/XAosXuNZyF/BiazfanxmamNRoxxVxka.png\",\"userid\":\"00000001\",\"email\":\"antdesign@alipay.com\",\"signature\":\"海纳百川，有容乃大\",\"title\":\"交互专家\",\"group\":\"蚂蚁金服－某某某事业群－某某平台部－某某技术部－UED\",\"tags\":[{\"key\":\"0\",\"label\":\"很有想法的\"},{\"key\":\"1\",\"label\":\"专注设计\"},{\"key\":\"2\",\"label\":\"辣~\"},{\"key\":\"3\",\"label\":\"大长腿\"},{\"key\":\"4\",\"label\":\"川妹子\"},{\"key\":\"5\",\"label\":\"海纳百川\"}],\"notifyCount\":12,\"unreadCount\":11,\"country\":\"China\",\"access\":\"getAccess()\",\"geographic\":{\"province\":{\"label\":\"浙江省\",\"key\":\"330000\"},\"city\":{\"label\":\"杭州市\",\"key\":\"330100\"}},\"address\":\"西湖区工专路 77 号\",\"phone\":\"0752-268888888\"}}")
}

func userNotices(c *gin.Context) {
	recvJson := make(map[string]interface{}) //注意该结构接受的内容
	c.BindJSON(&recvJson)
	fmt.Println("%v",&recvJson)
	
	c.JSON(http.StatusOK,"{\"data\":[{\"id\":\"000000001\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/ThXAXghbEsBCCSDihZxY.png\",\"title\":\"你收到了 14 份新周报\",\"datetime\":\"2017-08-09\",\"type\":\"notification\"},{\"id\":\"000000002\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/OKJXDXrmkNshAMvwtvhu.png\",\"title\":\"你推荐的 曲妮妮 已通过第三轮面试\",\"datetime\":\"2017-08-08\",\"type\":\"notification\"},{\"id\":\"000000003\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/kISTdvpyTAhtGxpovNWd.png\",\"title\":\"这种模板可以区分多种通知类型\",\"datetime\":\"2017-08-07\",\"read\":true,\"type\":\"notification\"},{\"id\":\"000000004\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/GvqBnKhFgObvnSGkDsje.png\",\"title\":\"左侧图标用于区分不同的类型\",\"datetime\":\"2017-08-07\",\"type\":\"notification\"},{\"id\":\"000000005\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/ThXAXghbEsBCCSDihZxY.png\",\"title\":\"内容不要超过两行字，超出时自动截断\",\"datetime\":\"2017-08-07\",\"type\":\"notification\"},{\"id\":\"000000006\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/fcHMVNCjPOsbUGdEduuv.jpeg\",\"title\":\"曲丽丽 评论了你\",\"description\":\"描述信息描述信息描述信息\",\"datetime\":\"2017-08-07\",\"type\":\"message\",\"clickClose\":true},{\"id\":\"000000007\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/fcHMVNCjPOsbUGdEduuv.jpeg\",\"title\":\"朱偏右 回复了你\",\"description\":\"这种模板用于提醒谁与你发生了互动，左侧放『谁』的头像\",\"datetime\":\"2017-08-07\",\"type\":\"message\",\"clickClose\":true},{\"id\":\"000000008\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/fcHMVNCjPOsbUGdEduuv.jpeg\",\"title\":\"标题\",\"description\":\"这种模板用于提醒谁与你发生了互动，左侧放『谁』的头像\",\"datetime\":\"2017-08-07\",\"type\":\"message\",\"clickClose\":true},{\"id\":\"000000009\",\"title\":\"任务名称\",\"description\":\"任务需要在 2017-01-12 20:00 前启动\",\"extra\":\"未开始\",\"status \":\"todo \",\"type\":\"event\"},{\"id\":\"000000010\",\"title\":\"第三方紧急代码变更\",\"description\":\"冠霖提交于 2017-01-06，需在 2017-01-07 前完成代码变更任务\",\"extra\":\"马上到期\",\"status \":\"urgent \",\"type\":\"event\"},{\"id\":\"000000011\",\"title\":\"信息安全考试\",\"description\":\"指派竹尔于 2017-01-09 前完成更新并发布\",\"extra\":\"已耗时 8 天\",\"status \":\"doing \",\"type\":\"event\"},{\"id\":\"000000012\",\"title\":\"ABCD 版本发布\",\"description\":\"冠霖提交于 2017-01-06，需在 2017-01-07 前完成代码变更任务\",\"extra\":\"进行中\",\"status \":\"processing \",\"type\":\"event\"}]}")
	
}

func testdb(c *gin.Context) {
	var dbinfo = model.DBAuthInfo{"test","127.0.0.1","3306","gch","GCHgch_123456"};
	dbmysql.Connect(dbinfo);
	c.String(http.StatusOK, "testdb success\n")

}

func testjson(c *gin.Context) {
    buf, err := json.Marshal(model.AccountLogin{Name: "root",Passwd:"123456"})
    if err != nil {
        panic(err)
    }
    println(string(buf))
	fmt.Println(string(buf))
	c.String(http.StatusOK, string(buf))
}
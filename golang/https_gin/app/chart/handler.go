/*
 * @Author: your name
 * @Date: 2021-11-08 10:39:41
 * @LastEditTime: 2021-11-14 17:40:10
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\app\shop\handler.go
 */

 package chart

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

func getChartData(c *gin.Context) {
	str := "{\"data\":{\"visitData\":[{\"x\":\"2021-12-01\",\"y\":7},{\"x\":\"2021-12-02\",\"y\":5},{\"x\":\"2021-12-03\",\"y\":4},{\"x\":\"2021-12-04\",\"y\":2},{\"x\":\"2021-12-05\",\"y\":4},{\"x\":\"2021-12-06\",\"y\":7},{\"x\":\"2021-12-07\",\"y\":5},{\"x\":\"2021-12-08\",\"y\":6},{\"x\":\"2021-12-09\",\"y\":5},{\"x\":\"2021-12-10\",\"y\":9},{\"x\":\"2021-12-11\",\"y\":6},{\"x\":\"2021-12-12\",\"y\":3},{\"x\":\"2021-12-13\",\"y\":1},{\"x\":\"2021-12-14\",\"y\":5},{\"x\":\"2021-12-15\",\"y\":3},{\"x\":\"2021-12-16\",\"y\":6},{\"x\":\"2021-12-17\",\"y\":5}],\"visitData2\":[{\"x\":\"2021-12-01\",\"y\":1},{\"x\":\"2021-12-02\",\"y\":6},{\"x\":\"2021-12-03\",\"y\":4},{\"x\":\"2021-12-04\",\"y\":8},{\"x\":\"2021-12-05\",\"y\":3},{\"x\":\"2021-12-06\",\"y\":7},{\"x\":\"2021-12-07\",\"y\":2}],\"salesData\":[{\"x\":\"1月\",\"y\":749},{\"x\":\"2月\",\"y\":1177},{\"x\":\"3月\",\"y\":965},{\"x\":\"4月\",\"y\":514},{\"x\":\"5月\",\"y\":579},{\"x\":\"6月\",\"y\":1043},{\"x\":\"7月\",\"y\":496},{\"x\":\"8月\",\"y\":832},{\"x\":\"9月\",\"y\":852},{\"x\":\"10月\",\"y\":574},{\"x\":\"11月\",\"y\":300},{\"x\":\"12月\",\"y\":203}],\"searchData\":[{\"index\":1,\"keyword\":\"搜索关键词-0\",\"count\":799,\"range\":6,\"status\":1},{\"index\":2,\"keyword\":\"搜索关键词-1\",\"count\":697,\"range\":42,\"status\":0},{\"index\":3,\"keyword\":\"搜索关键词-2\",\"count\":630,\"range\":84,\"status\":1},{\"index\":4,\"keyword\":\"搜索关键词-3\",\"count\":754,\"range\":55,\"status\":1},{\"index\":5,\"keyword\":\"搜索关键词-4\",\"count\":425,\"range\":81,\"status\":0},{\"index\":6,\"keyword\":\"搜索关键词-5\",\"count\":18,\"range\":53,\"status\":0},{\"index\":7,\"keyword\":\"搜索关键词-6\",\"count\":471,\"range\":21,\"status\":0},{\"index\":8,\"keyword\":\"搜索关键词-7\",\"count\":326,\"range\":33,\"status\":0},{\"index\":9,\"keyword\":\"搜索关键词-8\",\"count\":803,\"range\":93,\"status\":0},{\"index\":10,\"keyword\":\"搜索关键词-9\",\"count\":316,\"range\":25,\"status\":0},{\"index\":11,\"keyword\":\"搜索关键词-10\",\"count\":737,\"range\":45,\"status\":1},{\"index\":12,\"keyword\":\"搜索关键词-11\",\"count\":578,\"range\":26,\"status\":0},{\"index\":13,\"keyword\":\"搜索关键词-12\",\"count\":332,\"range\":55,\"status\":0},{\"index\":14,\"keyword\":\"搜索关键词-13\",\"count\":727,\"range\":21,\"status\":0},{\"index\":15,\"keyword\":\"搜索关键词-14\",\"count\":243,\"range\":13,\"status\":1},{\"index\":16,\"keyword\":\"搜索关键词-15\",\"count\":582,\"range\":25,\"status\":0},{\"index\":17,\"keyword\":\"搜索关键词-16\",\"count\":379,\"range\":79,\"status\":0},{\"index\":18,\"keyword\":\"搜索关键词-17\",\"count\":967,\"range\":6,\"status\":1},{\"index\":19,\"keyword\":\"搜索关键词-18\",\"count\":27,\"range\":52,\"status\":1},{\"index\":20,\"keyword\":\"搜索关键词-19\",\"count\":679,\"range\":98,\"status\":0},{\"index\":21,\"keyword\":\"搜索关键词-20\",\"count\":986,\"range\":9,\"status\":0},{\"index\":22,\"keyword\":\"搜索关键词-21\",\"count\":349,\"range\":96,\"status\":1},{\"index\":23,\"keyword\":\"搜索关键词-22\",\"count\":602,\"range\":67,\"status\":1},{\"index\":24,\"keyword\":\"搜索关键词-23\",\"count\":107,\"range\":55,\"status\":1},{\"index\":25,\"keyword\":\"搜索关键词-24\",\"count\":153,\"range\":97,\"status\":0},{\"index\":26,\"keyword\":\"搜索关键词-25\",\"count\":442,\"range\":32,\"status\":1},{\"index\":27,\"keyword\":\"搜索关键词-26\",\"count\":215,\"range\":27,\"status\":1},{\"index\":28,\"keyword\":\"搜索关键词-27\",\"count\":482,\"range\":65,\"status\":1},{\"index\":29,\"keyword\":\"搜索关键词-28\",\"count\":367,\"range\":10,\"status\":1},{\"index\":30,\"keyword\":\"搜索关键词-29\",\"count\":409,\"range\":31,\"status\":0},{\"index\":31,\"keyword\":\"搜索关键词-30\",\"count\":792,\"range\":89,\"status\":1},{\"index\":32,\"keyword\":\"搜索关键词-31\",\"count\":705,\"range\":8,\"status\":0},{\"index\":33,\"keyword\":\"搜索关键词-32\",\"count\":935,\"range\":37,\"status\":1},{\"index\":34,\"keyword\":\"搜索关键词-33\",\"count\":968,\"range\":3,\"status\":0},{\"index\":35,\"keyword\":\"搜索关键词-34\",\"count\":929,\"range\":60,\"status\":0},{\"index\":36,\"keyword\":\"搜索关键词-35\",\"count\":365,\"range\":87,\"status\":0},{\"index\":37,\"keyword\":\"搜索关键词-36\",\"count\":627,\"range\":30,\"status\":1},{\"index\":38,\"keyword\":\"搜索关键词-37\",\"count\":922,\"range\":99,\"status\":0},{\"index\":39,\"keyword\":\"搜索关键词-38\",\"count\":831,\"range\":29,\"status\":0},{\"index\":40,\"keyword\":\"搜索关键词-39\",\"count\":390,\"range\":79,\"status\":0},{\"index\":41,\"keyword\":\"搜索关键词-40\",\"count\":883,\"range\":64,\"status\":0},{\"index\":42,\"keyword\":\"搜索关键词-41\",\"count\":11,\"range\":43,\"status\":1},{\"index\":43,\"keyword\":\"搜索关键词-42\",\"count\":679,\"range\":73,\"status\":1},{\"index\":44,\"keyword\":\"搜索关键词-43\",\"count\":395,\"range\":1,\"status\":0},{\"index\":45,\"keyword\":\"搜索关键词-44\",\"count\":178,\"range\":52,\"status\":0},{\"index\":46,\"keyword\":\"搜索关键词-45\",\"count\":790,\"range\":44,\"status\":0},{\"index\":47,\"keyword\":\"搜索关键词-46\",\"count\":232,\"range\":12,\"status\":0},{\"index\":48,\"keyword\":\"搜索关键词-47\",\"count\":280,\"range\":33,\"status\":1},{\"index\":49,\"keyword\":\"搜索关键词-48\",\"count\":316,\"range\":35,\"status\":0},{\"index\":50,\"keyword\":\"搜索关键词-49\",\"count\":953,\"range\":86,\"status\":1}],\"offlineData\":[{\"name\":\"Stores 0\",\"cvr\":0.2},{\"name\":\"Stores 1\",\"cvr\":0.7},{\"name\":\"Stores 2\",\"cvr\":0.8},{\"name\":\"Stores 3\",\"cvr\":0.8},{\"name\":\"Stores 4\",\"cvr\":0.3},{\"name\":\"Stores 5\",\"cvr\":0.1},{\"name\":\"Stores 6\",\"cvr\":0.7},{\"name\":\"Stores 7\",\"cvr\":0.6},{\"name\":\"Stores 8\",\"cvr\":0.5},{\"name\":\"Stores 9\",\"cvr\":0.5}],\"offlineChartData\":[{\"x\":1638364209058,\"y1\":71,\"y2\":55},{\"x\":1638366009058,\"y1\":59,\"y2\":11},{\"x\":1638367809058,\"y1\":30,\"y2\":74},{\"x\":1638369609058,\"y1\":96,\"y2\":38},{\"x\":1638371409058,\"y1\":61,\"y2\":51},{\"x\":1638373209058,\"y1\":19,\"y2\":58},{\"x\":1638375009058,\"y1\":55,\"y2\":59},{\"x\":1638376809058,\"y1\":75,\"y2\":17},{\"x\":1638378609058,\"y1\":91,\"y2\":37},{\"x\":1638380409058,\"y1\":85,\"y2\":69},{\"x\":1638382209058,\"y1\":21,\"y2\":14},{\"x\":1638384009058,\"y1\":106,\"y2\":64},{\"x\":1638385809058,\"y1\":35,\"y2\":103},{\"x\":1638387609058,\"y1\":17,\"y2\":37},{\"x\":1638389409058,\"y1\":59,\"y2\":94},{\"x\":1638391209058,\"y1\":81,\"y2\":53},{\"x\":1638393009058,\"y1\":30,\"y2\":66},{\"x\":1638394809058,\"y1\":12,\"y2\":12},{\"x\":1638396609058,\"y1\":103,\"y2\":53},{\"x\":1638398409058,\"y1\":36,\"y2\":52}],\"salesTypeData\":[{\"x\":\"家用电器\",\"y\":4544},{\"x\":\"食用酒水\",\"y\":3321},{\"x\":\"个护健康\",\"y\":3113},{\"x\":\"服饰箱包\",\"y\":2341},{\"x\":\"母婴产品\",\"y\":1231},{\"x\":\"其他\",\"y\":1231}],\"salesTypeDataOnline\":[{\"x\":\"家用电器\",\"y\":244},{\"x\":\"食用酒水\",\"y\":321},{\"x\":\"个护健康\",\"y\":311},{\"x\":\"服饰箱包\",\"y\":41},{\"x\":\"母婴产品\",\"y\":121},{\"x\":\"其他\",\"y\":111}],\"salesTypeDataOffline\":[{\"x\":\"家用电器\",\"y\":99},{\"x\":\"食用酒水\",\"y\":188},{\"x\":\"个护健康\",\"y\":344},{\"x\":\"服饰箱包\",\"y\":255},{\"x\":\"其他\",\"y\":65}],\"radarData\":[{\"name\":\"个人\",\"label\":\"引用\",\"value\":10},{\"name\":\"个人\",\"label\":\"口碑\",\"value\":8},{\"name\":\"个人\",\"label\":\"产量\",\"value\":4},{\"name\":\"个人\",\"label\":\"贡献\",\"value\":5},{\"name\":\"个人\",\"label\":\"热度\",\"value\":7},{\"name\":\"团队\",\"label\":\"引用\",\"value\":3},{\"name\":\"团队\",\"label\":\"口碑\",\"value\":9},{\"name\":\"团队\",\"label\":\"产量\",\"value\":6},{\"name\":\"团队\",\"label\":\"贡献\",\"value\":3},{\"name\":\"团队\",\"label\":\"热度\",\"value\":1},{\"name\":\"部门\",\"label\":\"引用\",\"value\":4},{\"name\":\"部门\",\"label\":\"口碑\",\"value\":1},{\"name\":\"部门\",\"label\":\"产量\",\"value\":6},{\"name\":\"部门\",\"label\":\"贡献\",\"value\":5},{\"name\":\"部门\",\"label\":\"热度\",\"value\":7}]}}"
	byteStr:=[]byte(string(str))
	var chart model.CharData
	err := json.Unmarshal(byteStr,&chart)
	if err!=nil{
        fmt.Println(err)
    }
	
	fmt.Printf("getChartData: %+v\n",&chart)
	c.JSON(http.StatusOK,chart)
}


func getActivities(c *gin.Context) {
	str := "{\"data\":[{\"id\":\"trend-1\",\"updatedAt\":\"2021-12-01T14:00:02.791Z\",\"user\":{\"name\":\"曲丽丽\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/BiazfanxmamNRoxxVxka.png\"},\"group\":{\"name\":\"高逼格设计天团\",\"link\":\"http://github.com/\"},\"project\":{\"name\":\"六月迭代\",\"link\":\"http://github.com/\"},\"template\":\"在 @{group} 新建项目 @{project}\"},{\"id\":\"trend-2\",\"updatedAt\":\"2021-12-01T14:00:02.791Z\",\"user\":{\"name\":\"付小小\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/cnrhVkzwxjPwAaCfPbdc.png\"},\"group\":{\"name\":\"高逼格设计天团\",\"link\":\"http://github.com/\"},\"project\":{\"name\":\"六月迭代\",\"link\":\"http://github.com/\"},\"template\":\"在 @{group} 新建项目 @{project}\"},{\"id\":\"trend-3\",\"updatedAt\":\"2021-12-01T14:00:02.791Z\",\"user\":{\"name\":\"林东东\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/gaOngJwsRYRaVAuXXcmB.png\"},\"group\":{\"name\":\"中二少女团\",\"link\":\"http://github.com/\"},\"project\":{\"name\":\"六月迭代\",\"link\":\"http://github.com/\"},\"template\":\"在 @{group} 新建项目 @{project}\"},{\"id\":\"trend-4\",\"updatedAt\":\"2021-12-01T14:00:02.791Z\",\"user\":{\"name\":\"周星星\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/WhxKECPNujWoWEFNdnJE.png\"},\"project\":{\"name\":\"5 月日常迭代\",\"link\":\"http://github.com/\"},\"template\":\"将 @{project} 更新至已发布状态\"},{\"id\":\"trend-5\",\"updatedAt\":\"2021-12-01T14:00:02.791Z\",\"user\":{\"name\":\"朱偏右\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/ubnKSIfAJTxIgXOKlciN.png\"},\"project\":{\"name\":\"工程效能\",\"link\":\"http://github.com/\"},\"comment\":{\"name\":\"留言\",\"link\":\"http://github.com/\"},\"template\":\"在 @{project} 发布了 @{comment}\"},{\"id\":\"trend-6\",\"updatedAt\":\"2021-12-01T14:00:02.791Z\",\"user\":{\"name\":\"乐哥\",\"avatar\":\"https://gw.alipayobjects.com/zos/rmsportal/jZUIxmJycoymBprLOUbT.png\"},\"group\":{\"name\":\"程序员日常\",\"link\":\"http://github.com/\"},\"project\":{\"name\":\"品牌迭代\",\"link\":\"http://github.com/\"},\"template\":\"在 @{group} 新建项目 @{project}\"}]}"
	byteStr:=[]byte(string(str))
	var activities model.Activities
	err := json.Unmarshal(byteStr,&activities)
	if err!=nil{
        fmt.Println(err)
    }
	
	fmt.Printf("getActivities: %+v\n",&activities)
	c.JSON(http.StatusOK,activities)
}

func getProNotices(c *gin.Context) {
	str := "{\"data\":[{\"id\":\"xxx1\",\"title\":\"Alipay\",\"logo\":\"https://gw.alipayobjects.com/zos/rmsportal/WdGqmHpayyMjiEhcKoVE.png\",\"description\":\"那是一种内在的东西，他们到达不了，也无法触及的\",\"updatedAt\":\"2021-12-01T14:03:50.617Z\",\"member\":\"科学搬砖组\",\"href\":\"\",\"memberLink\":\"\"},{\"id\":\"xxx2\",\"title\":\"Angular\",\"logo\":\"https://gw.alipayobjects.com/zos/rmsportal/zOsKZmFRdUtvpqCImOVY.png\",\"description\":\"希望是一个好东西，也许是最好的，好东西是不会消亡的\",\"updatedAt\":\"2017-07-24T00:00:00.000Z\",\"member\":\"全组都是吴彦祖\",\"href\":\"\",\"memberLink\":\"\"},{\"id\":\"xxx3\",\"title\":\"Ant Design\",\"logo\":\"https://gw.alipayobjects.com/zos/rmsportal/dURIMkkrRFpPgTuzkwnB.png\",\"description\":\"城镇中有那么多的酒馆，她却偏偏走进了我的酒馆\",\"updatedAt\":\"2021-12-01T14:03:50.617Z\",\"member\":\"中二少女团\",\"href\":\"\",\"memberLink\":\"\"},{\"id\":\"xxx4\",\"title\":\"Ant Design Pro\",\"logo\":\"https://gw.alipayobjects.com/zos/rmsportal/sfjbOqnsXXJgNCjCzDBL.png\",\"description\":\"那时候我只会想自己想要什么，从不想自己拥有什么\",\"updatedAt\":\"2017-07-23T00:00:00.000Z\",\"member\":\"程序员日常\",\"href\":\"\",\"memberLink\":\"\"},{\"id\":\"xxx5\",\"title\":\"Bootstrap\",\"logo\":\"https://gw.alipayobjects.com/zos/rmsportal/siCrBXXhmvTQGWPNLBow.png\",\"description\":\"凛冬将至\",\"updatedAt\":\"2017-07-23T00:00:00.000Z\",\"member\":\"高逼格设计天团\",\"href\":\"\",\"memberLink\":\"\"},{\"id\":\"xxx6\",\"title\":\"React\",\"logo\":\"https://gw.alipayobjects.com/zos/rmsportal/kZzEzemZyKLKFsojXItE.png\",\"description\":\"生命就像一盒巧克力，结果往往出人意料\",\"updatedAt\":\"2017-07-23T00:00:00.000Z\",\"member\":\"骗你来学计算机\",\"href\":\"\",\"memberLink\":\"\"}]}"
	byteStr:=[]byte(string(str))
	var notices model.ProNotices
	err := json.Unmarshal(byteStr,&notices)
	if err!=nil{
        fmt.Println(err)
    }
	
	fmt.Printf("getProNotices: %+v\n",&notices)
	c.JSON(http.StatusOK,notices)
}
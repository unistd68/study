package model

import (
    "time"
)

type AccountLogin struct {
    Name   string `json:"name"`
    Passwd string `json:"password"`
    AutoLogin bool `json:"autoLogin"`
    Type string `json:"type"`
}

type LoginResp struct {
    Status   string `json:"status"`
    Type string `json:"type"`
    CurrentAuthority string `json:"currentAuthority"`
}

type Property struct {
    Key   string `json:"key"`
    Label string `json:"label"`
}

type TagItem struct {
    Properties   []Property `json:"properties"`
}

type City struct {
    Properties   Property `json:"properties"`
}

type Province struct {
    Properties   Property `json:"properties"`
}

type Geographic struct {
    Province  Province `json:"province"`
    City City `json:"city"`
}


type CurrentUser struct {
    Name   string `json:"name"`
    Avatar string `json:"avatar"`
    UserID string `json:"userid"`
    Email string `json:"email"`
    Signature string `json:"signature"`
    Title string `json:"title"`
    Group string `json:"group"`
    Tags []Property `json:"tags"`
    NotifyCount int `json:"notifyCount"`
    UnReadCount int `json:"unreadCount"`
    Country string `json:"country"`
    Access string `json:"access"`
    Geographic Geographic `json:"geographic"`
    City string `json:"city"`
    Address string `json:"address"`
    Phone string `json:"phone"`
}

type CurrentUserResp struct {
    Data CurrentUser `json:"data"`
}

type NoticeIconItem struct {
    ID   string `json:"id"`
    Extra string `json:"extra"`
    Key string `json:"key"`
    Read bool `json:"read"`
    Avatar string `json:"avatar"`
    Title string `json:"title"`
    Status string `json:"status"`
    Datetime string `json:"datetime"`
    Description string `json:"description"`
    Type string `json:"type"`
    CickClose bool `json:"clickClose"`
}

type NoticeResp struct {
    Data []NoticeIconItem `json:"data"`
}

type OutLoginResp struct {
    Data    EmptyStruct `json:"data"`
    Success   bool `json:"success"`
}

type RulesResp struct {
    Rules    []RuleListItem `json:"data"`
    Total   int `json:"total"`
    Success   bool `json:"success"`
    PageSize   int `json:"pageSize"`
    Current   int `json:"current"`
}

type RuleListItem struct {
    key  int  `json:"key"`
    disabled  bool  `json:"disabled"`
    href  string  `json:"href"`
    avatar  string  `json:"avatar"`
    name  string  `json:"name"`
    owner  string  `json:"owner"`
    desc  string  `json:"desc"`
    callNo  int  `json:"callNo"`
    status  int  `json:"status"`
    updatedAt  string  `json:"updatedAt"`
    createdAt  string  `json:"createdAt"`
    progress  int  `json:"progress"`
}

type MenutItem struct{
    Key       int       `json:"key"`
    Disabled  bool      `json:"disabled"`
    Href      string    `json:"href"`
    Avatar    string    `json:"avatar"`
    Name      string    `json:"name"`
    Owner     string    `json:"owner"`
    Desc      string    `json:"desc"`
    CallNo    int       `json:"callNo"`
    Status    string    `json:"status"`
    UpdatedAt time.Time `json:"updatedAt"`
    CreatedAt time.Time `json:"createdAt"`
    Progress  int       `json:"progress"`
}

type MenutsResp struct {
	Data     []MenutItem `json:"data"`
	Total    int  `json:"total"`
	Success  bool `json:"success"`
	PageSize int  `json:"pageSize"`
	Current  int  `json:"current"`
}

type EmptyStruct struct {}

type DBAuthInfo struct {
    DBName  string
    DBHost  string
    DBPort  string
	DBUser  string
	DBPwd   string
}

type DBMsg struct {
    Id     int
    Msg   string
}

type Video struct {
    Videos   []VideoMsg `json:"data"`
}

type VideoMsg struct {
    Title   string `json:"title"`
    Type    string `json:"type"`
    Url     string `json:"url"`
}

type Audio struct {
    Audios   []AudioMsg `json:"data"`
}

type AudioMsg struct {
    Name     string `json:"name"`
    Artist   string `json:"artist"`
    Url   string `json:"url"`
    Lrc   string `json:"lrc"`
    Cover   string `json:"cover"`
}

type AudioRecords struct {
    DBAudios   []DBAudios `json:"data"`
}

type DBAudios struct {
    Title     string `json:"title"`
    Ip   string `json:"ip"`
    Bucket   string `json:"bucket"`
    Filepath   string `json:"filepath"`
}

type VideoResp struct {
    Addrs   []VideoAddr `json:"data"`
}

type VideoAddr struct {
    Title   string `json:"title"`
    Url   string `json:"url"`
}

type WorkChartData struct {
	Data struct {
		VisitData []struct {
			X string `json:"x"`
			Y int    `json:"y"`
		} `json:"visitData"`
		VisitData2 []struct {
			X string `json:"x"`
			Y int    `json:"y"`
		} `json:"visitData2"`
		SalesData []struct {
			X string `json:"x"`
			Y int    `json:"y"`
		} `json:"salesData"`
		SearchData []struct {
			Index   int    `json:"index"`
			Keyword string `json:"keyword"`
			Count   int    `json:"count"`
			Range   int    `json:"range"`
			Status  int    `json:"status"`
		} `json:"searchData"`
		OfflineData []struct {
			Name string  `json:"name"`
			Cvr  float64 `json:"cvr"`
		} `json:"offlineData"`
		OfflineChartData []struct {
			X  int64 `json:"x"`
			Y1 int   `json:"y1"`
			Y2 int   `json:"y2"`
		} `json:"offlineChartData"`
		SalesTypeData []struct {
			X string `json:"x"`
			Y int    `json:"y"`
		} `json:"salesTypeData"`
		SalesTypeDataOnline []struct {
			X string `json:"x"`
			Y int    `json:"y"`
		} `json:"salesTypeDataOnline"`
		SalesTypeDataOffline []struct {
			X string `json:"x"`
			Y int    `json:"y"`
		} `json:"salesTypeDataOffline"`
		RadarData []struct {
			Name  string `json:"name"`
			Label string `json:"label"`
			Value int    `json:"value"`
		} `json:"radarData"`
	} `json:"data"`
}

type AnalysisChartData struct {
	Data struct {
		VisitData []struct {
			X string `json:"x"`
			Y int    `json:"y"`
		} `json:"visitData"`
		VisitData2 []struct {
			X string `json:"x"`
			Y int    `json:"y"`
		} `json:"visitData2"`
		SalesData []struct {
			X string `json:"x"`
			Y int    `json:"y"`
		} `json:"salesData"`
		SearchData []struct {
			Index   int    `json:"index"`
			Keyword string `json:"keyword"`
			Count   int    `json:"count"`
			Range   int    `json:"range"`
			Status  int    `json:"status"`
		} `json:"searchData"`
		OfflineData []struct {
			Name string  `json:"name"`
			Cvr  float64 `json:"cvr"`
		} `json:"offlineData"`
		OfflineChartData []struct {
			X  int64 `json:"x"`
			Y1 int   `json:"y1"`
			Y2 int   `json:"y2"`
		} `json:"offlineChartData"`
		SalesTypeData []struct {
			X string `json:"x"`
			Y int    `json:"y"`
		} `json:"salesTypeData"`
		SalesTypeDataOnline []struct {
			X string `json:"x"`
			Y int    `json:"y"`
		} `json:"salesTypeDataOnline"`
		SalesTypeDataOffline []struct {
			X string `json:"x"`
			Y int    `json:"y"`
		} `json:"salesTypeDataOffline"`
		RadarData []struct {
			Name  string `json:"name"`
			Label string `json:"label"`
			Value int    `json:"value"`
		} `json:"radarData"`
	} `json:"data"`
}

type Activities struct {
	Data []struct {
		ID        string    `json:"id"`
		UpdatedAt time.Time `json:"updatedAt"`
		User      struct {
			Name   string `json:"name"`
			Avatar string `json:"avatar"`
		} `json:"user"`
		Group struct {
			Name string `json:"name"`
			Link string `json:"link"`
		} `json:"group,omitempty"`
		Project struct {
			Name string `json:"name"`
			Link string `json:"link"`
		} `json:"project"`
		Template string `json:"template"`
		Comment  struct {
			Name string `json:"name"`
			Link string `json:"link"`
		} `json:"comment,omitempty"`
	} `json:"data"`
}


type ProNotices struct {
	Data []struct {
		ID          string    `json:"id"`
		Title       string    `json:"title"`
		Logo        string    `json:"logo"`
		Description string    `json:"description"`
		UpdatedAt   time.Time `json:"updatedAt"`
		Member      string    `json:"member"`
		Href        string    `json:"href"`
		MemberLink  string    `json:"memberLink"`
	} `json:"data"`
}
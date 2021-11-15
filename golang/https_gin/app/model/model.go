package model

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
    Read string `json:"read"`
    Avatar string `json:"avatar"`
    Title string `json:"title"`
    Status string `json:"status"`
    Datetime string `json:"datetime"`
    Description string `json:"description"`
    Type string `json:"type"`
}

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
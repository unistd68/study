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



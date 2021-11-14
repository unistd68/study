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
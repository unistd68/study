package model

type User struct {
    Name   string `json:"name"`
    Passwd string `json:"password"`
    AutoLogin bool `json:"autoLogin"`
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
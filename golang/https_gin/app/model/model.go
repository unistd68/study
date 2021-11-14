package model

type User struct {
    Name   string `json:"name"`
    Passwd string `json:"password"`
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
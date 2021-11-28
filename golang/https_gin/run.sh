#!/bin/bash
#项目路径
APP_NAME=main.go
#配置文件路径
#APP_CONF=

#使用说明，用来提示输入参数
usage() {
	echo "Usage: run.sh {start|stop|restart|status}"
	exit 1
}

#检查程序是否正在运行
is_running() {
	pid=`ps -ef|grep $APP_NAME|grep -v grep|awk '{print $2}'`
	#如果不存在则返回1，存在则返回0
	if [ -z "${pid}" ];
	then
		return 1
	else
		return 0
	fi
}

#启动
start() {
	is_running
	if [ $? -eq 0 ];
	then
		echo "${APP_NAME} is already running, pid=${pid}"
	else
		sh update.sh
		(nohup go run ${APP_NAME} &) > nohup.out 2>&1 &
	fi
}

#停止
stop() {
	is_running
	if [ $? -eq 0 ];
	then
		kill -9 $pid
	else
		echo "${APP_NAME} is not running"
	fi
}

#查看运行状态
status() {
	is_running
	if [ $? -eq 0 ];
	then
		echo "${APP_NAME} is running, pid is ${pid}"
	else
		echo "${APP_NAME} is not running"
	fi
}

#重启
restart() {
	stop
	sleep 5
	start
}

#根据输入的参数，选择对应的执行方法，不输入则执行使用说明
case "$1" in
	start)
		start
		;;
	stop)
		stop
		;;
	status)
		status
		;;
	restart)
		restart
		;;
	*)
		usage
		;;
esac

CC = g++
CC_FLAGS = -W -Wall -Werror -I./  -I/home/xtcgch/Env/redis/redis-6.2.5/deps -L/home/xtcgch/Env/redis/redis-6.2.5/deps/hiredis/build_dir -lhiredis -std=c++11
EXEC = my_service
OBJS = main.o httpserver.o httpresponse.o useredis.o configparse.o

CC_FLAGS += -std=c++11

$(EXEC): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@

main.o: main.cpp
	$(CC) $(CC_FLAGS) -c -o $@ main.cpp
	
httpserver.o: HttpServer.cpp HttpServer.hpp
	$(CC) $(CC_FLAGS) -c -o $@ HttpServer.cpp
	
httpresponse.o: HttpResponse.cpp HttpResponse.hpp
	$(CC) $(CC_FLAGS) -c -o $@ HttpResponse.cpp

useredis.o: UseRedis.cpp UseRedis.h
	$(CC) $(CC_FLAGS) -c -o $@ UseRedis.cpp

configparse.o: ConfigParse.cpp ConfigParse.h
	$(CC) $(CC_FLAGS) -c -o $@ ConfigParse.cpp

all: $(EXEC)

clean:
	rm -rf $(OBJS) $(EXEC)

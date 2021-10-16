CC = g++
CC_FLAGS = -W -Wall  -I./ -I../../includes -I../../tools  -I../ -I/usr/local/include/readerwriterqueue -I/home/xtcgch/Env/redis/redis-6.2.5/deps -L/home/xtcgch/Env/redis/redis-6.2.5/deps/hiredis/build_dir -lhiredis 
EXEC = test_sm4
OBJS = test_sm4.o sm4.o 

CC_FLAGS += -std=c++11 -fpermissive

$(EXEC): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@

sm4.o: sm4.cpp sm4.h tools.h
	$(CC) $(CC_FLAGS) -c -o $@ sm4.cpp

test_sm4.o: test_sm4.cpp sm4.o
	$(CC) $(CC_FLAGS) -c -o $@ test_sm4.cpp sm4.o sm4.cpp
	


all: $(EXEC)

clean:
	rm -rf $(OBJS) $(EXEC)

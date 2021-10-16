CC = g++
CC_FLAGS = -W -Wall -Werror -I./ -I../../includes -I../../tools  -I../
EXEC = test_sm4
OBJS = test_sm4.o sm4.o 

CC_FLAGS += -std=c++11

$(EXEC): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@

test_sm4.o: test_sm4.cpp
	$(CC) $(CC_FLAGS) -c -o $@ test_sm4.cpp
	
sm4.o: sm4.cpp sm4.h
	$(CC) $(CC_FLAGS) -c -o $@ sm4.cpp

all: $(EXEC)

clean:
	rm -rf $(OBJS) $(EXEC)

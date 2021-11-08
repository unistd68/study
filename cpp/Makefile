CC = g++
CC_FLAGS = -fpermissive -g -std=c++11
EXEC = test
OBJS = main.o dp.o md5.o sm3.o sm4.o tools.o string_test.o

CC_FLAGS += -fpermissive -g
CC_FLAGS += -luuid -L/usr/lib64

LIBS   := -luuid
INCLUDE:= -I.

$(EXEC): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@

main.o:  main.cpp 
	$(CC) $(CC_FLAGS)  -o $@ -c main.cpp

dp.o: dp.cpp 
	$(CC) $(CC_FLAGS)  -o $@ -c  dp.cpp 

md5.o: md5.cpp 
	$(CC) $(CC_FLAGS)  -o $@ -c  md5.cpp 

sm3.o: sm3.cpp  
	$(CC) $(CC_FLAGS)  -o $@ -c  sm3.cpp 

sm4.o: sm4.cpp 
	$(CC) $(CC_FLAGS)  -o $@ -c  sm4.cpp 

tools.o: tools.cpp  
	$(CC) $(CC_FLAGS)  -o $@ -c  tools.cpp 

string_test.o: string_test.cpp   
	$(CC) $(CC_FLAGS)  -o $@ -c  string_test.cpp 

all: $(EXEC)

clean:
	rm -rf $(OBJS) $(EXEC)


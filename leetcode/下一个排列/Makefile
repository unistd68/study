CC = g++
CC_FLAGS = -fpermissive -g -std=c++11
EXEC = test
OBJS = main.o algorithm.o tools.o

CC_FLAGS += -fpermissive -g
CC_FLAGS += -luuid -L/usr/lib64

LIBS   := -luuid
INCLUDE:= -I.

$(EXEC): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@

main.o:  main.cpp 
	$(CC) $(CC_FLAGS)  -o $@ -c main.cpp

algorithm.o: algorithm.cpp 
	$(CC) $(CC_FLAGS)  -o $@ -c  algorithm.cpp 

tools.o: tools.cpp  
	$(CC) $(CC_FLAGS)  -o $@ -c  tools.cpp 

all: $(EXEC)

clean:
	rm -rf $(OBJS) $(EXEC)


TARGE:= run
OBJS:=main.o func.o extra.o linklist.o
CC:=gcc
CFLAGS:= -c -o

$(TARGE):$(OBJS)
	$(CC) $(OBJS) -o $(TARGE)
%.o:%.c
	$(CC) $< $(CFLAGS) $@
clean:
	rm $(OBJS) $(TARGE)

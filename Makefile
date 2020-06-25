PROG = diary
CC = g++
CPPFLAGS = -O0 -std=c++11 -g 
OBJS = main.o message.o date.o time.o diary.o app.o utilities.o

$(PROG) : $(OBJS)
	$(CC)  $(OBJS)  -o $(PROG)

main.o :
	$(CC) $(CPPFLAGS) -c src/main.cpp

message.o : include/message.h
	$(CC) $(CPPFLAGS) -c src/message.cpp

date.o :  include/date.h
	$(CC) $(CPPFLAGS) -c src/date.cpp

time.o :  include/time.h
	$(CC) $(CPPFLAGS) -c src/time.cpp

diary.o :  include/diary.h
	$(CC) $(CPPFLAGS) -c src/diary.cpp

app.o :  include/app.h
	$(CC) $(CPPFLAGS) -c src/app.cpp

utilities.o :  include/utilities.h
	$(CC) $(CPPFLAGS) -c src/utilities.cpp

clean:
	rm -f *.o

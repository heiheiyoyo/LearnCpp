CC=g++
CFLAGS=


Main.exe: TextQuery.o QueryResult.o
	$(CC) $(CFLAGS) -o main.exe QueryResult.o TextQuery.o main.cpp

TextQuery.o:
	$(CC) $(CFLAGS) -c -o TextQuery.o TextQuery.cpp

QueryResult.o:
	$(CC) $(CFLAGS) -c -o QueryResult.o QueryResult.cpp


.PHONY:clean
clean:
	@rm TextQuery.o QueryResult.o Main.exe
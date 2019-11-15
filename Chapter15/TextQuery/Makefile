CC=g++
CFLAGS=


Main.exe: TextQuery.o QueryResult.o Querys.o
	$(CC) $(CFLAGS) -o main.exe QueryResult.o TextQuery.o Querys.o main.cpp

WordQueryTest.exe:
	$(CC) $(CFLAGS) -o WordQueryTest.exe QueryResult.o TextQuery.o Querys.o WordQueryTest.cpp

TextQuery.o:
	$(CC) $(CFLAGS) -c -o TextQuery.o TextQuery.cpp

QueryResult.o:
	$(CC) $(CFLAGS) -c -o QueryResult.o QueryResult.cpp

Querys.o:
	$(CC) $(CFLAGS) -c -o Querys.o Querys.cpp


.PHONY:clean
clean:
	@rm TextQuery.o QueryResult.o Main.exe WordQueryTest.exe Querys.o
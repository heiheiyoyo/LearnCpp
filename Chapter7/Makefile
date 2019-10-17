CC=g++
CFLAGS=-std=c++11

main.o: Sales_data.o
	$(CC) $(CFLAGS) main.cpp Sales_data.o -o main.o

Sales_data.o:
	$(CC) $(CFLAGS) -c Sales_data.cpp -o Sales_data.o

.PHONY:clean
clean:
	@rm Sales_data.o main.o

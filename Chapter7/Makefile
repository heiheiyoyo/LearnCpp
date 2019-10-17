CC=g++
CFLAGS=-std=c++11

usingSales_data.o: Sales_data.o
	$(CC) $(CFLAGS) usingSales_data.cpp Sales_data.o -o usingSales_data.o

Sales_data.o:
	$(CC) $(CFLAGS) -c Sales_data.cpp -o Sales_data.o

.PHONY:clean
clean:
	@rm Sales_data.o usingSales_data.o

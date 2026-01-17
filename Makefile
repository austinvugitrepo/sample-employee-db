CC ?= clang
CXX ?= clang++
SOURCECC = write.c
SOURCECXX = se-db.cpp
PREFIX ?= /usr/local
BINARY = $(PREFIX)/bin

default:
	$(CC) -o sql.o -c $(SOURCECC) -Wall -pthread -I /usr/local/include
	$(CXX) -o main.o -c $(SOURCECXX) -Wall -pthread
link:
	$(CXX) -o sedp.exe main.o sql.o -pthread -lsqlite3 -L /usr/local/lib

install:
	mkdir -p $(BINARY)
	cp sedp.exe $(BINARY)/sedp.exe
	chmod 755 $(BINARY)/sedp.exe

uninstall:
	rm main.o sql.o sedp.exe
	rm -f $(BINARY)/sedp.exe

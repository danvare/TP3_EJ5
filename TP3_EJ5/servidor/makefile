programa: tcpServer.o
	gcc -o programa tcpServer.o -lpthread
	chmod 755 ./programa

demonio.o: tcpServer.c header.h
	gcc -c tcpServer.c
clean:
	rm -f *.o

programa: tcpClient.o
	gcc -o programa tcpClient.o -lpthread
	chmod 755 ./programa
client.o: tcpClient.c header.h
	gcc -c tcpClient.c
clean:
	rm -f *.o

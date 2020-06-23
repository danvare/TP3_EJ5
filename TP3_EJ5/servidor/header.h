#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

struct Estructura{
    char itemId[150];
    char articulo[150];
    char producto[150];
    char marca[150];
};

typedef struct Estructura Estructura;

void helpMe();

#endif // HEADER_H_INCLUDED

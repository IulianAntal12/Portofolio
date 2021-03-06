#include "mainwindow.h"
#include <QApplication>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include "connection.h"
#include <iostream>
/* codul de eroare returnat de anumite apeluri */
extern int errno;
/* portul de conectare la server*/
int port;
int Connection::client_sd=0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int sd;			// descriptorul de socket
    struct sockaddr_in server;	// structura folosita pentru conectare
    /* exista toate argumentele in linia de comanda? */
    if (argc != 3)
      {
        printf ("Sintaxa: %s <adresa_server> <port>\n", argv[0]);
        return -1;
      }
    /* stabilim portul */
    port = atoi (argv[2]);
    /* cream socketul */
    if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
      {
        perror ("Eroare la socket().\n");
        return errno;
      }
    /* umplem structura folosita pentru realizarea conexiunii cu serverul */
    /* familia socket-ului */
    server.sin_family = AF_INET;
    /* adresa IP a serverului */
    server.sin_addr.s_addr = inet_addr(argv[1]);
    /* portul de conectare */
    server.sin_port = htons (port);
    if (::connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1)
       {
         perror ("[client]Eroare la connect().\n");
         return errno;
       }
    Connection con;
    con.receive_descriptor(sd);

    return a.exec();
}

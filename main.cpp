// Server side C/C++ program to demonstrate Socket programming
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <WinSock2.h>
#include <Windows.h>
//#include <stdlib.h>
#include <sstream>
#include <string.h>

#define SCK_VERSION 0x0202

using namespace std;
int main(){
   SOCKET sock;
   SOCKADDR_IN address;

   long ok;
   char MESSAGE[200];

   WSAData WSD;
   WORD DllVersion;
   DllVersion = MAKEWORD(2,1);
   ok=WSAStartup(DllVersion, &WSD);

   while(true){
         sock =socket(AF_INET,SOCK_STREAM,NULL);

   address.sin_addr.s_addr = inet_addr("192.168.0.103    ");
   address.sin_family = AF_INET;
   address.sin_port = htons(10102);

   connect(sock,(SOCKADDR*)&address,sizeof(address));

        string msg;
        cout<<"Enter message --> ";
        cin>>msg ;
        const char* s =msg.c_str();
         ok = send(sock,s,1024,NULL);

         ok=recv(sock,MESSAGE,sizeof(MESSAGE),NULL);
         string reply;
         reply=MESSAGE;
        cout<<"Server says --> "<<reply<<endl;
    }
}

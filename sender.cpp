#include <iostream>
#include <string>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "constants.h"

void sender(){
    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    // set multicast address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, constants::MULTICAST_ADDR.c_str(), &addr.sin_addr);
    addr.sin_port = htons(constants::PORT);

    std::string msg = "Hello, multicast!";
    sendto(sock, msg.c_str(), msg.length(), 0, (struct sockaddr*)(&addr), sizeof(addr));
    std::cout << "Sent message: " << msg << std::endl;
}


int main(){
    sender();
    return 0;
}

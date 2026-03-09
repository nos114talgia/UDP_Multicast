#include <iostream>
#include <string>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "constants.h"
void receiver(){
    int sock;
    struct sockaddr_in addr;
    char buffer[constants::MAX_MSG_LEN + 1];

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    // set socket to reuse address
    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // set multicast address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(constants::PORT);
    // bind
    bind(sock, (struct sockaddr*)(&addr), sizeof(addr));

    // join multicast group
    struct ip_mreq mreq;
    memset(&mreq, 0, sizeof(mreq));
    inet_pton(AF_INET, constants::MULTICAST_ADDR.c_str(), &mreq.imr_multiaddr);
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);

    setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));

    // receive
    int len = recvfrom(sock, buffer, constants::MAX_MSG_LEN, 0, nullptr, nullptr);
    buffer[len] = '\0';
    std::cout << "Received message: " << buffer << std::endl;
}

int main(){
    receiver();
    return 0;
}

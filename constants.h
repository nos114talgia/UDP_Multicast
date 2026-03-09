#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace constants{
    constexpr int PORT = 8888;
    constexpr int MAX_MSG_LEN = 1024;
    inline const std::string MULTICAST_ADDR = "239.0.0.1";
}

#endif
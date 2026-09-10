#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <memory>
#include <cstring>
class Socket {
public:
    explicit Socket() noexcept;
    void start() noexcept;
    ~Socket() noexcept;
private:
    int status;
    struct addrinfo hint;
    struct addrinfo *servInfo;
};



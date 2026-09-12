#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <memory>
#include <cstring>
#include <print>
class Socket
{
public:
    explicit Socket() noexcept(true);
    void start();
    ~Socket() noexcept;

private:
    int status;
    int socketFileDescriptor;
    struct addrinfo hint;
    struct addrinfo *servInfo;
};

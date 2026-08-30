#pragma once
#include <cstdint>
#include <cstddef>
#include <string>
#include <memory>
#include <netb.h>
#include <sys/socket.h>
#include "own_memory_allocator_ready/memory.h"


class Server {
public:
    explicit Server(int listeningPort) noexcept;

    ~Server();

    Server(const Server &) = delete;
    Server &operator =(const Server &) = delete;

    void start();

private:
    int listeningPort;
    int listeningSocketFd;
    std::addrinfo* addressList;
    void setupListeningSocket();
};

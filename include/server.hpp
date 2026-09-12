#pragma once
#include <cstdint>
#include <cstddef>
#include <string>
#include <memory>
#include <netdb.h>
#include <sys/socket.h>
#include "socket.hpp"
#include "own_memory_allocator_ready/memory.h"
#define RUNNING true

class Server {
public:
    explicit Server() noexcept (true);
    void start();
    ~Server();
    Server(const Server &) = delete;
    Server &operator =(const Server &) = delete;


private:
    Socket socket;
};

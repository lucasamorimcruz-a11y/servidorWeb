
#include "../include/socket.hpp"

Socket::Socket() noexcept(true)
{
    this->status = 0;
    this->socketFileDescriptor = -1;
    this->servInfo = nullptr;
    std::memset(&this->hint, 0, sizeof(this->hint));
    this->hint.ai_family = AF_UNSPEC;
    this->hint.ai_socktype = SOCK_STREAM;
    this->hint.ai_flags = AI_PASSIVE;
}
void Socket::start()
{
    this->status = getaddrinfo(nullptr, "3490", &this->hint, &this->servInfo);
    if ((this->status) != 0)
    {
        std::println(stderr, "erro: {}", gai_strerror(this->status));
        return;
    }
    int _socketFileDescriptor = socket(this->servInfo->ai_family, this->servInfo->ai_socktype, this->servInfo->ai_protocol);
    if (_socketFileDescriptor == -1)
    {
        std::println(stderr, "erro ao criar socket");
        return;
    }
    this->socketFileDescriptor = _socketFileDescriptor;
    int yes = 1;
    setsockopt(this->socketFileDescriptor, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
    if ((bind(socketFileDescriptor, this->servInfo->ai_addr, this->servInfo->ai_addrlen)) == -1)
    {
        std::println(stderr, "erro no bind");
        close(this->socketFileDescriptor);
        this->socketFileDescriptor = -1;
        freeaddrinfo(this->servInfo);
        return;
    }
    freeaddrinfo(this->servInfo);
    this->servInfo = nullptr;
    if (listen(this->socketFileDescriptor, 10) == -1)
    {
        std::println(stderr, "erro no listen");
        close(this->socketFileDescriptor);
        this->socketFileDescriptor = -1;
        freeaddrinfo(this->servInfo);
        return;
    }
}
int Socket::acceptConnection()
{
    sockaddr_storage theirAddress;
    socklen_t addressSize;
    addressSize = sizeof(theirAddress);
    int clientFileDescriptor = accept(this->socketFileDescriptor, (sockaddr *)&theirAddress, &addressSize);
    return clientFileDescriptor;
}
Socket::~Socket() noexcept(true)
{
    if (this->socketFileDescriptor != -1)
    {
        close(this->socketFileDescriptor);
    }
    if (this->servInfo != nullptr)
    {
        freeaddrinfo(this->servInfo);
    }
}
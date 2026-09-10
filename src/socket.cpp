
#include "../include/socket.hpp"

Socket::Socket() noexcept {
    std::memset(&this->hint, 0, sizeof(this->hint));
    this->hint.ai_family = AF_UNSPEC;
    this->hint.ai_socktype = SOCK_STREAM;
    this->hint.ai_flags = AI_PASSIVE;
    if ((this->status = getaddrinfo(NULL, "3490", &this->hint, &this->servInfo))!= 0) {
        std::fprintf(std::stderr, "erro : %s\n", gai_strerror(this->status));
    }
}
Socket::~Socket() noexcept {
    freeaddrinfo(this->servInfo);
}
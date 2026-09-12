#include "include/server.hpp"
Server::Server()
{
}
void Server::start()
{
    this->socket.start();
    while (RUNNING)
    {
        int client = this->socket.acceptConnection();
        if (client == -1)
        {
            std::println(stderr, "Erro ao aceitar conexão do cliente");
            continue;
        }
        char buffer[4096];
        ssize_t bytesReceived = recv(client, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived == -1)
        {
            std::println(stderr, "recv: {}", std::strerror(errno));
            close(client);
            continue;
        }
        if (bytesReceived == 0)
        {
            close(client);
            continue;
        }
        buffer[bytesReceived] = '\0';
        std::println("Recebido!");
        std::println("{}", buffer);
        close(client);
    }
}
void Server::shutdown(){
    
}
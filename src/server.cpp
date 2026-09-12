#include "include/server.hpp"
Server::Server ()
{
   
}
void Server::start(){
    this->socket.start();
    while (RUNNING){
        int client = this->socket.acceptConnection();
        if (client == -1)
        {
            std::println(stderr, "Erro ao aceitar conexão do cliente");
            continue;
        }
        

    }   
}


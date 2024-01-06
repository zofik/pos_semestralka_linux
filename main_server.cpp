//
// Created by zofia on 6. 1. 2024.
//
#include <iostream>
#include "server.h"

int main() {
    std::cout << "--- Krok 1 - Vytvorenie serveru" << std::endl;

    int port = 55586;
    Server server(port);

    if (!server.startServer()) {
        return -1;
    }

    return 0;
}

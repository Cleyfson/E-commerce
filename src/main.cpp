#include "celular.hpp"
#include "util.hpp"
#include "venda.hpp"
#include <iostream>

int main()
{
    Venda venda;
    std::string command;
    while (getline(std::cin, command) && !command.empty()) {
        if (command == "insert") {
            Insert(venda);
        } else if (command == "sell") {
            Sell(venda);
        } else if (command == "add") {
            Add(venda);
        } else if (command == "del") {
            Del(venda);
        } else if (command == "discount") {
            Discount(venda);
        }
        command = "";
    }
    venda.imprimeEstoque();
    return 0;
}
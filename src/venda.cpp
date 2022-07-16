#include "venda.hpp"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>

void Venda::adicionaCelular(const Celular& celular)
{
    m_celulares.push_back(celular);
}

void Venda::ordena()
{
    m_celulares.sort();
}

void Venda::recarregaEstoque(int cod, int qtd)
{
    for (auto it = m_celulares.begin(); it != m_celulares.end(); it++) {
        if (it->cod == cod) {
            it->quantidade += qtd;
            break;
        }
    }
}

void Venda::efetuaVenda(int cod, int qtd)
{
    for (auto it = m_celulares.begin(); it != m_celulares.end(); it++) {
        if (it->cod == cod && it->quantidade >= qtd) {
            it->quantidade -= qtd;
            break;
        }
    }
}

void Venda::aplicaDesconto(const std::string& fabricante, float desconto)
{
    for (auto it = m_celulares.begin(); it != m_celulares.end(); it++) {
        if (it->fabricante == fabricante) {
            it->valor_unitario -= (it->valor_unitario * desconto) / 100;
        }
    }
}

void Venda::removeModelo(int cod)
{
    for (auto it = m_celulares.begin(); it != m_celulares.end(); it++) {
        if (it->cod == cod) {
            m_celulares.erase(it);
            break;
        }
    }
}

void Venda::imprimeEstoque() const
{
    for (auto it = m_celulares.begin(); it != m_celulares.end(); it++) {

        if (it->quantidade > 0) {
            std::cout << it->fabricante << " ";
            std::cout << it->modelo << ", ";
            std::cout << it->armazenamento << "GB"
                      << ", ";
            std::cout << it->memoria << "GB RAM"
                      << ", ";
            std::cout << (int)(10000 * (it->peso)) << " gramas"
                      << ", ";

            for (int i = 0; i < (int)it->cor.length(); i++) {
                if (i == 0) {
                    std::cout << (char)toupper(it->cor.at(i));
                } else {
                    std::cout << it->cor.at(i);
                }
            }
            std::cout << ", ";

            if (it->quantidade == 1) {
                std::cout << it->quantidade << " "
                          << "restante"
                          << ", ";

            } else {

                std::cout << it->quantidade << " "
                          << "restantes"
                          << ", ";
            }
            std::cout << "R$"
                      << " " << std::fixed << std::setprecision(2) << it->valor_unitario << std::endl;
        }
    }
}
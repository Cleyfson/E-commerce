#include "celular.hpp"

int Celular::codigo = 0;

Celular::Celular(std::string modelo,
    std::string fabricante,
    int armazenamento,
    int memoria,
    double peso,
    std::string cor,
    int qtd,
    float valor)
{
    this->modelo = modelo;
    this->fabricante = fabricante;
    this->armazenamento = armazenamento;
    this->memoria = memoria;
    this->peso = peso;
    this->cor = cor;
    this->quantidade = qtd;
    this->valor_unitario = valor;
    this->cod = ++codigo;
}

bool Celular::operator<(const Celular& other) const
{

    if (this->fabricante == other.fabricante) {
        if (this->modelo < other.modelo) {
            return true;
        } else {
            return false;
        }
    } else if (this->fabricante < other.fabricante) {
        return true;
    } else {
        return false;
    }
}
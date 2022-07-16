#ifndef CELULAR_H
#define CELULAR_H

#include <string>

class Celular {
public:
    std::string modelo;
    std::string fabricante;
    std::string cor;
    int armazenamento;
    int quantidade;
    int memoria;
    int cod;
    float valor_unitario;
    double peso;
    Celular(std::string modelo,
        std::string fabricante,
        int armazenamento,
        int memoria,
        double peso,
        std::string cor,
        int qtd,
        float valor);

    bool operator<(const Celular& other) const;

public:
private:
    static int codigo;
};

#endif
#ifndef SISTEMAGESTAO_H
#define SISTEMAGESTAO_H

#include "Astronauta.h"
#include "Voo.h"
#include <map>

class SistemaGestao {
public:
    std::map<std::string, Astronauta> astronautas;
    std::map<int, Voo> voos;

    void cadastrarAstronauta(const std::string& cpf, const std::string& nome, int idade);
    void cadastrarVoo(int codigo);
    void adicionarAstronautaEmVoo(const std::string& cpf, int codigoVoo);
    void removerAstronautaDeVoo(const std::string& cpf, int codigoVoo);
    void lancarVoo(int codigoVoo);
    void explodirVoo(int codigoVoo);
    void finalizarVoo(int codigoVoo, bool sucesso);
    void listarVoos() const;
    void listarAstronautasMortos() const;
};

#endif // SISTEMAGESTAO_H

#include "SistemaGestao.h"
#include <iostream>

void SistemaGestao::cadastrarAstronauta(const std::string& cpf, const std::string& nome, int idade) {
    astronautas[cpf] = Astronauta(cpf, nome, idade);
}

void SistemaGestao::cadastrarVoo(int codigo) {
    voos[codigo] = Voo(codigo);
}

void SistemaGestao::adicionarAstronautaEmVoo(const std::string& cpf, int codigoVoo) {
    if (astronautas.find(cpf) != astronautas.end() && voos.find(codigoVoo) != voos.end()) {
        voos[codigoVoo].adicionarAstronauta(&astronautas[cpf]);
    }
}

void SistemaGestao::removerAstronautaDeVoo(const std::string& cpf, int codigoVoo) {
    if (astronautas.find(cpf) != astronautas.end() && voos.find(codigoVoo) != voos.end()) {
        voos[codigoVoo].removerAstronauta(&astronautas[cpf]);
    }
}

void SistemaGestao::lancarVoo(int codigoVoo) {
    if (voos.find(codigoVoo) != voos.end()) {
        voos[codigoVoo].lancarVoo();
    }
}

void SistemaGestao::explodirVoo(int codigoVoo) {
    if (voos.find(codigoVoo) != voos.end()) {
        voos[codigoVoo].explodirVoo();
    }
}

void SistemaGestao::finalizarVoo(int codigoVoo, bool sucesso) {
    if (voos.find(codigoVoo) != voos.end()) {
        voos[codigoVoo].finalizarVoo(sucesso);
    }
}

void SistemaGestao::listarVoos() const {
    for (const auto& [codigo, voo] : voos) {
        std::cout << "Voo " << codigo << " - ";
        switch (voo.status) {
            case Voo::PLANEJADO: std::cout << "Planejado"; break;
            case Voo::EM_CURSO: std::cout << "Em curso"; break;
            case Voo::FINALIZADO: std::cout << "Finalizado"; break;
            case Voo::EXPLODIDO: std::cout << "Explodido"; break;
        }
        std::cout << "\nAstronautas:\n";
        for (const auto* astronauta : voo.passageiros) {
            std::cout << astronauta->cpf << " - " << astronauta->nome << "\n";
        }
    }
}

void SistemaGestao::listarAstronautasMortos() const {
    for (const auto& [cpf, astronauta] : astronautas) {
        if (astronauta.morto) {
            std::cout << "CPF: " << astronauta.cpf << ", Nome: " << astronauta.nome << "\n";
            std::cout << "Voos: ";
            for (int codigoVoo : astronauta.voos) {
                std::cout << codigoVoo << " ";
            }
            std::cout << "\n";
        }
    }
}

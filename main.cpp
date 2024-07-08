#include "SistemaGestao.h"
#include <iostream>

int main() {
    SistemaGestao sistema;

    // Cadastrar astronautas
    sistema.cadastrarAstronauta("12345678901", "Neil Armstrong", 39);
    sistema.cadastrarAstronauta("98765432101", "Buzz Aldrin", 41);

    // Cadastrar voos
    sistema.cadastrarVoo(1);
    sistema.cadastrarVoo(2);

    // Adicionar astronautas ao voo 1
    sistema.adicionarAstronautaEmVoo("12345678901", 1);
    sistema.adicionarAstronautaEmVoo("98765432101", 1);

    // Lançar o voo 1
    sistema.lancarVoo(1);

    // Explodir o voo 1
    sistema.explodirVoo(1);

    // Listar todos os voos
    std::cout << "Listagem de Voos:\n";
    sistema.listarVoos();

    // Listar todos os astronautas mortos
    std::cout << "\nAstronautas Mortos:\n";
    sistema.listarAstronautasMortos();

    return 0;
}

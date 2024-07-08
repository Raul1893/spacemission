#include "Voo.h"

Voo::Voo(int codigo) : codigo(codigo), status(PLANEJADO) {}

void Voo::adicionarAstronauta(Astronauta* astronauta) {
    if (status == PLANEJADO && astronauta->disponivel) {
        passageiros.push_back(astronauta);
        astronauta->disponivel = false;
        astronauta->voos.push_back(codigo);
    }
}

void Voo::removerAstronauta(Astronauta* astronauta) {
    if (status == PLANEJADO) {
        passageiros.erase(std::remove(passageiros.begin(), passageiros.end(), astronauta), passageiros.end());
        astronauta->disponivel = true;
    }
}

void Voo::lancarVoo() {
    if (status == PLANEJADO && !passageiros.empty()) {
        status = EM_CURSO;
    }
}

void Voo::explodirVoo() {
    if (status == EM_CURSO) {
        status = EXPLODIDO;
        for (auto* astronauta : passageiros) {
            astronauta->morto = true;
        }
    }
}

void Voo::finalizarVoo(bool sucesso) {
    if (status == EM_CURSO) {
        status = FINALIZADO;
        if (sucesso) {
            for (auto* astronauta : passageiros) {
                astronauta->disponivel = true;
            }
        } else {
            for (auto* astronauta : passageiros) {
                astronauta->morto = true;
            }
        }
    }
}

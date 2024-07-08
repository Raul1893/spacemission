#ifndef VOO_H
#define VOO_H

#include "Astronauta.h"
#include <vector>

class Voo {
public:
    enum Status { PLANEJADO, EM_CURSO, FINALIZADO, EXPLODIDO };

    int codigo;
    Status status;
    std::vector<Astronauta*> passageiros;

    Voo(int codigo);
    void adicionarAstronauta(Astronauta* astronauta);
    void removerAstronauta(Astronauta* astronauta);
    void lancarVoo();
    void explodirVoo();
    void finalizarVoo(bool sucesso);
};

#endif // VOO_H

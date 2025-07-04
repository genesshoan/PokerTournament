//#include "Jugador.h"
#include "Partida.h"

int main() {
    Partida p;
    CargarPartida(p, 0);
    MostrarPartida(p);
    CargarPartida(p, 1);
    MostrarPartida(p);
}

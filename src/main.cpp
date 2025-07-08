#include "PartidasJugadas.h"

int main() {
    PartidasJugadas lista;
    
    Crear(lista);

    printf("Esta vacia?: %s\n", EsVacia(lista) ? "Si" : "No");

    Partida p1 = {1, 12345678, 87654321, 12345678};
    Partida p2 = {2, 87654321, 12345678, 87654321};
    Partida p3 = {3, 55555555, 44444444, 55555555};

    InsBack(lista, p1);
    InsBack(lista, p2);
    InsBack(lista, p3);

    printf("\nLista completa:\n");
    ListarPartidasJugadas(lista);

    printf("\nCantidad de partidas: %d\n", Largo(lista));

    printf("\nPrimera partida:\n");
    MostrarPartida(Primero(lista));

    printf("\nPartida en posicion 1 (k = 1):\n");
    MostrarPartida(K_esimo(lista, 1));

    printf("\nUltimo numero de partida: %d\n", DevolverUltimoNrP(lista));

    printf("\nLista luego de aplicar Resto:\n");
    Resto(lista);
    ListarPartidasJugadas(lista);

    printf("\nPartidas del jugador 12345678:\n");
    ListarPartidasPorJugador(lista, 12345678);
}

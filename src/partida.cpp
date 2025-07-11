#include "Partida.h"

long int GetCedulaJugador1 (Partida p){
    return p.Cedula_Jugador1;
}

long int GetCedulaJugador2 (Partida p) {
    return p.Cedula_Jugador2;
}

int GetNumeroPartida(Partida p) {
    return p.Nro_Partida;
}

long int GetCedulaVencedor (Partida p) {
    return p.Cedula_Vencedor;
}

void CargarPartida (Partida &p, long int c1, long int c2, int numero) {
    p.Nro_Partida = numero;
    p.Cedula_Jugador1 = c1;
    p.Cedula_Jugador2 = c2;

    boolean cedulaValida = FALSE;
    while (!cedulaValida) {
        printf("\tIngrese la Cedula del Jugador Ganador: ");
        scanf("%ld", &p.Cedula_Vencedor);
        if (GetCedulaJugador1(p) == GetCedulaVencedor(p) || GetCedulaJugador2(p) == GetCedulaVencedor(p))
            cedulaValida = TRUE;
        else
            printf("[ ERROR ]: Cedula del ganador invalida. Debe ser la cedula de uno de los jugadores.\n");
    }
}

void MostrarPartida (Partida p) {
    printf("\tNumero de partida: %d\n", GetNumeroPartida(p));
    printf("\tCedula del jugador 1: %ld\n", GetCedulaJugador1(p));
    printf("\tCedula del jugador 2: %ld\n", GetCedulaJugador2(p));
    printf("\tCedula del ganador: %ld\n", GetCedulaVencedor(p));
}
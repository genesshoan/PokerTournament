#ifndef _PARTIDA_H
#define _PARTIDA_H

#include <stdio.h>
#include "boolean.h"

typedef struct {
    int Nro_Partida;
    long int Cedula_Jugador1;
    long int Cedula_Jugador2;
    long int Cedula_Vencedor;
}Partida;

/**
 * @brief Obtiene la cedula del jugador 1 de una partida.
 * @param p Partida de la cual se desea obtener la cedula del jugador 1.
 * @return Cedula del jugador 1.
 */
long int GetCedulaJugador1 (Partida p);

/**
 * @brief Obtiene la cedula del jugador 2 de una partida.
 * @param p Partida de la cual se desea obtener la cedula del jugador 2.
 * @return Cedula del jugador 2.
 */
long int GetCedulaJugador2 (Partida p);

/**
 * @brief Obtiene el numero de la partida.
 * @param p Partida de la cual se desea obtener el numero.
 * @return Numero de la partida.
 */
int GetNumeroPartida(Partida p);

/**
 * @brief Obtiene el cedula del jugador ganador de una partida.
 * @param p Partida de la cual se desea obtener el cedula del jugador ganador.
 * @return Cedula del jugador ganador.
 */
long int GetCedulaVencedor (Partida p);

/**
 * @brief Carga una partida desde un archivo.
 * @param d Partida a cargar.
 * @param numero Numero de la partida a cargar.
 */
void CargarPartida (Partida &p, int numero);

/**
 * @brief Muestra los detalles de una partida.
 * @param p Partida a mostrar.
 */
void MostrarPartida (Partida p);

#endif
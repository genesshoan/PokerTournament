#ifndef _SISTEMA_
#define _SISTEMA_

#include "Torneo.h"
#include "PartidasJugadas.h"
#include "Jugadores.h"

/**
 * @fn ResgistrarJugador
 * @brief Registra un jugador en el sistema.
 * @param j Jugadores del torneo.
 * @param cedula Cédula del jugador a registrar.
 */
void ResgistrarJugador(Jugadores &j, long int cedula);

/**
 * @fn ListarTodosLosJugadores
 * @brief Lista todos los jugadores del torneo.
 * @param jug Jugadores del torneo.
 */
void ListarTodosLosJugadores (Jugadores jug);

/**
 * @fn ListarDatosPorJugador
 * @brief Lista los datos del jugador y las partidas jugadas por el mismo.
 * @param j Jugadores del torneo.
 * @param p Partidas jugadas en el torneo.
 * @details Esta función muestra los datos del jugador, junto con las partidas en las que han participado.
 */
void ListarDatosPorJugador (Jugadores j, PartidasJugadas p, long int cedula);

/**
 * @fn RegistrarPartida
 * @brief Registra una partida jugada por los jugadores en el torneo.
 * @param j Jugadores del torneo.
 * @param p Partidas jugadas en el torneo.
 * @param t Torneo en el que se registran las partidas.
 * @details Esta función permite registrar una nueva partida, actualizando el diccionario de jugadores y la secuencia de partidas jugadas.
 */
void RegistrarPartida (Jugadores &j, PartidasJugadas &p, Torneo &t, long int c1, long int c2);

/**
 * @fn ListarTodasLasPartidas
 * @brief Lista todas las partidas jugadas en el torneo.   
 * @param p Partidas jugadas en el torneo.
 */
void ListarTodasLasPartidas (PartidasJugadas p);

/**
 * @fn CantidadJugadoresPorFecha
 * @brief Muestra la cantidad de jugadores nacidos antes, durante y después de una fecha específica.
 * @param j Jugadores del torneo.
 * @details Esta función solicita una fecha y muestra la cantidad de jugadores nacidos antes, durante y después de esa fecha.
 */
void CantidadJugadoresPorFecha (Jugadores j);

void MismaSubdivision(Torneo t, Jugadores j, long int c1, long int c2);

void MostrarTorneoCompleto(Torneo t, Jugadores j);

#endif
#ifndef _PARTIDAS_JUGADAS_
#define _PARTIDAS_JUGADAS_

#include "Partida.h"

typedef struct nodoP {
	Partida info;
	nodoP * sig;
} NodoP;

typedef struct {
	NodoP * prim;
	NodoP * ult;
} PartidasJugadas;

/**
 * @fn Crear
 * @brief Inicializa la lista de partidas jugadas como vacía.
 * @param p La lista de partidas jugadas a inicializar.
 * @post La lista de partidas jugadas queda vacía.
 * @note Esta función debe ser llamada antes de usar la lista.
 */
void Crear (PartidasJugadas &p);

/**
 * @fn EsVacia
 * @brief Verifica si la lista de partidas jugadas está vacía.
 * @param p La lista de partidas jugadas a verificar.
 * @return TRUE si la lista está vacía, FALSE en otro caso.
 */
boolean EsVacia (PartidasJugadas p);

/**
 * @fn InsFront
 * @brief Inserta una partida al frente de la lista de partidas jugadas.
 * @param p La lista de partidas jugadas.
 * @param part La partida a insertar.
 * @post La partida se agrega al inicio de la lista.
 */
void InsFront (PartidasJugadas &p, Partida part);

/**
 * @fn Primero
 * @brief Obtiene la primera partida de la lista de partidas jugadas.
 * @param p La lista de partidas jugadas.
 * @return La primera partida de la lista.
 * @pre La lista no debe estar vacía.
 */
Partida Primero (PartidasJugadas p);

/**
 * @fn Resto
 * @brief Elimina la primera partida de la lista de partidas jugadas.
 * @param p La lista de partidas jugadas.
 * @post La primera partida es eliminada de la lista.
 * @pre La lista no debe estar vacía.
 */
void Resto (PartidasJugadas &p);

/**
 * @fn Largo
 * @brief Obtiene la cantidad de partidas jugadas en la lista.
 * @param p La lista de partidas jugadas.
 * @return El número de partidas en la lista.
 */
int Largo (PartidasJugadas p);

/**
 * @fn K_esimo
 * @brief Obtiene la k-ésima partida de la lista de partidas jugadas.
 * @param p La lista de partidas jugadas.
 * @param k El índice de la partida a obtener (0 es la primera).
 * @return La k-ésima partida de la lista.
 * @pre 0 <= k < Largo(p).
 */
Partida K_esimo (PartidasJugadas p, int k);

/**
 * @fn InsBack
 * @brief Inserta una partida al final de la lista de partidas jugadas.
 * @param p La lista de partidas jugadas.
 * @param part La partida a insertar.
 * @post La partida se agrega al final de la lista.
 */
void InsBack (PartidasJugadas &p, Partida part);

/**
 * @fn ListarPartidasJugadas
 * @brief Muestra todas las partidas jugadas en la lista.
 * @param p La lista de partidas jugadas.
 */
void ListarPartidasJugadas (PartidasJugadas p);

/**
 * @fn ListarPartidasPorJugador
 * @brief Muestra todas las partidas jugadas por un jugador específico.
 * @param p La lista de partidas jugadas.
 * @param cedula La cédula del jugador cuyas partidas se desean listar.
 */
void ListarPartidasPorJugador (PartidasJugadas p, long int cedula);

/**
 * @fn DevolverUltimoNrP
 * @brief Devuelve el número de la última partida jugada.
 * @param p La lista de partidas jugadas.
 * @return El número de la última partida jugada.
 * @pre La secuencia no debe estar vacía.
 */
int DevolverUltimoNrP (PartidasJugadas p);


#endif
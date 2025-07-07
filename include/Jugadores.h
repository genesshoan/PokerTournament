#ifndef _JUGADORES_H_
#define _JUGADORES_H_

#include "Jugador.h"

const int B = 10; // Número de jugadores
typedef struct nodoJ {
	Jugador info;
	nodoJ * sig;
} NodoJ;
typedef NodoJ * Lista;
typedef Lista Jugadores[B];

void CrearLista (Lista &l);

boolean PerteneceLista (Lista l, long int cedula);

void InsFront (Lista &l, Jugador j);

void ModificarLista(Lista &l, Jugador j);

void EliminarNodo(Lista &l, long int cedula);

void MostrarLista (Lista l);

void CantJugadoresNacidosLista (Lista l, Fecha f, int &antes, int &durante, int &despues);

int h(long int cedula);

/**
 * @fn Make
 * @brief Inicializa el Hash de jugadores como vacío.
 */
void Make (Jugadores &j);

/**
 * @fn Member
 * @brief Dada una cedula, determina si existe un jugador en el sistema.
 * @param cedula La cédula del jugador.
 * @return TRUE si el jugador existe, FALSE en otro caso.
 */
boolean Member (Jugadores j, long int cedula);

/**
 * @fn Insert
 * @brief Inserta un jugador en el sistema.
 * @param j La lista de jugadores.
 * @param jug El jugador a insertar.
 * @pre El jugador no debe existir en el sistema.
 * @post El jugador se agrega al sistema.
 */
void Insert (Jugadores &j, Jugador jug);

/**
 * @fn Find
 * @brief Busca un jugador por su cédula.
 * @param j La lista de jugadores.
 * @param cedula La cédula del jugador a buscar.
 * @return El jugador encontrado.
 * @pre El jugador debe existir en el sistema.
 */
Jugador Find (Jugadores j, long int cedula);

/**
 * @fn Modify
 * @brief Modifica los datos de un jugador.
 * @param j La lista de jugadores.
 * @param jug El jugador con los datos modificados.
 * @pre El jugador debe existir en el sistema.
 * @post Los datos del jugador se actualizan en el sistema.
 */
void Modify (Jugadores &j, Jugador jug);

/**
 * @fn Delete
 * @brief Elimina un jugador del sistema.
 * @param j La lista de jugadores.
 * @param cedula La cédula del jugador a eliminar.  
 * @pre El jugador debe existir en el sistema.
 * @post El jugador ya no existe en el sistema.
 */
void Delete (Jugadores &j, long int cedula);

/**
 * @fn ListarJugadores
 * @brief Lista todos los jugadores del sistema.
 * @param j La lista de jugadores.
 * @post Muestra los datos de todos los jugadores en el sistema.
 */
void ListarJugadores (Jugadores j);

/**
 * @fn CantJugadoresNacidos
 * @brief Cuenta la cantidad de jugadores nacidos antes, durante y después de una fecha dada.
 * @param j La lista de jugadores.
 * @param f La fecha de referencia.
 * @param antes Referencia para almacenar la cantidad de jugadores nacidos antes de la fecha.
 * @param durante Referencia para almacenar la cantidad de jugadores nacidos en la fecha.
 * @param despues Referencia para almacenar la cantidad de jugadores nacidos después de la fecha.
 */
void CantJugadoresNacidos (Jugadores j, Fecha f, int &antes, int &durante, int &despues);



#endif
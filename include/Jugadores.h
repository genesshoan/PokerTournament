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

/**
 * @fn CrearLista
 * @brief Crea una lista de jugadores vacía.
 * @param l Lista a inicializar.
 */
void CrearLista (Lista &l);

/**
 * @fn PerteneceLista
 * @brief Verifica si un jugador con la cédula dada pertenece a la lista.
 * @param l Lista de jugadores.
 * @param cedula Cédula del jugador a buscar.
 * @return TRUE si el jugador pertenece a la lista, FALSE en caso contrario.
 */
boolean PerteneceLista (Lista l, long int cedula);

/**
 * @fn MayorLista
 * @brief Encuentra el mayor número de jugador en la lista.
 * @param l Lista de jugadores.
 * @param mayor Referencia para almacenar el mayor número de jugador encontrado.
 */
void MayorLista(Lista l, int &mayor);

/**
 * @fn InsFront
 * @brief Inserta un jugador al inicio de la lista.
 * @param l Lista de jugadores.
 * @param j Jugador a insertar.
 */
void InsFront (Lista &l, Jugador j);

/**
 * @fn ObtenerLista
 * @brief Obtiene un jugador de la lista por su cédula.
 * @param l Lista de jugadores.
 * @param cedula Cédula del jugador a buscar.
 * @pre El jugador debe existir en la lista.
 * @return El jugador encontrado.
 */
Jugador ObtenerLista (Lista l, long int cedula);

/**
 * @fn MostrarLista
 * @brief Modifica los datos de un jugador en la lista.
 * @param l Lista de jugadores.
 * @param cedula Cédula del jugador a modificar.
 */
void ModificarLista(Lista &l, Jugador j);

/**
 * @fn EliminarNodo
 * @brief Elimina un jugador de la lista por su cédula.
 * @param l Lista de jugadores.
 * @param cedula Cédula del jugador a eliminar.
 */
void EliminarNodo(Lista &l, long int cedula);

/**
 * @fn MostrarLista
 * @brief  Muestra toda la lista de jugadores.
 * @param l Lista de jugadores.
 */
void MostrarLista (Lista l);

/**
 * @fn CantJugadoresNacidosLista
 * @brief Cuenta la cantidad de jugadores nacidos antes, durante y después de una fecha específica
 * @param l Lista de jugadores.
 * @param f Fecha de referencia.
 * @param antes Referencia para almacenar la cantidad de jugadores nacidos antes de la fecha.
 * @param durante Referencia para almacenar la cantidad de jugadores nacidos en la fecha.
 * @param despues Referencia para almacenar la cantidad de jugadores nacidos después de la fecha.
 */
void CantJugadoresNacidosLista (Lista l, Fecha f, int &antes, int &durante, int &despues);

/**
 * @fn MayorGanadasLista
 * @brief Encuentra el jugador con la mayor cantidad de partidas ganadas en la lista.
 * @param l Lista de jugadores.
 * @param maxGanadas Referencia para almacenar la mayor cantidad de partidas ganadas.
 */
void MayorGanadasLista(Lista l, int maxGanadas);

/**
 * @fn MostrarGanadoresLista
 * @brief Muestra los jugadores con la mayor cantidad de partidas ganadas en la lista.
 * @param l Lista de jugadores.
 * @param maxGanadas La mayor cantidad de partidas ganadas.
 */
void MostrarGanadoresLista (Lista l, int maxGanadas);

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

/**
 * @fn HayJugadores
 * @brief Verifica si hay jugadores en el sistema.
 * @param j La lista de jugadores.
 * @return TRUE si hay al menos un jugador, FALSE en caso contrario.
 */
boolean HayJugadores (Jugadores j);

/**
 * @fn NumeroSiguiente
 * @brief Obtiene el siguiente número de jugador disponible.
 * @param j La lista de jugadores.
 * @return El siguiente número de jugador disponible.
 * @details Recorre todas las listas de jugadores y encuentra el mayor número de jugador.
 */
int NumeroSiguiente(Jugadores j);

/**
 * @fn ObtenerMayorCantidadGanadas
 * @brief Obtiene la mayor cantidad de partidas ganadas por un jugador en el sistema.
 * @param j La lista de jugadores.
 * @return La mayor cantidad de partidas ganadas por un jugador.
 */
int ObtenerMayorCantidadGanadas (Jugadores j);

/**
 * @fn MostrarGanadores
 * @brief Muestra los jugadores con la mayor cantidad de partidas ganadas.
 * @param j La lista de jugadores.
 * @details Recorre todas las listas de jugadores y muestra aquellos que tienen la mayor cantidad
 */
void MostrarGanadores(Jugadores j, int maxGanadas);



#endif
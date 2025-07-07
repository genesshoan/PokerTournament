#ifndef _TORNEO_H_
#define _TORNEO_H_

#include "boolean.h"

const int N = 10;

typedef int Torneo[N][N];

/**
 * @fn InicializarVisitados
 * @brief Inicializa el arreglo de visitados a FALSE.
 * @param visitados El arreglo de visitados a inicializar.
 * @note Se asume que el tamaño del arreglo es N.
 */
void InicializarVisitados (boolean visitados []);

/**
 * @fn Crear
 * @brief Inicializa el torneo como vacío.
 * @param t El torneo a inicializar.
 */
void Crear (Torneo &t);

/**
 * @fn PerteneceVertice
 * @brief Verifica si un vértice pertenece al torneo.
 * @param t El torneo.
 * @param v El vértice a verificar.
 * @return TRUE si el vértice pertenece, FALSE en otro caso.
 */
boolean PerteneceVertice (Torneo t, int v);

/**
 * @fn PerteneceArista
 * @brief Verifica si una arista pertenece al torneo.
 * @param t El torneo.
 * @param u Un extremo de la arista.
 * @param v El otro extremo de la arista.
 * @return TRUE si la arista pertenece, FALSE en otro caso.
 */
boolean PerteneceArista (Torneo t, int u, int v);

// void InsertarVertice (Torneo &t, int v);

/**
 * @fn InsertarArista
 * @brief Inserta una arista en el torneo.
 * @param t El torneo.
 * @param v La arista a insertar.
 */
void InsertarArista (Torneo &t, int u, int v);

/**
 * @fn GradoVertice
 * @brief Calcula el grado de un vértice en el torneo.
 * @param t El torneo.
 * @param v El vértice cuyo grado se desea calcular.
 * @return El grado del vértice.
 */
int GradoVertice (Torneo t, int v);

/**
 * @fn MismaComponenteConexa
 * @brief Verifica si dos jugadores pertenecen a la misma componente conexa.
 * @param t El torneo.
 * @param c1 La cédula del primer jugador.
 * @param c2 La cédula del segundo jugador.
 * @return TRUE si pertenecen a la misma componente conexa, FALSE en otro caso.
 */
boolean MismaComponenteConexa (Torneo t, int v1, int v2);

/**
 * @fn TorneoTerminado
 * @brief Verifica si el torneo ha terminado.
 * @param t El torneo.
 * @return TRUE si el torneo ha terminado, FALSE en otro caso.
 */
boolean TorneoTerminado (Torneo t);


#endif
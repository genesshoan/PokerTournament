#ifndef _JUGADOR_H
#define _JUGADOR_H

#include "string.h"
#include "fecha.h"

typedef struct {
    long int Cedula;
    Fecha Fecha_Nacimiento;
    int Nro_Jugador;
    string Nombre;
    string Apellido;
    string Departamento;
    int Cant_Partidas_Disputadas;
    int Cant_Partidas_Ganadas;
} Jugador;

/**
 * @fn GetCedulaJugador
 * @brief Dvuelve la cedula del jugador.
 * @param j El jugador del cual se desea obtener la cedula.
 * @return La cedula del jugador.
 */
long int GetCedulaJugador (Jugador j);

/**
 * @fn GetFechaNaciemiento
 * @brief Devuelve la fecha de nacimiento del jugador.
 * @param j El jugador del cual se desea obtener la fecha de nacimiento.
 * @return La fecha de nacimiento del jugador.
 */
Fecha GetFechaNacimiento (Jugador j);

/**
 * @fn GetNumeroJugador
 * @brief Devuelve el numero del jugador.
 * @param j El jugador del cual se desea obtener el numero.
 * @return El numero del jugador.
 */
int GetNumeroJugador (Jugador j);

/**
 * @fn GetNombre
 * @brief Devuelve el nombre del jugador.
 * @param j El jugador del cual se desea obtener el nombre.
 * @param nombre Referencia a una cadena donde se almacenara el nombre del jugador.
 */
void GetNombre (Jugador j, string &nombre);

/**
 * @fn GetApellido
 * @brief Devuelve el apellido del jugador.
 * @param j El jugador del cual se desea obtener el apellido.
 * @param apellido Referencia a una cadena donde se almacenara el apellido del jugador.
 */
void GetApellido (Jugador j, string &apellido);

/**
 * @fn GetDepartamento
 * @brief Devuelve el departamento del jugador.
 * @param j El jugador del cual se desea obtener el departamento.
 * @param dept Referencia a una cadena donde se almacenara el departamento del jugador.
 */
void GetDepartamento (Jugador j, string &dept);

/**
 * @fn GetPartidasDisputadas
 * @brief Devuelve la cantidad de partidas disputadas por el jugador.
 * @param j El jugador del cual se desea obtener la cantidad de partidas disputadas.
 * @return La cantidad de partidas disputadas por el jugador.
 */
int GetPartidasDisputadas (Jugador j);

/**
 * @fn GetPartidasGanadas
 * @brief Devuelve la cantidad de partidas ganadas por el jugador.
 * @param j El jugador del cual se desea obtener la cantidad de partidas ganadas.
 * @return La cantidad de partidas ganadas por el jugador.
 */
int GetPartidasGanadas (Jugador j);

/**
 * @fn SetCedulaJugador
 * @brief Permite cargar datos del jugador y asigna el número dado.
 * @param j El jugador al cual se le desea cargar.
 * @param cedula La cedula a establecer.
 */
void CargarJugador (Jugador &j, long int cedula, int numero);

/**
 * @fn MostrarJugador
 * @brief Muestra los datos del jugador.
 * @param j El jugador cuyos datos se desean mostrar.
 */
void MostrarJugador (Jugador j); 

/**
 * @fn IncrementarPartidasDisputadas
 * @brief Incrementa la cantidad de partidas disputadas del jugador.
 * @param j El jugador al cual se le desea incrementar la cantidad de partidas disputadas.
 */
void IncrementarPartidasDisputadas (Jugador &j);

/**
 * @fn IncrementarPartidasGanadas
 * @brief Incrementa la cantidad de partidas ganadas del jugador.
 * @param j El jugador al cual se le desea incrementar la cantidad de partidas ganadas.
 */
void IncrementarPartidasGanadas (Jugador &j);

#endif
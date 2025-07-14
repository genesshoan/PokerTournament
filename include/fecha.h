#ifndef _FECHA_H
#define _FECHA_H

#include "boolean.h"

typedef struct
{
    int dia;
    int mes;
    int ano;
} Fecha;

/*Dada una fecha devuelve el dia*/
int Devolver_Dia (Fecha fecha);

/*Dada una fecha devuelve el mes*/
int Devolver_Mes (Fecha fecha);

/*Dada una fecha devuelve el ano*/
int Devolver_Ano (Fecha fecha);

/*Devuelve TRUE si la fecha ingresada es valida*/
boolean Validar_Fecha (Fecha fecha);

/*Carga los componentes de la estructura*/
void Cargar_Fecha (Fecha &fecha);

/*Despliega por pantalla la estructura*/
void Mostrar_Fecha (Fecha fecha);

/*Verifica que la fecha sea 1 posterior a la 2*/
boolean FechaPosterior (Fecha f1, Fecha f2);

/*Verifica que 2 fechas sean iguales*/
boolean FechasIguales (Fecha f1, Fecha f2);

/*Verifica que la fecha 1 sea anterior a la 2*/
boolean FechaAnterior (Fecha f1, Fecha f2);

/*Ordena las fechas de mayor a menor*/
void OrdenarFechas (Fecha &f1, Fecha &f2);

#endif

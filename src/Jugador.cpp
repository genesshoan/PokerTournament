#include "Jugador.h"

long int GetCedulaJugador (Jugador j){
    return j.Cedula;
}

Fecha GetFechaNacimiento (Jugador j) {
    return j.Fecha_Nacimiento;
}

int GetNumeroJugador (Jugador j) {
    return j.Nro_Jugador;
}

void GetNombre (Jugador j, string &nombre) {
    strcop(nombre, j.Nombre);
}

void GetApellido (Jugador j, string &apellido) {
    strcop(apellido, j.Apellido);
}

void GetDepartamento (Jugador j, string &dept) {
    strcop(dept, j.Departamento);
}

int GetPartidasDisputadas (Jugador j) {
    return j.Cant_Partidas_Disputadas;
}

int GetPartidasGanadas (Jugador j) {
    return j.Cant_Partidas_Ganadas;
}

void CargarJugador (Jugador &j, long int cedula, int numero) {
    j.Nro_Jugador = numero;
    j.Cedula = cedula;
    printf("\tFecha de nacimiento del jugador:\n");
    Cargar_Fecha(j.Fecha_Nacimiento);
    strcrear(j.Nombre);
    printf("\tIngrese el nombre del jugador: ");
    ClearBuffer(); // Lipiar la linea, fflush(stdin) nos da error
    scan(j.Nombre);
    strcrear(j.Apellido);
    printf("\tIngrese el apellido del jugador: ");
    scan(j.Apellido);
    strcrear(j.Departamento);
    printf("\tIngrese el departamento del jugador: ");
    scan(j.Departamento);
    j.Cant_Partidas_Disputadas = 0;
    j.Cant_Partidas_Ganadas = 0;
}

void MostrarJugador (Jugador j) {
    printf("\tCedula jugador: %ld\n", GetCedulaJugador(j));
    Mostrar_Fecha(GetFechaNacimiento(j));
    printf("\tNumero jugador: %d\n", GetNumeroJugador(j));
    string Nombre, Apellido, Departamento;
    strcrear(Nombre);
    GetNombre(j, Nombre);
    strcrear(Apellido);
    GetApellido(j, Apellido);
    strcrear(Departamento);
    GetDepartamento(j, Departamento);
    printf("\tNombre: ");
    print(Nombre);
    printf("\tApellido: ");
    print(Apellido);
    printf("\tDepartamento: ");
    print(Departamento);   
    printf("\tPartidas disputadas: %d\n", GetPartidasDisputadas(j));
    printf("\tPartidas ganadas: %d\n", GetPartidasGanadas(j));
}

void IncrementarPartidasDisputadas (Jugador &j) {
    j.Cant_Partidas_Disputadas++;
}

void IncrementarPartidasGanadas (Jugador &j) {
    j.Cant_Partidas_Ganadas++;
}
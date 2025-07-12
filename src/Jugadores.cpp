#include "Jugadores.h"

void CrearLista (Lista &l) {
    l = NULL;
}

int LargoLista(Lista l) {
    int contador;
    while(l != NULL) {
        contador++;
        l = l->sig;
    }
    return contador;
}

boolean PerteneceLista (Lista l, long int cedula) {
    boolean pertenece = FALSE;
    while (l != NULL && !pertenece) {
        if (cedula == GetCedulaJugador(l->info))
            pertenece = TRUE;
        l = l->sig;
    }
    return pertenece;
}

void MayorLista(Lista l, int &mayor) { 
    while (l != NULL) {
        if (GetNumeroJugador(l->info) > mayor)
            mayor = GetNumeroJugador(l->info);
        l = l->sig; 
    }
}

void InsFront (Lista &l, Jugador j) {
    Lista nuevo = new NodoJ;
    nuevo->info = j;
    nuevo->sig = l;
    l = nuevo;
}

Jugador ObtenerLista (Lista l, long int cedula) {
    while (GetCedulaJugador(l->info) != cedula)
        l = l->sig;    
    return l->info;
}

void ModificarLista(Lista &l, Jugador j) {
    Lista aux = l;
    long int cedula = GetCedulaJugador(j);
    while (GetCedulaJugador(aux->info) != cedula)
        aux = aux->sig;
    aux->info = j;
}

void EliminarNodo(Lista &l, long int cedula) {
    Lista aux = l;
    Lista ant = NULL;
    while(GetCedulaJugador(aux->info) != cedula) {
        ant = aux;
        aux = aux->sig;
    }

    if(aux != NULL) {
        if(ant == NULL) {
            l = aux->sig;
        }
        else
            ant->sig = aux->sig;
    }
    delete aux;
}

void MostrarLista (Lista l) {
    while (l != NULL) {
        MostrarJugador(l->info);
        l = l->sig;
    }
}

void CantJugadoresNacidosLista (Lista l, Fecha f, int &antes, int &durante, int &despues) {
    while (l != NULL) {
        Fecha nacimiento = GetFechaNacimiento(l->info);
        if (FechaAnterior(nacimiento, f))
            antes++;
        else {
            if (FechasIguales(nacimiento, f))
                durante++;
            else
                despues++;
        }
        l = l->sig;
    }
}

void MayorGanadasLista(Lista l, int maxGanadas) {
    while (l != NULL) {
        if (GetPartidasGanadas(l->info) > maxGanadas) {
            maxGanadas = GetPartidasGanadas(l->info);
        }
        l = l->sig;
    }
}

void MostrarGanadoresLista (Lista l, int maxGanadas) {
    while (l != NULL) {
        if (GetPartidasGanadas(l->info) == maxGanadas)
            MostrarJugador(l->info);
        l = l->sig;
    }  
}

int h(long int cedula) {
    return cedula % B;
}

void Make (Jugadores &j) {
    for (int i = 0; i < B; i++)
        CrearLista(j[i]);
}

boolean Member (Jugadores j, long int cedula) {
    int cubeta = h(cedula);
    return PerteneceLista(j[cubeta], cedula);
}

void Insert (Jugadores &j, Jugador jug) {
    int cubeta = h(GetCedulaJugador(jug));
    InsFront(j[cubeta], jug);
}

Jugador Find (Jugadores j, long int cedula) {
    int cubeta = h(cedula);
    return ObtenerLista(j[cubeta], cedula);
}

void Modify (Jugadores &j, Jugador jug) {
    int cubeta = h(GetCedulaJugador(jug));
    ModificarLista(j[cubeta], jug);
}

void Delete (Jugadores &j, long int cedula) {
    int cubeta = h(cedula);
    EliminarNodo(j[cubeta], cedula);
}

void ListarJugadores(Jugadores j) {
    for (int i = 0; i < B; i++)
        MostrarLista(j[i]);
}

void CantJugadoresNacidos (Jugadores j, Fecha f, int &antes, int &durante, int &despues) {
    antes = 0;
    durante = 0;
    despues = 0;
    for (int i = 0; i < B; i++)
        CantJugadoresNacidosLista(j[i], f, antes, durante, despues);
}

boolean HayJugadores (Jugadores j) {
    boolean hay = FALSE;
    int i = 0;
    while (i < B && !hay) {
        if (j[i] != NULL)
            hay = TRUE;
        i++;
    }
    return hay;
}

int NumeroSiguiente(Jugadores j) {
    int mayor = 0;
    for (int i = 0; i < B; i++) {
        Lista l = j[i];
        MayorLista(l, mayor);
    }
    
    return mayor + 1;
}

int ObtenerMayorCantidadGanadas (Jugadores j) {
    int maxGanadas = 0;
    for (int i = 0; i < B; i++)
        MayorGanadasLista(j[i], maxGanadas);
    return maxGanadas;
}

void MostrarGanadores(Jugadores j, int maxGanadas) {
    for (int i = 0; i < B; i++)
        MostrarGanadoresLista(j[i], maxGanadas);
}

int CantidadJugadores (Jugadores j) {
    int cant = 0;
    for (int i = 0; i < B; i++)
        cant += LargoLista(j[i]);
    return cant;
}

boolean CantidadJugadoresValidos (Jugadores j) {
    return (boolean)(CantidadJugadores(j) <= B);
}
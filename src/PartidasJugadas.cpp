#include "PartidasJugadas.h"

void Crear (PartidasJugadas &p) {
    p.prim = NULL;
    p.ult = NULL;
}

boolean EsVacia (PartidasJugadas p) {
    return (boolean)(p.prim == NULL);
}

void InsFront (PartidasJugadas &p, Partida part) {
    NodoP * nuevo = new NodoP;
    nuevo -> info = part;
    nuevo -> sig = p.prim;
    if (p.ult == NULL)
        p.ult = nuevo;
        
    p.prim = nuevo;
}

Partida Primero (PartidasJugadas p) {
    return p.prim->info;
}

void Resto (PartidasJugadas &p) {
    NodoP * borrar = p.prim;
    p.prim = p.prim ->sig;
    if (p.prim == NULL)
        p.ult = NULL;
    delete borrar;
}

int Largo (PartidasJugadas p) {
    int cont = 0;
    while (!EsVacia(p)) {
        cont++;
        p.prim = p.prim->sig;
    }
    return cont;
}

Partida K_esimo (PartidasJugadas p, int k) {
    NodoP * aux = p.prim;
    while (k > 1) {
        aux = aux->sig;
        k--;
    }
    return aux->info;
}

void InsBack (PartidasJugadas &p, Partida part) {
    NodoP * nuevo = new nodoP;
    nuevo -> info = part;
    nuevo -> sig = NULL;
    if (p.ult == NULL) {
        p.ult = nuevo;
        p.prim = nuevo;
    }
    else {
        p.ult -> sig = nuevo;
        p.ult = nuevo;
    }

}

void ListarPartidasJugadas (PartidasJugadas p) {
    while (!EsVacia(p)) {
        MostrarPartida(p.prim->info);
        p.prim = p.prim->sig;
    }
}

void ListarPartidasPorJugador (PartidasJugadas p, long int cedula) {
    while (!EsVacia(p)) {
        Partida part = p.prim->info;
        if (GetCedulaJugador1(part) == cedula || GetCedulaJugador2(part) == cedula)
            MostrarPartida(part);  
        p.prim = p.prim->sig; 
    }
}

int DevolverSiguienteNmrPartida (PartidasJugadas p) {
    int num;
    if (EsVacia(p)) {
        num = 1;
    } else {
        num = GetNumeroPartida(p.ult->info) + 1;
    }
    return num;
}
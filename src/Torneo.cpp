#include "Torneo.h"

void InicializarVisitados (boolean visitados []) {
    for (int i = 0; i < N; i++)
        visitados[i] = FALSE;
}

void Crear (Torneo &t) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            t[i][j] = 0;
    }
}

boolean PerteneceVertice (Torneo t, int v) {
    return (boolean)(v >= 0 && v < N);
}

boolean PerteneceArista (Torneo t, int u, int v) {
    return (boolean)(PerteneceVertice(t, u) && PerteneceVertice(t, v) && t[u][v] == 1);
}
// void InsertarVertice (Torneo &t, int v);

void InsertarArista (Torneo &t, int u, int v) {
    t[u][v] = 1;
    t[v][u] = 1;
}

int GradoVertice (Torneo t, int v) {
     int grado = 0;
     for (int i = 0; i < N; i++) {
        if (t[v][i] == 1)
            grado ++;
     }
     return grado;
}

boolean DFS (Torneo t, int actual, int destino, boolean visitado[N]){
    visitado [actual] = TRUE;

	if (actual == destino) 
        return TRUE;

	for (int j = 0; j < N; j++){
		if (t[actual][j] == 1 && !visitado[j]){
			if (DFS (t, j, destino, visitado))
                return TRUE;
		}
	}

    return FALSE;
}

boolean MismaComponenteConexa (Torneo t, int v1, int v2) {
    boolean visitado[N];
    InicializarVisitados(visitado);
    return DFS(t, v1, v2, visitado);    
}

boolean TorneoTerminado(Torneo t) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (t[i][j] == 0)
                return FALSE;
        }
    }
    return TRUE;
}

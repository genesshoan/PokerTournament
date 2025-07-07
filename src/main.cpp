#include "Torneo.h"

// int main() {
//     Jugadores j;
//     Jugador jug;
//     Make(j);
//     for (int i = 0; i < 5; i++) {
//         CargarJugador(jug, i);
//         Insert(j, jug);
//         printf("Jugador %d insertado\n", i);
//     }
//     printf("Jugadores insertados:\n");
//     ListarJugadores(j);

//     Delete(j, 2);
//     ListarJugadores(j);
//     Delete(j, 1);
//     ListarJugadores(j);

    
//     // for (int i = 0; i < B; i++) {
//     //     int input;
//     //     scanf("%d", &input);
//     //     ClearBuffer();
//     //     if (Member(j, input)) {
//     //         printf("El jugador con cedula %d existe\n", input);
//     //         MostrarJugador(Find(j,input));
//     //     }
//     //     else
//     //         printf("El jugador con cedula %d no existe\n", input);
//     // }

//     // printf("Ingrese la cedula del jugador a modificar:\n");
//     // long int cedula;
//     // scanf("%ld", &cedula);
//     // ClearBuffer();
//     // if (Member(j, cedula)) {
//     //     Jugador Mod = Find(j, cedula);
//     //     printf("Jugador encontrado:\n");
//     //     Mod.Cant_Partidas_Disputadas += 10;
//     //     Mod.Cant_Partidas_Ganadas += 5;
//     //     Modify(j, Mod);
//     //     printf("Jugador modificado:\n");
//     //     ListarJugadores(j);
//     //     Delete(j, cedula);
//     //     printf("Jugador con cedula %ld eliminado\n", cedula);
//     //     MostrarJugador(jug);
//     // }
    
    

//     int antes, durante, despues;
//     Fecha f;
//     Cargar_Fecha(f);
//     CantJugadoresNacidos(j, f, antes, durante, despues);
//     printf("Jugadores nacidos antes de la fecha: %d\n", antes);
//     printf("Jugadores nacidos durante la fecha: %d\n", durante);
//     printf("Jugadores nacidos despues de la fecha: %d\n", despues);
// }

int main() {
    Torneo t;
    printf("Arranca o no arranca\n");
    // === CASO 1: Torneo vacío ===
    Crear(t);
    printf("Creado\n");
    printf("Torneo vacío terminado? %s\n", TorneoTerminado(t) ? "Sí" : "No");

    // === CASO 2: Torneo con algunas aristas ===
    Crear(t);
    InsertarArista(t, 0, 1);
    InsertarArista(t, 0, 2);
    InsertarArista(t, 1, 2);

    printf("\nGrado de vértice 0: %d\n", GradoVertice(t, 0));
    printf("¿0 y 2 están conectados? %s\n", MismaComponenteConexa(t, 0, 2) ? "Sí" : "No");
    printf("Torneo parcial terminado? %s\n", TorneoTerminado(t) ? "Sí" : "No");

    // === CASO 3: Torneo completo (no dirigido) ===
    Crear(t);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            InsertarArista(t, i, j);
        }
    }

    printf("\nTorneo completo terminado? %s\n", TorneoTerminado(t) ? "Sí" : "No");
    printf("¿Todos los vértices están en la misma componente?\n");
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            printf("  - %d y %d: %s\n", i, j, MismaComponenteConexa(t, i, j) ? "Sí" : "No");
        }
    }
}

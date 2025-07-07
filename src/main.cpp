#include "Jugadores.h"

int main() {
    Jugadores j;
    Jugador jug;
    Make(j);
    for (int i = 0; i < 5; i++) {
        CargarJugador(jug, i);
        Insert(j, jug);
        printf("Jugador %d insertado\n", i);
    }
    printf("Jugadores insertados:\n");
    ListarJugadores(j);

    Delete(j, 2);
    ListarJugadores(j);
    Delete(j, 1);
    ListarJugadores(j);

    
    // for (int i = 0; i < B; i++) {
    //     int input;
    //     scanf("%d", &input);
    //     ClearBuffer();
    //     if (Member(j, input)) {
    //         printf("El jugador con cedula %d existe\n", input);
    //         MostrarJugador(Find(j,input));
    //     }
    //     else
    //         printf("El jugador con cedula %d no existe\n", input);
    // }

    // printf("Ingrese la cedula del jugador a modificar:\n");
    // long int cedula;
    // scanf("%ld", &cedula);
    // ClearBuffer();
    // if (Member(j, cedula)) {
    //     Jugador Mod = Find(j, cedula);
    //     printf("Jugador encontrado:\n");
    //     Mod.Cant_Partidas_Disputadas += 10;
    //     Mod.Cant_Partidas_Ganadas += 5;
    //     Modify(j, Mod);
    //     printf("Jugador modificado:\n");
    //     ListarJugadores(j);
    //     Delete(j, cedula);
    //     printf("Jugador con cedula %ld eliminado\n", cedula);
    //     MostrarJugador(jug);
    // }
    
    

    int antes, durante, despues;
    Fecha f;
    Cargar_Fecha(f);
    CantJugadoresNacidos(j, f, antes, durante, despues);
    printf("Jugadores nacidos antes de la fecha: %d\n", antes);
    printf("Jugadores nacidos durante la fecha: %d\n", durante);
    printf("Jugadores nacidos despues de la fecha: %d\n", despues);
}

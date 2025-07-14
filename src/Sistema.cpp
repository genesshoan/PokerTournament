#include "Sistema.h"

void ResgistrarJugador(Jugadores &j, long int cedula) {
    if (Member(j, cedula)) {
        printf("\t[ ERROR ]: El jugador con la cedula %ld ya fue ingresado en el sistema.\n", cedula);
    } else {
        if (!CantidadJugadoresValidos(j)) {
            printf("\t[ ERROR ]: No se pueden registrar mas jugadores, el sistema esta lleno.\n");
            printf("\t[ TIP ]: Digite la opción 8 en el menu principal, podra ver los resultados.\n");
        } else {
            Jugador nuevoJugador;
            CargarJugador(nuevoJugador, cedula, NumeroSiguiente(j));
            Insert(j, nuevoJugador);
            printf("\t[ INFO ]: Jugador con cedula %ld registrado exitosamente.\n", cedula);
        }
        
    }
}

void ListarTodosLosJugadores(Jugadores j)
{
    if (!HayJugadores(j)) {
        printf("\t[ INFO ]: No hay jugadores registrados en el sistema.\n");
        printf("\t[ TIP ]: Digite la opción 1 en el menu principal, para registrar participantes.\n");
    }
    else {
        ListarJugadores(j);
    }
}

void ListarDatosPorJugador (Jugadores j, PartidasJugadas p, long int cedula) {
    if (!Member(j, cedula)) {
        printf("\t[ ERROR ]: El jugador con cedula %ld no existe en el sistema.\n", cedula);
    } else {
        Jugador jug = Find(j, cedula);
        MostrarJugador(jug);
        if (GetPartidasDisputadas(jug) == 0) {
            printf("\t[ INFO ]: El jugador no ha disputado ninguna partida.\n");
        } else {
            printf("\t[ RES ]: Partidas disputadas por el jugador:\n");
            ListarPartidasPorJugador(p, cedula);
        }
    }
}

void RegistrarPartida (Jugadores &j, PartidasJugadas &p, Torneo &t, long int c1, long int c2) {
    // Hace falta chequear la cantidad de partidas, no pasa nada por ingresar demás,
    // pero sería lo más correcto, se podra mejorar el output del programa
    if (c1 == c2) {
        printf("\t[ ERROR ]: No se puede registrar una partida entre el mismo jugador.\n");
    } else if (!Member(j, c1)) {
        printf("\t[ ERROR ]: El jugador con cedula %ld no existe en el sistema.\n", c1);
    }
    else if (!Member(j, c2)) {
        printf("\t[ ERROR ]: El jugador con cedula %ld no existe en el sistema.\n", c2);
    } else {
        Jugador jug1 = Find(j, c1);
        Jugador jug2 = Find(j, c2);

        int numJugador1 = GetNumeroJugador(jug1) - 1;
        int numJugador2 = GetNumeroJugador(jug2) - 1;
        /* Los jugadores comenzan en 1...N, mientras que en el grafo al tratarse de una matriz
        los vertices estan númerados desde 0...N-1 */
        if (PerteneceArista(t, numJugador1, numJugador2)) {
            printf("\t[ ERROR ]: Ya se registro una partida entre %ld y %ld en este torneo.\n", c1, c2);
        } else {
            // Insertar partida en la lista de partidas jugadas
            Partida nuevaPartida;
            // Preguntar quien es el ganador
            CargarPartida(nuevaPartida, c1, c2, DevolverSiguienteNmrPartida(p));
            InsBack(p, nuevaPartida);

            // Actualizar componentes del Jugador
            IncrementarPartidasDisputadas(jug1);
            IncrementarPartidasDisputadas(jug2);

            if (GetCedulaVencedor(nuevaPartida) == c1) {
                IncrementarPartidasGanadas(jug1);
            } else {
                IncrementarPartidasGanadas(jug2);
            }

            // Actualizar el jugador en el diccionario
            Modify(j, jug1);
            Modify(j, jug2);

            // Actualizar Torneo
            InsertarArista(t, numJugador1, numJugador2);

            printf("\t[ INFO ]: Partida registrada exitosamente entre los jugadores con cedula %ld y %ld.\n", c1, c2);
        }
    }
}

void ListarTodasLasPartidas(PartidasJugadas p) {
    if (EsVacia(p)) {
        printf("\t[ INFO ]: No hay partidas registradas en el sistema.\n");
    } else {
        printf("\t[ RES ]: Partidas jugadas en el torneo:\n");
        ListarPartidasJugadas(p);
    }
}

void CantidadJugadoresPorFecha(Jugadores j) {
    Fecha fecha;
    Cargar_Fecha(fecha);

    int antes, durante, despues;

    CantJugadoresNacidos(j, fecha, antes, durante, despues);
    printf("\t[ RES ]: Cantidad de jugadores nacidos antes de la fecha: %d\n", antes);
    printf("\t[ RES ]: Cantidad de jugadores nacidos durante la fecha: %d\n", durante);
    printf("\t[ RES ]: Cantidad de jugadores nacidos despues de la fecha: %d\n", despues);
}

void MismaSubdivision(Torneo t, Jugadores j, long int c1, long int c2) {
    if (c1 == c2) {
        printf("\t[ ERROR ]: Ha insgresado dos veces el mismo jugador.\n");
    } else if (!Member(j, c1)) {
        printf("\t[ ERROR ]: El jugador con cedula %ld no existe en el sistema.\n", c1);
    }
    else if (!Member(j, c2)) {
        printf("\t[ ERROR ]: El jugador con cedula %ld no existe en el sistema.\n", c2);
    } else {
        int numJugador1 = GetNumeroJugador(Find(j, c1)) - 1;
        int numJugador2 = GetNumeroJugador(Find(j, c2)) - 1;
        /* Los jugadores comenzan en 1...N, mientras que en el grafo al tratarse de una matriz
           los vertices estan númerados desde 0...N-1 */

        if (PerteneceArista(t, numJugador1, numJugador2)) {
            printf("\t[ INFO ]: Los jugadores forman parte de la misma subdivision.\n");
        } else if (MismaComponenteConexa(t, numJugador1, numJugador2)) {
            printf("\t[ INFO ]: Los jugadores forman parte de la misma subdivision.\n");
        } else {
            printf("\t[ INFO ]: Los jugadores NO forman parte de la misma subdivision.\n");
        }
    }
}

void MostrarTorneoCompleto(Torneo t, Jugadores j) {
    if (!TorneoTerminado(t)) {
        printf("\t[ INFO ]: El torneo aun no ha concluido.\n");

        int cantJugadores = CantidadJugadores(j);
        if (cantJugadores < B) {
            printf("\t[ INFO ]: Aun quedan jugadores por ser registrados ( %d / %d ).\n", cantJugadores, B);
            printf("\t[ TIP ]: Digite la opción 1 en el menu principal, para registrar participantes.\n");
        }
    } else {
        int maxGanadas = ObtenerMayorCantidadGanadas(j);
        printf("\t[ RES ]: Jugadores con la mayor cantidad de partidas ganadas (%d):\n", maxGanadas);
        MostrarGanadores(j, maxGanadas);
    }
}
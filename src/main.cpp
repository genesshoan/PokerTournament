#include "Sistema.h"
#include "menu.h"


int main () {
    Jugadores jugadores;
    PartidasJugadas partidas;
    Torneo torneo;

    boolean salir = FALSE;
    int opcion;

    // Crear colecciones vacias
    Crear(torneo);
    Crear(partidas);
    Make(jugadores);

    // Cambiar color del fondo
    system("COLOR 90");
    
    do
    {
        long int cedula;
        long int cedula2;
        MenuPrincipal(opcion);
        TitulosMenuPrincipal(opcion);

        switch (opcion) {
        case 0:
            salir = TRUE;
            break;
        case 1:
            scanCedula(cedula);
            ResgistrarJugador(jugadores, cedula);
            break;
        case 2:
            ListarTodosLosJugadores(jugadores);
            break;
        case 3:
            scanCedula(cedula);
            ListarDatosPorJugador(jugadores, partidas, cedula);
            break;
        case 4:
            printf("\t[ SIS ]:Ingrese la cedula del jugador 1:\n");
            scanCedula(cedula);
            printf("\t[ SIS ]: Ingrese la cedula del jugador 2:\n");
            scanCedula(cedula2);
            RegistrarPartida(jugadores, partidas, torneo, cedula, cedula2);
            break;
        case 5:
            ListarTodasLasPartidas(partidas);
            break;
        case 6:
            CantidadJugadoresPorFecha(jugadores);
            break;
        case 7:
            printf("\t[ SIS ]: Ingrese la cedula del jugador 1:\n");
            scanCedula(cedula);
            printf("\t[ SIS ]: Ingrese la cedula del jugador 2:\n");
            scanCedula(cedula2);
            MismaSubdivision(torneo, jugadores, cedula, cedula2);
            break;
        case 8:
            MostrarTorneoCompleto(torneo, jugadores);
            break; 
        default:
            printf("\t[ ERROR ]: Opcion invalida, intente nuevamente.\n");
            break;
        }
        if (!salir){
            printf("\t");
            system("pause");
        }
    } while (!salir);
    
    Adios();
}
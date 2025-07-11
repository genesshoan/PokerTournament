#include "Sistema.h"


int main() {
    Jugadores jugadores;
    PartidasJugadas partidas;
    Torneo torneo;

    Make(jugadores);
    Crear(partidas);
    Crear(torneo);

    printf("=== Registro de jugadores ===\n");
    ResgistrarJugador(jugadores, 12345678);
    ResgistrarJugador(jugadores, 87654321);
    ResgistrarJugador(jugadores, 12345678); // Intentar registrar duplicado

    printf("\n=== Listar todos los jugadores ===\n");
    ListarTodosLosJugadores(jugadores);

    printf("\n=== Registrar partida ===\n");
    RegistrarPartida(jugadores, partidas, torneo, 12345678, 87654321);
    RegistrarPartida(jugadores, partidas, torneo, 12345678, 12345678); // Misma cédula

    printf("\n=== Listar todas las partidas ===\n");
    ListarTodasLasPartidas(partidas);

    printf("\n=== Datos de jugador ===\n");
    ListarDatosPorJugador(jugadores, partidas, 12345678);

    printf("\n=== Jugadores por fecha ===\n");
    CantidadJugadoresPorFecha(jugadores);

    printf("\n=== Ver si están en la misma subdivisión ===\n");
    MismaSubdivision(torneo, jugadores, 12345678, 87654321);

    printf("\n=== Mostrar torneo completo ===\n");
    MostrarTorneoCompleto(torneo, jugadores);
}
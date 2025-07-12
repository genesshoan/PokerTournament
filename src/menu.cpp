#include "menu.h"

void TitulosMenuPrincipal (int opcion)
{
    switch (opcion)
    {
    case 1:
        printf("\n\tREGISTRAR JUGADOR\n\t-----------------\n");
        break;
    case 2:
        printf("\n\tJUGADORES DEL SISTEMA\n\t---------------------\n");
        break;
    case 3:
        printf("\n\tDATOS DEL JUGADOR\n\t-----------------\n");
        break;
    case 4:
        printf("\n\tREGISTRAR PARTIDA\n\t-----------------\n");
        break;
    case 5:
        printf("\n\tPARTIDAS DEL SISTEMA\n\t--------------------\n");   
        break;
    case 6:
        printf("\n\tJUGADORES POR FECHA\n\t-------------------\n");
        break;
    case 7:
        printf("\n\tMISMA SUBDIVISION\n\t-----------------\n");
        break;
    case 8:
        printf("\n\tTORNEO COMPLETO\n\t---------------\n");
        break;
    }
}

void TituloPrincipal ()
{
    printf("\n\n\t ___  ___                 \n");
    printf("\t|  \\/  |                 \n");
    printf("\t| .  . | ___ _ __  _   _ \n");
    printf("\t| |\\/| |/ _ \\ '_ \\| | | |\n");
    printf("\t| |  | |  __/ | | | |_| |\n");
    printf("\t\\_|  |_/\\___|_| |_|\\__,_|\n");
    printf("\t                         \n");
    printf("\tObligatorio de programacion III\n");
}

void MenuPrincipal (int &opcion)
{
    system("cls");
    TituloPrincipal();
    printf("\n\t1. Registrar jugador.\n");
    printf("\t2. Listar todos los jugadores.\n");
    printf("\t3. Listar datos del jugador por cedula.\n");
    printf("\t4. Registrar partida.\n");
    printf("\t5. Listar todas las partidas\n");
    printf("\t6. Cant. jugadores por fecha.\n");
    printf("\t7. Misma subdivision.\n");
    printf("\t8. Torneo Completo?.\n");
    printf("\t0. SALIR\n");
    printf("\tIngrese una opcion: ");
    scanf("%d", &opcion);
    ClearBuffer();

    system("cls");
}

void Adios ()
{
    printf("\t               _ _           \n");
    printf("\t     /\\      | (_)          \n");
    printf("\t    /  \\   __| |_  ___  ___ \n");
    printf("\t   / /\\ \\ / _` | |/ _ \\/ __|\n");
    printf("\t  / ____ \\ (_| | | (_) \\__ \\ \n");
    printf("\t /_/    \\_\\__,_|_|\\___/|___/ \n");
}
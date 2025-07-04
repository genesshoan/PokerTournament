#include "fecha.h"

int Devolver_Dia(Fecha fecha)
{
    return fecha.dia;
}

int Devolver_Mes(Fecha fecha)
{
    return fecha.mes;
}

int Devolver_Ano(Fecha fecha)
{
    return fecha.ano;
}

boolean Validar_Fecha(Fecha fecha)
{
    boolean valido = FALSE;
    int dia, mes, ano;
    dia = fecha.dia;
    mes = fecha.mes;
    ano = fecha.ano;

    if (fecha.mes >= 1 && fecha.mes <= 12)
    {
        switch (fecha.mes)
        {
        case 2:
            if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
            {
                if (dia >= 1 && dia <= 29)
                    valido = TRUE;
            }
            else
            {
                if (dia >= 1 && dia <= 28)
                    valido = TRUE;
            }
            break;
        case 4: case 6: case 9: case 11:
            if (dia >= 1 && dia <= 30)
                valido = TRUE;
            break;
        default:
            if (dia >= 1 && dia <= 31)
                valido = TRUE;
        }
    }
    return valido;
}

void Cargar_Fecha(Fecha &fecha)
{
    boolean valido;
    do
    {
        printf("\tIngrese la fecha (Formato DD MM AAAA): ");
        scanf("%d %d %d", &fecha.dia, &fecha.mes, &fecha.ano);
        valido = Validar_Fecha(fecha);
        if (!valido)
            printf("\tEl valor de fecha ingresado es invalido, por favor intente nuevamente.\n");
    } while (!valido);
}

void Mostrar_Fecha(Fecha fecha)
{
    printf("\tFecha: %d / %d / %d\n", Devolver_Dia(fecha), Devolver_Mes(fecha), Devolver_Ano(fecha));
}

boolean FechaPosterior (Fecha f1, Fecha f2){
    boolean posterior = FALSE;
    if (Devolver_Ano(f1) > Devolver_Ano(f2))
        posterior = TRUE;
    else
        if (Devolver_Ano(f1) == Devolver_Ano(f2))
        {  
            if (Devolver_Mes(f1) > Devolver_Mes(f2))
                posterior = TRUE;
            else 
                 if (Devolver_Mes(f1) == Devolver_Mes(f2)) 
                 {
                    if (Devolver_Dia(f1) >= Devolver_Dia(f2))
                        posterior = TRUE;
                 }
        }   
    return posterior;
}

boolean FechasIguales (Fecha f1, Fecha f2) {
    boolean iguales = FALSE;
    if (Devolver_Ano(f1) == Devolver_Ano(f2))
        if (Devolver_Mes(f1) == Devolver_Mes(f2))
            if (Devolver_Dia(f1) == Devolver_Dia(f2))
                iguales = TRUE;
    return iguales;
}

boolean FechaAnterior (Fecha f1, Fecha f2){
    boolean anterior = FALSE;
    if (Devolver_Ano(f1) < Devolver_Ano(f2))
        anterior = TRUE;
    else
        if (Devolver_Ano(f1) == Devolver_Ano(f2))
        {  
            if (Devolver_Mes(f1) < Devolver_Mes(f2))
                anterior = TRUE;
            else 
                 if (Devolver_Mes(f1) == Devolver_Mes(f2)) 
                 {
                    if (Devolver_Dia(f1) <= Devolver_Dia(f2))
                        anterior = TRUE;
                 }
        } 
    return anterior;
}

void OrdenarFechas (Fecha &f1, Fecha &f2) {
    if (!FechasIguales(f1, f2))
        if (!FechaAnterior(f1,f2)){
            Fecha aux = f1;
            f1 = f2;
            f2 = aux;
        }
}
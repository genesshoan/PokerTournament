#include "string.h"

void strcrear (string &str){
    str = new char [1];
    str[0] = '\0';
}

void strdestruir (string &str){
    delete [] str;
    str = NULL;
}

int strlar (string str){
    int length = 0;

    while (str[length] != '\0')
        length++;
    return length;
}

void strcop (string &str1, string str2){
    int i = 0, largo;
    largo = strlar(str2) + 1;
    delete [] str1;
    str1 = new char [largo];

    while (str2[i] != '\0')
    {
        str1[i] = str2[i];    
        i++;
    }
    str1[i] = '\0'; 
}

void scan (string &str){
    string aux = new char [MAX];
    int i = 0;
    char input;

    fflush(stdin);
    scanf("%c", &input);
    while (input != '\n' && i < (MAX - 1))
    {
        aux[i] = input;
        scanf("%c", &input);
        i++;
    }
    aux[i] = '\0';
    strcop(str,aux);
    strdestruir(aux);
}
// Mejorar codigo
void strcon (string &str1, string str2){
    int i, j, largo1, largo2, largototal;
    string aux;

    largo1 = strlar(str1);
    largo2 = strlar(str2);

    aux = new char [largo1 + 1];
    strcop(aux, str1);

    delete [] str1;
    largototal = largo1 + largo2 + 1;

    if (largototal > MAX)
        largototal = MAX;
    str1 = new char [largototal];

    i = 0;
    j = 0;
    while (i < (largototal - 1) && aux[j] != '\0')
    {
        str1[i] = aux[j];
        i++;
        j++;
    }
    j = 0;
    while (i < (largototal - 1) && str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';

    strdestruir(aux);
}
// mejor cambiar los punteros
void strswp (string &str1, string &str2){
    string aux = NULL;
    strcop(aux,str1);
    strcop(str1,str2);
    strcop(str2,aux);
    strdestruir(aux);
}

void print (string str){
    int i = 0;
    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
}

boolean strmen (string str1, string str2){
    boolean menor, mayor;
    int i = 0;
    menor = FALSE;
    mayor = FALSE;

    while (str1[i] != '\0' && str2[i] != '\0' && !menor  && !mayor)
    {
        if (str1[i] < str2[i])
            menor = TRUE;
        else
            if (str1[i] > str2[i])
                mayor = TRUE;
            else
                i++;
    }
    if (!menor && !mayor)
    {
        if (str1[i] == '\0' && str2[i] != '\0')
            menor = TRUE;
    }
    return menor;
}

boolean streq (string str1, string str2){
    int i = 0;
    boolean iguales = TRUE;

    while (str1[i] != '\0' && str2[i] != '\0' && iguales)
    {
        if (str1[i] != str2[i])
            iguales = FALSE;
        else
            i++;
    }
    if (iguales && ((str1[i] == '\0' && str2[i] != '\0') || (str2[i] == '\0' && str1[i] != '\0')))
        iguales = FALSE;
    return iguales;
}

void Bajar_String (string s, FILE * f)  
{ 
    int i=0; 
    while (s[i] != '\0') { 
        fwrite (&s[i], sizeof(char), 1, f); 
        i++; 
    } 
    // escribo el '\0' 
    fwrite (&s[i], sizeof(char), 1, f); 
} 
void Levantar_String (string &s, FILE * f)  
{ 
    int i=0; 
    string aux; 
    aux = new char[MAX]; 
    fread (&aux[i], sizeof(char), 1, f); 
    while (!feof(f) && (aux[i] != '\0')) { 
        i++; 
        fread (&aux[i], sizeof(char), 1, f); 
    } 
    if (feof(f)) 
        aux[i] = '\0'; 
    strcop (s, aux); 
    delete [] aux; 
} 

void ClearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

long int convertirStringNumerico(string str)
{
    int i = 0;
    long int num = 0;
    boolean negativo = FALSE;

    if (str[i] == '-') {
        negativo = TRUE;
        i++;
    }

    while (str[i] != '\0') {
        num = num * 10 + (str[i] - '0'); // 48 -> '0'
        i++;
    }

    if (negativo)
        num = -num;

    return num;
}

boolean EsNumerico(string str) {
    int i = 0;

    if (str[0] == '\0')
        return FALSE;

    if (str[0] == '-') {
        if (str[1] == '\0')
            return FALSE;
        i = 1;
    }

    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return FALSE;
    }

    return TRUE;
}

boolean EsCero(string str) {
    return (boolean)(convertirStringNumerico(str) == 0);
}

void scanCedula(long int &cedula) {
    string str;
    strcrear(str);
    boolean valido = FALSE;

    do {
        printf("\t[ SIS ]: Ingrese cedula sin puntos ni guiones: ");
        scan(str);

        if (!EsNumerico(str)) {
            printf("\t[ ERROR ]: Entrada invalida.\n");
            printf("\t[ INFO ]: Solo se admiten digitos (0...9). Intente nuevamente.\n");
        } else if (EsCero(str)) {
            printf("\t[ ERROR ]: Cedula invalida.\n");
            printf("\t[ INFO ]: Este campo no puede ser cero. Intente nuevamente.\n");
        } else {
            valido = TRUE;
        }

        if (!valido)
            strdestruir(str);

    } while (!valido);

    cedula = convertirStringNumerico(str);
}

boolean ContieneDigitos(string str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            return TRUE;
        }
    }
    return FALSE;
}

void scanNombre (string &str, const char * nombre) {
    strcrear(str);
    boolean valido = FALSE;

    do {
        printf("\t[ SIS ]: Ingrese %s: ", nombre);
        scan(str);

        if (ContieneDigitos(str)) {
            printf("\t[ ERROR ]: Entrada invalida.\n");
            printf("\t[ INFO ]: Solo se admiten caracteres no numericos. Intente nuevamente.\n");
        } else if (strlar(str) < 1) {
            printf("\t[ ERROR ]: Entrada invalida.\n");
            printf("\t[ INFO ]: Este campo no puede estar vacio. Intente nuevamente.\n");
        } else {
            valido = TRUE;
        }

        if (!valido)
            strdestruir(str);
    } while (!valido);
}
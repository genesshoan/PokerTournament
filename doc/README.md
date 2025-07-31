# Obligatorio Programación III

- **Autores:** Valdo Castiglia, Shoan Genes.
- **Profesor:** Joel Estramil.
- **Fecha de entrega:** 15 de julio de 2025
---

# Introducción general

El presente informe describe el diseño y modelado de un sistema de gestión para un torneo nacional de póker, desarrollado como parte del trabajo obligatorio de la materia **Programación $\text{III}$.** El sistema tiene como objetivo principal utilizarse en la organización y administración de un torneo, todos los jugadores juegan contra todos, es decir, cada jugador disputará una partida contra cada uno de los demás a lo largo del torneo, siendo el ganador aquel que haya salido victorioso en más partidas.

El sistema debe permitir registrar las partidas en orden cronológico (de menor a mayor), mantener estadísticas de los jugadores de forma implícita y realizar consultas específicas a los datos almacenados en memoria, como determinar si dos jugadores pertenecen a la misma sub-división del torneo o si el torneo ha concluido.

Al tratarse de un **prototipo** no se incluye funcionalidades de persistencia de los datos en memoria secundaria.

Para abordar esta problemática, se ha sugerido optar por la **teoría de grafos** como modelo conceptual, complementando con el análisis y diseño de $\text{Tipos Abstractos de Datos}$ (TADs) apropiados para la representación eficiente de la información y las operaciones requeridas.

El presente documento forma parte de la entrega que incluye tanto análisis teórico como la implementación en `C++` del sistema completo.
`Mensaje:`La cantidad de jugadores esta seteada en 3, para hacer las pruebas más rápidas. Si se desea aumentar la cantidad de jugadores, modificar en el archivo **Jugadores.h** la constante `B` y en **Torneo.h** la constante `N`.

---

# Modelado mediante grafo

El grafo se utiliza para modelar las **relaciones de juego entre los jugadores** del torneo:

- **Los vértices:** Cada vértice representa un **jugador** del torneo.
- **Las aristas:** Cada arista representa una **partida disputada** entre dos jugadores.

### Propiedades del Grafo

- **Grafo Simple:** No hay **bucles** (un jugador no juega consigo mismo), ni hay múltiples aristas entre el mismo par de jugadores (no es multígrafo).
- **No dirigido:** Las **partidas** son entre pares de jugadores, y la relación “han jugado entre si” es bidireccional. Semánticamente es lo mismo “J1 jugó con J2” que “J2 jugó con J1”.
- **Orden N:** Tiene **N vértices**, uno por cada jugador inscripto.
- **Número máximo de aristas $\frac{N(N-1)}{2}$:** Ya que cada par de jugadores debe de jugar una sola vez entre sí.
- **Grafo completo (Al finalizar el torneo):** Cuando termine el torneo todos los Jugadores habrán jugado entre si por lo tanto todos los vértices estarán conectados entre si
    
    ![Ejemplo para un torneo de 5 participantes.](https://github.com/genesshoan/PokerTournament/blob/main/img/GrafoObligatorio.drawio.png)
    
    Ejemplo para un torneo de 5 participantes.
    

---

# Análisis de TADs

Una vez establecido el modelo conceptual mediante grafos, es necesario elegir que tipos de datos se utilizaran para representar el contexto del sistema. Los Tipos Abstractos de Datos (TADs) nos proporcionan una metodología para especificar qué información debe almacenarse y qué operaciones deben realizarse, independientemente de los detalles de implementación.

En está sección se analizan los requerimientos de almacenamiento y procesamiento de datos del sistema, identificando los TADs más apropiados para cada tipo de información. Se consideran aspectos como el orden de registro de partidas, la necesidad de búsquedas, las operaciones de actualización y consulta, así como las relaciones entre los diferentes entidades del sistema.

El análisis se centra en dos entidades principales: las partidas jugadas (que requieren un orden cronológico) y los jugadores (que requiere ser identificados por cédula), definiendo para cada una el TAD más adecuado según sus características y uso esperado.

- $Torneo = Grafo(NumeroJugador, \{NumeroJugador, NumeroJugador\})$
    
    La elección del **TAD Grafo** para la representación de esta realidad se basa en la practicidad del grafo. Con esto nos referimos a que se busca una representación simplificada que además puede representarse con relativa facilidad en lenguajes de programación.
    
    Las funcionalidades requeridas 7 y 8 pueden entenderse con facilidad aplicando teoría de grafos, para generar un modelado abstracto de la relación "$J_n$ ha jugado con $J_k$”:
    
    - Saber si dos jugadores forman parte de la misma subdivisión es equivalente a determinar mediante un algoritmo basado en DFS si forman parte de la misma componente conexa del grafo.
    - Saber si ha concluido el torneo se puede determinar verificando si el grafo ha quedado completo
- **$*PartidasJugadas = Secuencia(Partida)*$**
Dado que se desea registrar las partidas en el orden en que se juegan, por su número de partida, de menor a mayor, y no se específica la necesidad de realizar búsquedas por número ni eliminar elementos, en definitiva, no se describe un comportamiento mas complejo que el de una secuencia lineal. Es decir, no existen requerimientos de comportamientos semejantes a los de un Queue, Deque o Stack.
Por lo tanto, el **TAD secuencia** **simple** es el más apropiado para representar esta agrupación de entidades, ya que se quiere almacenar las partidas en forma ordenada cronológicamente, recorriéndolas secuencialmente cuando sea necesario.
- $Partida = Producto Carteciano (NúmeroPartida, Cedula1, Cedula1, CedulaVencedor)$
Utilizamos un TAD producto cartesiano porque queremos representar la entidad Partida entre los jugadores $J_n$ y $J_k$.
- $Cedula = Entero$
- $NúmeroPartida = Entero$
- $Jugadores = Diccionario(Jugador)$
Dado que a la entidad **Jugador** se la puede identificar mediante la cédula de identidad, y que se específica dentro de los requerimientos la necesidad de optimizar la búsqueda de los mismos por cédula, la colección más apropiada es un **Diccionario**.
- $Jugador = Producto Cartesiano(
  Cédula,\ 
  FechaNacimiento,\ 
  NúmeroJugador,\\ 
  Nombre,\ 
  Apellido,\ 
  Departamento,\\ 
  CantidadPartidas,\ 
  CantidadJugadas)$
Utilizamos un TAD producto cartesiano porque queremos representar la entidad **Jugador**, la cual está compuesta por valores que provienen de diferentes conjuntos de datos.
- $FechaNacimiento = Fecha$
- $NúmeroJugador = Entero$
- $Nombre = String$
- $Apellido = String$
- $Departamento = String$
- $CantidadPartidas = Entero$
- $CantidadJugadas = Entero$
- $Fecha = Producto Cartesiano(Dia, Mes, Año)$
    
    Utilizamos un TAD producto cartesiano porque queremos representar la entidad **Fecha**, la cual está compuesta por valores que provienen de diferentes conjuntos de datos.
    
- $Dia = Entero$
- $Mes = Entero$
- $Año = Entero$

---

# Estructuras a utilizar

Esta sección detalla las estructuras de datos concretas seleccionadas para implementar cada uno de los TADs definidos en el análisis anterior. La elección de cada estructura se fundamenta en los requerimientos específicos del sistema, considerando factores como eficiencia temporal, uso de memoria y patrones de acceso esperados.

Para cada estructura se presenta su definición en lenguaje `C++`, junto con la justificación técnica de su selección, explicando cómo cada implementación optimiza las operaciones más frecuentes del sistema.

### Torneo

En el contexto de este torneo y como se ha analizado previamente, dado que el torneo concluye cuando todos los jugadores han jugado con todos, menos ellos mismos, es decir, al tratarse de uno completo, la representación mediante de **listas de adyacencia** no es adecuada, esta es útil cuando la cantidad de aristas en el grafo no es elevada, ya que esta almacena en cada lista correspondiente a un vértice, todos los vértices adyacentes a este, al tratarse de un grafo que va a tener en algún momento muchas aristas, se pierde eficiencia en la búsqueda, el recorrido y el uso de memoria, ya que se duplican datos innecesariamente.

![Ejemplo para el grafo representado en el “Análisis mediante grafo”.](https://github.com/genesshoan/PokerTournament/blob/main/img/fe08f348-fff1-4279-b8e4-a443ba8ccd9a.png)

Ejemplo para el grafo representado en el “Análisis mediante grafo”.

Por lo tanto, y coherentemente con lo que se ha planteado a lo lago de la primera parte del curso, la **matriz de adyacencia** es más eficiente, cuando hay un elevado número de aristas. También está representación nos permite optimizar el determinar “¿estos dos jugadores han jugado?”, ya que la operación de saber si existe una arista es de O(1); esta operación debe ejecutarse cada vez que se ingresa un partida, ya que dos jugadores no pueden jugar entre si dos veces.

Adicionalmente, verificar si el torneo está completo, equivale a saber si la matriz tiene $\frac{N(N-1)}{2}$ aristas.

```cpp
const int N = ...;
typedef int Torneo [N][N];
```

### PartidasJugadas

Una lista con puntero al principio y al final (LPPF), permite optimizar las operaciones de inserción al final en O(1), manteniendo así el ordenamiento de las partidas por número de menor a mayor. Manteniendo una eficiencia similar a la de un arreglo con tope (ACT) para las operaciones deseadas, pero al ser una estructura dinámica el consumo de memoria crece según la cantidad real de partidas.

```cpp
typedef struct nodoP {
	Partida info;
	nodoP * sig;
} NodoP;

typedef struct {
	NodoP * prim;
	NodoP * ult;
} PartidasJugadas;
```

### Partida

Contiene el resultado de una partida disputada entre dos jugadores, además de contener al **vencedor** de la misma partida.

```cpp
typedef struct {
	int Nro_Partidas;
	long int Cedula_Jugador1;
	long int Cedula_Jugador2;
	long int Cedula_Vencedor;
}Partida;
```

### Jugadores

Dado que se conoce que habrá una cantidad acotada de jugadores en el torneo, si bien no se específica cual (se asume N), y que no se requiere ningún orden específico de los elementos, la estructura más apropiada es una tabla **Hash**. Con esta estructura se optimiza la búsqueda por cédula, con un promedio, contando con una buena función de dispersión, de **O(1)**.

Siendo está estructura elegida antes de una variante del árbol binario, ya que no se necesita listar a los jugadores en ningún orden particular.

El mapeo queda descartado, ya que la identificación de los jugadores debería hacerse por su número de jugador (0…N-1), lo cual no es eficiente, dado que se requiere optimizar las búsquedas por cédula para algunas operaciones.

```cpp
const int B = ...; // Número de jugadores
typedef struct nodoJ {
	Jugador info;
	nodoJ * sig;
} NodoJ;
typedef NodoJ * Lista;
typedef Lista Jugadores[B];
```

### Jugador

Se representa un conjunto de atributos fijo y limitado que contiene cada atributo solicitado en la letra del Obligatorio, que nos permite acceder, modificar y mostrar los datos de cada jugador.

```cpp
typedef struct {
	long int Cedula;
	Fecha Fecha_Nacimiento;
	int Nro_Jugador;
	string Nombre;
	string Apellido;
	string Departamento;
	int Cant_Partidas_Disputadas;
	int Cant_Partidas_Ganadas;
} Jugador;
```

### Fecha

```cpp
typedef struct{
	int Dia;
	int Mes;
	int Anio;
} Fecha;
```

---

# Esquema de módulos

El sistema se estructura mediante una arquitectura modular que separa claramente las responsabilidades y facilita el mantenimiento del código. Esta organización permite una implementación escalable y comprensible, donde cada módulo encapsula funcionalidades específicas relacionadas con una entidad o conjunto de operaciones del dominio del problema.
El **Módulo Sistema** actúa como coordinador principal, encargándose de las interacciones entre los diferentes componentes del sistema para proveer las funcionalidades de alto nivel requeridas por el usuario.

![Esquema de Modulos.drawio.png](https://github.com/genesshoan/PokerTournament/blob/main/img/Esquema_de_Modulos.drawio.png)

# Definiciones

En esta sección se presenta la especificación detallada de las operaciones primitivas de cada Tipo Abstracto de Datos (TAD) y las funciones auxiliares necesarias para el correcto funcionamiento del sistema. Para cada módulo se describen los encabezados de las funciones, sus precondiciones cuando aplican, y una explicación de su propósito y comportamiento esperado.

Cada definición incluye las precondiciones necesarias para garantizar el uso correcto de las operaciones, especificando los estados válidos de las estructuras de datos antes de la ejecución de cada función. Esto asegura la robustez del sistema y facilita la detección temprana de errores durante el desarrollo y las pruebas.

### Modulo String

El módulo String proporciona una implementación completa para el manejo de cadenas de caracteres dinámicas, ofreciendo todas las operaciones necesarias para la manipulación de texto dentro del sistema. Este módulo es fundamental ya que muchas de las entidades del sistema requieren almacenar y procesar información textual como nombres, apellidos y departamentos.

| Encabezados | Descripciones |
| --- | --- |
| void strcrear (string &str) | Inicializa un string con el carácter NULL (’\0’). |
| void strdestruir (string &str) | Libera la memoria de un string y establece el puntero en NULL. |
| int strlar (string str) | Devuelve el largo de un string. |
| void strcop (string &str1, string str2) | Copia el segundo string en el primero. |
| void scan (string &str) | Permite cargar una string por teclado. |
| void strcon (string &str1, string str2) | Concatena en str1 el segundo string. |
| void strswp (string &str1, string &str2) | Intercambia los contenidos de los strings. |
| void print (string str) | Lista un string por pantalla. |
| boolean strmen (string str1, string str2) | Determina si el primer string es menor que el segundo, alfabéticamente hablando.  |
| boolean streq (string str1, string str2) | Determina si dos string son iguales. |
| void Bajar_String (string s, FILE * f) | Escribe en un archivo los caracteres del string.
**Precondición:** El archivo viene abierto para escritura. |
| void Levantar_String (string &s, FILE * f) | Lee desde el archivo los caracteres del string.
**Precondición:** El abierto viene abierto para lectura. |
| void ClearBuffer(); | Limpia el Buffer |
| long int convertirStringNumerico(string str) | Permite convertir un string a un valor numérico.
**Precondición:** El string efectivamente debe de ser númerico. |
| boolean EsNumerico(string str) | Determina si un string es completamente numérico. |
| boolean EsCero(string str) | Determina si el valor numérico de un string es cero. |
| void scanCedula(long int &cedula) | Permite escanear una cedula, realizando chequeos para solo aceptar valores completamente numéricos. |
| void scanNombre(string &str, const char * nombre) | Permite escanear un string que no es vacío ni numérico. |
| boolean ContieneDigitos(string str) | Comprueba si existe algún digito en el string |

### Modulo Fecha

Este módulo encapsula toda la lógica relacionada con el manejo de fechas, proporcionando una interfaz robusta para crear, validar y comparar fechas. Su importancia radica en que el sistema requiere gestionar fechas de nacimiento de jugadores y realizar operaciones de comparación temporal.

| Encabezados | Descripciones |
| --- | --- |
| int Devolver_Dia (Fecha fecha) | Dada una fecha devuelve el día. |
| int Devolver_Mes (Fecha fecha) | Dada una fecha devuelve el mes. |
| int Devolver_Ano (Fecha fecha) | Dada una fecha devuelve el año. |
| boolean Validar_Fecha (Fecha fecha) | Devuelve TRUE si la fecha ingresada es valida. |
| void Cargar_Fecha (Fecha &fecha) | Carga los componentes de la estructura. |
| void Mostrar_Fecha (Fecha fecha) | Despliega por pantalla la estructura. |
| boolean FechaPosterior (Fecha f1, Fecha f2) | Verifica que la fecha sea 1 posterior a la 2. |
| boolean FechasIguales (Fecha f1, Fecha f2) | Verifica que 2 fechas sean iguales. |
| boolean FechaAnterior (Fecha f1, Fecha f2) | Verifica que la fecha 1 sea anterior a la 2. |
| void OrdenarFechas (Fecha &f1, Fecha &f2) | Ordena las fechas de mayor a menor. |

### Modulo Jugador

Representa la entidad central del sistema, encapsulando todos los datos y operaciones relacionadas con los participantes del torneo. Este módulo mantiene la integridad de los datos de cada jugador y proporciona una interfaz consistente para acceder y modificar esta información.

| Encabezados | Descripciones |
| --- | --- |
| long int GetCedulaJugador (Jugador j) | Devuelve la cedula de un jugador. |
| Fecha GetFechaNacimiento (Jugador j) | Devuelve la fecha de un jugador. |
| int GetNumeroJugador (Jugador j) | Devuelve el número de un jugador. |
| void GetNombre (Jugador j, string &nombre) | Devuelve el nombre de un jugador. |
| void GetApellido (Jugador j, string &apellido) | Devuelve el apellido de un jugador. |
| void GetDepartamento (Jugador j, string &dept) | Devuelve el departamento de un jugador. |
| int GetPartidasDisputadas (Jugador j) | Devuelve la cantidad de partidas disputadas de un jugador. |
| int GetPartidasGanadas (Jugador j) | Devuelve la cantidad de partidas ganadas de un jugador. |
| void CargarJugador (Jugador &j, long int cedula, int numero) |  Cargar los datos de un jugador. |
| void MostrarJugador (Jugador j) | Lista los datos de un jugador por pantalla. |
| void IncrementarPartidasDisputadas (Jugador &j) | Incrementa en 1 la cantidad de partidas disputadas del jugador. |
| void IncrementarPartidasGanadas (Jugador &j) | Incrementa en 1 la cantidad de paridas disputadas del jugador. |

### Modulo Partida

Modela cada encuentro entre dos jugadores, almacenando la información esencial sobre el resultado de la partida. Este módulo es crucial para mantener el historial completo del torneo y calcular las estadísticas de los jugadores.

| Encabezados | Descripciones |
| --- | --- |
| long int GetCedulaJugador1 (Partida p) | Devuelve la cedula del jugador 1. |
| long int GetCedulaJugador2 (Partida p) | Devuelve la cedula del jugador 2. |
| int GetNumeroPartida (Partida p) | Devuelve el número de partida. |
| long int GetCedulaVencedor (Partida p) | Devuelve el número de cedula del vencedor. |
| void CargarPartida (Partida &p, int numero) | Permite al usuario cargar una partida, y asigna el numero dado. |
| void MostrarPartida (Partida p) | Lista por pantalla los datos de una partida. |

### Modulo Jugadores

Implementa una colección optimizada de jugadores utilizando una tabla hash, proporcionando acceso eficiente por cédula de identidad. Esta estructura es fundamental para las operaciones de búsqueda frecuentes que requiere el sistema.

| Encabezados | Descripciones |
| --- | --- |
| void CrearLista(Lista &L) | Crea una lista vacia |
| int LargoLista(Lista l) | Devuelve el largo de la Lista |
| boolean PerteneceLista(Lista l, long int cedula) | Dada una cedula, determina si existe un jugador en la lista con dicha cedula. |
| void MayorLista(Lista l, int &mayor) | Obtiene el mayor número de jugador de la lista. |
| void InsFront(Lista &l, Jugador j) | Inserta el jugador en la lista. |
| Jugador ObtenerLista (Lista l, long int cedula) | Obtiene un jugador de la lista por su cédula.
**Precondición:** El jugador debe existir en la lista. |
| void ModificarLista(Lista &l, Jugador j) | Modifica los datos de un jugador. |
| void EliminarNodo(Lista &l, long int cedula) | Elimina a un jugador, dando la cedula del jugador a eliminar |
| void MostrarLista(Lista l) | Muestra todos los jugadores del sistema. |
| void CantJugadoresNacidosLista (Lista l, Fecha f,  int &antes, int &durante, int &despues) | Determina cuantos jugadores nacieron antes, durante y después de una fecha dada. |
| void MayorGanadasLista(Lista l, int &maxGanadas) | Encuentra el Jugador con la mayor de Partidas ganadas   |
| void MostrarGanadoresLista (Lista l, int maxGanadas) | Muestra todos los jugadores que tengan “maxGanadas” partidas. |
| int h (long int cedula) | Devuelve el número de cubeta. |
| void Make (Jugadores &j) | Crea un diccionario vacío. |
| boolean Member (Jugadores j, long int cedula) | Determina si en el diccionario existe un elemento con la clave especificada. |
| void Insert (Jugadores &j, Jugador jug) | Inserta un elemento de tipo T en el diccionario.
**Precondición:** el elemento a insertar no es miembro del diccionario. |
| Jugador Find (Jugadores j, long int cedula) | Dada la clave de un elemento devuelve el elemento con dicha clave.
**Precondición:** El jugador existe en el diccionario. |
| void Modify (Jugadores &j, Jugador jug) | Sustituye el viejo elemento de tipo Jugador en el diccionario por el nuevo elemento.
**Precondición:** el elemento a sustituir es miembro del diccionario. |
| void Delete (Jugadores &j, long int cedula) | Dada la clave de un elemento lo borra del diccionario.
**Precondición:** el elemento es miembro del diccionario.  |
| void ListarJugadores (Jugadores j) | Lista todos los jugadores del sistema. |
| void CantJugadoresNacidos (Jugadores j, Fecha f, int &antes, int &durante, int &despues) | Dada una fecha devuelve la cantidad de jugadores que nacieron antes de esa fecha, en esa fecha y después de la misma. |
| boolean HayJugadores (Jugadores j) | Verifica si existe por lo menos un jugador en el sistema  |
| int NumeroSiguiente(Jugadores j) | Obtiene el segundo número de jugador disponible. |
| int ObtenerMayorCantidadGanadas (Jugadores j) | Obtiene la mayor cantidad de partidas ganadas por un jugador en el torneo. |
| void MostrarGanadores(Jugadores j, int maxGanadas) | Muestra a los Jugadores con la mayor partidas ganadas |
| void MostrarGanadores(Jugadores j) |  |
| int CantidadJugadores (Jugadores j) | Devuelve la cantidad de Jugadores |
| boolean CantidadJugadoresValidos(Jugadores j) | Devuelve si la cantidad de Jugadores en valida |
| int CantidadMaximaJugadores() | Devuelve al valor de la constante B, que representa la cantidad de jugadores máxima. |

### Modulo Torneo

Implementa la representación del torneo como un grafo no dirigido, donde los vértices son jugadores y las aristas representan partidas disputadas. Esta abstracción permite resolver eficientemente consultas sobre la conectividad entre jugadores y el estado de completitud del torneo.

| Encabezados | Descripciones |
| --- | --- |
| void InicializarVisitados (boolean visitados []) | Inicializa todos los vértices en FALSE. |
| void Crear (Torneo &t) | Crea un grafo vacío. |
| boolean PerteneceVertice (Torneo t, int v) | Determina si en el grafo existe el vértice especificado. |
| boolean PerteneceArista (Torneo t, int u, int v) | Determina si en el grafo existe la arista especificada. |
| void InsertarVertice (Torneo &t, int v) | Inserta el nuevo vértice al grafo.
**Precondición:** el vértice no pertenece al grafo. |
| void InsertarArista (Torneo &t, int u, int v) | Inserta la nueva arista al grafo.
**Precondición:** la arista no pertenece al grafo y que los vértices pertenezcan al grafo. |
| int GradoVertice (Torneo t, int v) | Devuelve el grado del vértice especificado.
**Precondición:** el vértice pertenece al grafo.  |
| boolean MismaComponenteConexa (Torneo t, int v1,  int v2) | Determina si dos jugadores forman parte de la misma componente conexa. |
| boolean TorneoTerminado (Torneo t) | Determina si todos los jugadores han jugado contra todos. |

### Modulo PartidasJugadas

Mantiene una secuencia ordenada cronológicamente de todas las partidas disputadas en el torneo. Esta estructura es esencial para preservar el orden temporal de los eventos y permitir consultas históricas.

| Encabezados | Descripciones |
| --- | --- |
| void Crear (PartidasJugadas &p) | Crea una secuencia vacía. |
| boolean EsVacia (PartidasJugadas p) | Determina si una secuencia es vacía o no. |
| void InsFront (PartidasJugadas &p, Partida part) | Agrega una partida a la secuencia. |
| Partida Primero (PartidasJugadas p) | Devuelve la primer partida en la secuencia.
**Precondición:** La secuencia no está vacía. |
| void Resto (PartidasJugadas &p) | Devuelve la secuencia sin sin su primer elemento.
**Precondición:** La secuencia no está vacía. |
| int Largo (PartidasJugadas p) | Devuelve el largo de la secuencia. |
| Partida K_esimo (PartidasJugadas p, int k) | Devuelve la partida que ocupa la posición k en la secuencia.
**Precondición:** La secuencia no está vacía. |
| void InsBack (PartidasJugadas &p, Partida part) | Agrega una partida al final de la secuencia. |
| void ListarPartidasJugadas (PartidasJugadas p) | Lista los datos de las partidas. |
| void ListarPartidasPorJugador (PartidasJugadas p, int long cedula) | Lista los datos de las partidas en las que participo un jugador. |
| int DevolverSiguienteNmrPartida (PartidasJugadas p) | Devuelve el siguiente número de partida para insertar. |

### Modulo Sistema

Actúa como la fachada del sistema, coordinando las operaciones entre todos los módulos para proporcionar las funcionalidades de alto nivel requeridas por el usuario. Este módulo implementa la lógica de negocio que integra todas las estructuras de datos y operaciones.

| Encabezados | Descripciones |
| --- | --- |
| void ResgistrarJugador(Jugadores &j, long int cedula) | Ristra un jugador en el sistema. |
| void ListarTodosLosJugadores (Jugadores jug) | Lista en pantalla todos los jugadores que están inscriptos en el Torneo |
| void ListarDatosPorJugador (Jugadores j, PartidasJugadas p, long int cedula); | Dada la cédula de un jugador, listas sus datos y los de las partidas en las que ha participado. |
| void RegistrarPartida (Jugadores &j, PartidasJugadas &p, Torneo &t, long int c1, long int c2) | Registra las partidas entre dos jugadores. |
| void ListarTodasLasPartidas (PartidasJugadas p) | Lista en pantalla todas las partidas jugadas en el Torneo |
| void CantidadJugadoresPorFecha(Jugadores j) | Muestra la cantidad de Jugadores nacidos antes, durante y después de una Fecha  |
| void MismaSubdivision(Torneo t, Jugadores j, long int c1, long int c2) | Saber si 2 Jugadores pertenecen a la misma subdivisión |
| void MostrarTorneoCompleto(Torneo t, Jugadores j) | Determina si el torneo termino y los ganadores del mismo |

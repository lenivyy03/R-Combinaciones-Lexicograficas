# R-Combinaciones-Lexicograficas

Generador de R-Combinaciones en Orden Lexicográfico

Este programa, desarrollado en C++, permite generar todas las r-combinaciones posibles de un conjunto de tamaño n en orden lexicográfico. El usuario introduce los valores de n y r, y el programa realiza lo siguiente:
  - Muestra en pantalla cada combinación generada.
  -Imprime el número total de combinaciones generadas.
  -Calcula el número teórico de combinaciones con la fórmula matemática C(n, r) = n! / (r!(n-r)!).
  -Verifica si el conteo de combinaciones coincide con el número teórico.
  -Genera un archivo .csv con todas las combinaciones y muestra la ruta completa donde se guardó.

*Autor*: Angel David Ortega Felix

Requisitos del sistema:
Sistema operativo: Windows, macOS o Linux.
Compilador de C++ con soporte para el estándar C++17 o superior (por ejemplo: g++, clang++, MSVC).
Editor de texto o IDE (opcional): VSCode, Code::Blocks, CLion, etc.


Instrucciones de compilación y ejecución:
Compilación en terminal (Linux/macOS):
g++ -std=c++17 -o combinaciones combinaciones.cpp

Compilación en Windows (con g++):
g++ -std=c++17 -o combinaciones.exe combinaciones.cpp

Ejecución:
./combinaciones

o en Windows:
combinaciones.exe

Explicación del algoritmo:
El algoritmo utiliza una técnica iterativa para generar todas las combinaciones de tamaño r de un conjunto de n elementos (del 1 al n), en orden lexicográfico.
Se inicializa un arreglo arregloR[] de tamaño r con los primeros valores: {1, 2, ..., r}.
Se imprime y guarda esta combinación.
Se busca la posición m desde el final del arreglo que pueda incrementarse sin exceder n.
Aumenta arregloR[m] y reinicia las posiciones siguientes como consecutivas.
El proceso se repite hasta que no haya más combinaciones posibles.
Esta técnica garantiza que las combinaciones están ordenadas de forma lexicográfica sin necesidad de ordenamientos adicionales.

Orden Lexicográfico: El orden lexicográfico es un tipo de ordenamiento similar al diccionario, donde las combinaciones se comparan elemento por elemento. Por ejemplo, para n = 5 y r = 3, el orden lexicográfico sería:
1 2 3  
1 2 4  
1 2 5  
1 3 4  
1 3 5  
...
3 4 5

El algoritmo asegura este orden al incrementar los elementos del arreglo secuencialmente desde la derecha hacia la izquierda, garantizando que las combinaciones se generen en el orden correcto.


Validación de entrada: 
El programa incluye las siguientes validaciones:
n debe ser mayor a 1.
n no puede superar el tamaño máximo definido (MAX_N = 100).
r debe ser mayor o igual a 0 y menor o igual a n.
Si el usuario introduce letras u otros caracteres, se detecta como entrada inválida y se solicita de nuevo.
Además, si r = 0, el programa detecta el caso especial y muestra que la única combinación posible es el conjunto vacío, sin generar archivo.



Formato de salida:
El archivo .csv generado tiene una línea por cada combinación, con los elementos separados por comas:
"1,2,3"
"1,2,4"
"1,2,5"
...
El archivo se guarda con el siguiente formato de nombre:
combinaciones_n<N>_r<R>.csv
Y al final del programa, se muestra la ruta completa del archivo usando std::filesystem::current_path():

Combinaciones guardadas en el archivo: /ruta/completa/combinaciones_n5_r3.csv


Verificación C(n,r): 
C(n, r) = n! / (r! * (n - r)!)
El programa compara esta cantidad con el número real de combinaciones generadas. Si coinciden, se muestra un mensaje de éxito. Esto permite verificar la correcta implementación del algoritmo.

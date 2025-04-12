#include <iostream>
#include <fstream> 
#include <limits>
#include <filesystem>

using namespace std;

#define MAX_N 100 

void capturarNumero ( int &num, const char solicitud[]);

int main() {
    bool Comparacion = true; 
    int n, r, val_max, m, contador = 0;
    int arregloR[MAX_N]; 

    cout << "COMBINACI\242N LEXICOGR\240FICA" << endl;

    // Analiza si r < n y si n > 1
    do {
        capturarNumero(n, "Introducir tama\244o del arreglo (n): ");
        if (n > MAX_N) 
        {
            cout << "Error: El tama\244o m\240ximo permitido para n es " << MAX_N << "." << endl;
        }
        if (n <= 1) 
        {
            cout << "Error: n tiene que ser mayor a 1." << endl;
        }
    } while (n > MAX_N || n <= 1);

    do {
        capturarNumero(r, "Introducir tama\244o de la combinaci\242n (r): ");
        if (r > n) 
        {
            cout << "Error: r no puede ser mayor que n." << endl;
        }
        if (r < 0) 
        {
            cout << "Error: r debe ser mayor o igual que 0." << endl;
        }
    } while (r > n || r < 0);

    // Si r = 0, imprimir que el único elemento es el vacío y no generar un archivo CSV
    if (r == 0) 
    {
        cout << "El \243nico elemento es el conjunto vac\241o. No se generar\240 un archivo CSV." << endl;
        return 0;
    }

    // Calcular el número teórico de combinaciones
    unsigned long long int combinacionesTeoricas = 1;
    for (int i = 1; i <= r; i++) 
    {
        combinacionesTeoricas = combinacionesTeoricas * (n - i + 1) / i;
    }
    
    // Crear el archivo CSV
    string filename = "combinaciones_n" + to_string(n) + "_r" + to_string(r) + ".csv";
    ofstream file(filename);

    if (!file.is_open()) 
    {
        cout << "Error al crear el archivo " << filename << endl;
        return 1;
    }

    for (int i = 0; i < r; i++)
    {
        arregloR[i] = i + 1;
    }
    
    // Combinaciones lexicográficas
    while (Comparacion) {
        cout << "Combinaci\242n: " << contador + 1 << ": ";
        contador++;
        for (int i = 0; i < r; i++) 
        {
            cout << arregloR[i];
            if (i < r - 1) {
                cout << " "; 
            }
        }
        cout << endl;

        file << "\"";
        for (int i = 0; i < r; i++) 
        {
            file << arregloR[i];
            if (i < r - 1) 
            {
                file << ",";
             }
        }
        file << "\"\n";


        m = r - 1;
        val_max = n;
        while (m >= 0 && arregloR[m] == val_max) 
        {
            m = m - 1;
            val_max = val_max - 1;
        }

        if (m < 0) 
        {
            break;
        }

        arregloR[m] = arregloR[m] + 1;

        for (int j = m + 1; j < r; j++) 
        {
            arregloR[j] = arregloR[j - 1] + 1;
        }
    }

    // Mostrar el número de combinaciones generadas y el número teórico de combinaciones
    cout << "N\243mero de combinaciones generadas: " << contador << endl;
    cout << "N\243mero teorico de combinaciones: " << combinacionesTeoricas << endl;
    file.close(); 
    if (contador == combinacionesTeoricas)
    {
        cout << "El n\243mero de combinaciones generadas coincide con el n\243mero te\242rico." << endl;
    } 
    else 
    {
        cout << "El n\243mero de combinaciones generadas no coincide con el n\243mero te\242rico." << endl;
    }
    
    cout << "Combinaciones guardadas en el archivo: " 
     << std::filesystem::current_path() / filename << endl;

    return 0;
}

/// Función para capturar un número entero y manejar errores de entrada (Si ingresas un carácter en vez de un número)
void capturarNumero ( int &num, const char solicitud[]) {
    std::cout << solicitud;
    std::cin >> num;
    while (std::cin.fail()){
        cout << "Error: Entrada no v\240lida. Por favor, introduce un n\243mero entero." << endl;
        std::cin.clear();
        std ::cin.ignore (std::numeric_limits <int>::max(), '\n');
        std::cout << solicitud;
        std ::cin >> num;
    }
}


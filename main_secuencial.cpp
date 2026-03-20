#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

void fibonacci();
void tablas();

int main()
{
    cout << "Esperando botón..." << endl;

    // Espera evento en GPIO 17
    system("gpiomon -c 0 --num-events=1 --edges=both 17");

    cout << "Botón presionado, iniciando ejecución en paralelo..." << endl;


    auto inicio = high_resolution_clock::now();

    // Ejecución en serie (UN SOLO HILO)
    fibonacci();
    tablas();

    auto fin = high_resolution_clock::now();
    auto tiempo = duration_cast<milliseconds>(fin - inicio);

    cout << "Tiempo total (secuencial): "
         << tiempo.count() << " ms" << endl;

    cout << "Encendiendo LED..." << endl;

    // Enciende LED en GPIO 27
    system("gpioset -c 0 27=1");

    cout << "LED encendido." << endl;
    
    return 0;
}

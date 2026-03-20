#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

// Declaración de funciones (están en otros archivos)
void fibonacci();
void tablas();

int main()
{
    cout << "Esperando botón..." << endl;

    // Espera evento en GPIO 17
    system("gpiomon -c 0 --num-events=1 --edges=both 17");

    cout << "Botón presionado, iniciando ejecución en paralelo..." << endl;

    // Inicio medición
    auto inicio = high_resolution_clock::now();

    // Ejecución en paralelo
    thread t1(fibonacci);
    thread t2(tablas);

    // Esperar a que ambos terminen
    t1.join();
    t2.join();

    // Fin medición
    auto fin = high_resolution_clock::now();
    auto tiempo = duration_cast<milliseconds>(fin - inicio);

    cout << "\nTiempo total (paralelo): "
         << tiempo.count() << " ms" << endl;

    cout << "Encendiendo LED..." << endl;

    // Enciende LED en GPIO 27
    system("gpioset -c 0 27=1");

    cout << "LED encendido." << endl;

    return 0;
}

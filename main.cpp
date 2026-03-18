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

    // Esperar señal en GPIO 17
    while (true)
    {
        int estado = system("gpioget gpiochip0 17");

        if (estado == 0) break;  // botón presionado
    }

    cout << "Inicio!" << endl;

    auto inicio = high_resolution_clock::now();

    // -------- PARALELO --------
    thread t1(fibonacci);
    thread t2(tablas);

    t1.join();
    t2.join();

    auto fin = high_resolution_clock::now();
    auto tiempo = duration_cast<milliseconds>(fin - inicio);

    cout << "Tiempo total: " << tiempo.count() << " ms" << endl;

    // Encender LED en GPIO 27
    system("gpioset gpiochip0 27=1");

    cout << "LED encendido" << endl;

    return 0;
}
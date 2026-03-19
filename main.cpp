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

    // Espera un flanco de bajada en GPIO 17
    // Útil si el botón está normalmente en HIGH y al presionarlo pasa a LOW
    system("gpiomon --num-events=1 --edges=falling gpiochip0 17");

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

    cout << "Encendiendo LED..." << endl;

    // Enciende LED en GPIO 27 y lo mantiene encendido
    system("gpioset --background gpiochip0 27=1");

    cout << "LED encendido" << endl;

    return 0;
}
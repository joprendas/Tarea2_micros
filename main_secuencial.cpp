#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

void fibonacci();
void tablas();

int main()
{
    auto inicio = high_resolution_clock::now();

    // Ejecución en serie (UN SOLO HILO)
    fibonacci();
    tablas();

    auto fin = high_resolution_clock::now();
    auto tiempo = duration_cast<milliseconds>(fin - inicio);

    cout << "Tiempo total (secuencial): "
         << tiempo.count() << " ms" << endl;

    return 0;
}
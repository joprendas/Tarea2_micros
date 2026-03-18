#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono;

void fibonacci();
void tablas();

int main()
{
    auto inicio = high_resolution_clock::now();

    // Ejecución en paralelo
    thread t1(fibonacci);
    thread t2(tablas);

    t1.join();
    t2.join();

    auto fin = high_resolution_clock::now();
    auto tiempo = duration_cast<milliseconds>(fin - inicio);

    cout << "Tiempo total (paralelo): "
         << tiempo.count() << " ms" << endl;

    return 0;
}
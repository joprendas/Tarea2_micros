#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

void fibonacci()
{
    cout << "Iniciando fibonacci..." << endl;

    long long a = 0, b = 1, c;
    for (int i = 0; i < 40; i++)
    {
        cout << "Fib[" << i << "] = " << a << endl;
        c = a + b;
        a = b;
        b = c;

        this_thread::sleep_for(milliseconds(100));
    }

    cout << "Fibonacci terminado." << endl;
}

void tablas()
{
    cout << "Iniciando tablas..." << endl;

    for (int n = 1; n <= 10; n++)
    {
        cout << "\nTabla del " << n << ":" << endl;
        for (int i = 1; i <= 10; i++)
        {
            cout << n << " x " << i << " = " << (n * i) << endl;
            this_thread::sleep_for(milliseconds(50));
        }
    }

    cout << "Tablas terminadas." << endl;
}

int main()
{
    cout << "Esperando botón..." << endl;

    // Espera hasta que el botón genere un evento en GPIO 17
    system("gpiomon -c 0 --num-events=1 --edges=both 17");

    cout << "Botón presionado, iniciando..." << endl;

    auto inicio = high_resolution_clock::now();

    thread t1(fibonacci);
    thread t2(tablas);

    t1.join();
    t2.join();

    auto fin = high_resolution_clock::now();
    auto tiempo = duration_cast<milliseconds>(fin - inicio);

    cout << "\nTiempo total: " << tiempo.count() << " ms" << endl;

    cout << "Encendiendo LED..." << endl;

    // Enciende el LED en GPIO 27
    system("gpioset -c 0 27=1");

    cout << "LED encendido." << endl;

    return 0;
}
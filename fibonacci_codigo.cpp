#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;

void fibonacci()
{
    ofstream archivo("fibonacci.txt");

    long long a = 0, b = 1, siguiente;

    archivo << a << endl;
    this_thread::sleep_for(chrono::milliseconds(100));

    archivo << b << endl;
    this_thread::sleep_for(chrono::milliseconds(100));

    for(int i = 2; i < 30; i++)
    {
        siguiente = a + b;
        archivo << siguiente << endl;

        a = b;
        b = siguiente;

        this_thread::sleep_for(chrono::milliseconds(100));
    }

    archivo.close();

    cout << "Fibonacci terminado" << endl;
}
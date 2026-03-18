#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;

void tablas() 
{
    ofstream archivo("tablas.txt");

    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            archivo << i << " x " << j << " = " << i*j << endl;

            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }

    archivo.close();

    cout << "Tablas terminado" << endl;
}
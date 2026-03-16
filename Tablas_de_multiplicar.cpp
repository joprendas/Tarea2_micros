#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    for (int i = 1; i <= 10; i++) {
        cout << "Tabla del " << i << ":\n";

        for (int j = 1; j <= 10; j++) {
            cout << i << " * " << j << " = " << i * j << endl;

            this_thread::sleep_for(chrono::milliseconds(100)); // 0,1 segundos
        }

        cout << endl;
    }
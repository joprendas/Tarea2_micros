#include <iostream>
#include <thread>
#include <chrono>
#include <gpiod.h>

using namespace std;
using namespace chrono;

#define CHIP "/dev/gpiochip0"
#define START_LINE 17
#define LED_LINE 27

void fibonacci();
void tablas();

int main()
{
    gpiod_chip *chip = gpiod_chip_open(CHIP);
    if (!chip) {
        cout << "Error abriendo GPIO" << endl;
        return 1;
    }

    // Solicitar líneas
    gpiod_line *start = gpiod_chip_get_line(chip, START_LINE);
    gpiod_line *led = gpiod_chip_get_line(chip, LED_LINE);

    gpiod_line_request_input(start, "start");
    gpiod_line_request_output(led, "led", 0);

    cout << "Esperando botón..." << endl;

    while (gpiod_line_get_value(start) == 0);

    cout << "Inicio!" << endl;

    auto inicio = high_resolution_clock::now();

    thread t1(fibonacci);
    thread t2(tablas);

    t1.join();
    t2.join();

    auto fin = high_resolution_clock::now();
    auto tiempo = duration_cast<milliseconds>(fin - inicio);

    cout << "Tiempo total: " << tiempo.count() << " ms" << endl;

    gpiod_line_set_value(led, 1);

    cout << "LED encendido" << endl;

    gpiod_chip_close(chip);

    return 0;
}
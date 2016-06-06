#include "../include/System.h"
#include <iostream>


int main() {
    int simulation_time, semaphore_time;
    std::cout << "Tempo de simulação desejado em segundos:\n";
    std::cin >> simulation_time;
    std::cout << "Duração do sinal verde do semáforo em segundos:\n";
    std::cin >> semaphore_time;

    System sys{simulation_time, semaphore_time};
    sys.run();

    return 0;
}

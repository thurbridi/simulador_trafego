#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include "structures/ArrayList.hpp"
#include "BaseLane.h"

enum SemaphoreState {
    kNorth,
    kEast,
    kSouth,
    kWest
};

/**
 * @brief      Descreve um semáforo quatro tempos
 */
class Semaphore {
 public:
    /**
     * @brief      Construtor
     *
     * @param[in]  interval  Tempo de troca de sinal para o semáforo (em
     *                       segundos)
     */
    Semaphore(int interval);

    /**
     * @brief      Conecta pistas que vão em direção do semáforo
     *
     * @param      north  Pista ao norte do semáforo
     * @param      east   Pista ao oeste do semáforo
     * @param      south  Pista ao sul do semáforo
     * @param      west   Pista ao oeste do semáforo
     */
    void setLanes(BaseLane *north, BaseLane *east, BaseLane *south, BaseLane *west);

    /**
     * @brief      Troca o sinal do semáforo no sentido horário
     */
    void changeState();

    /**
     * @brief      { function_description }
     *
     * @return     { description_of_the_return_value }
     */
    BaseLane* free_lane();

    /**
     * @brief      Retorna o intervalo de troca de sinal do semáforo
     *
     * @return     Intervalo de troca de sinal (em segundos)
     */
    int interval();

 private:
    int interval_;
    SemaphoreState state_;
    ArrayList<BaseLane*> lane_list_;
};

#endif

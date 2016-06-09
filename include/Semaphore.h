#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include "structures/ArrayList.hpp"
#include "BaseLane.h"

/**
 * @brief      Enumeração para estados do semáforo
 */
enum SemaphoreState {
    kNorth, //! < O semáforo está aberto para a pista norte
    kEast, //! < O semáforo está aberto para a pista leste
    kSouth, //! < O semáforo está aberto para a pista sul
    kWest //! < O semáforo está aberto para a pista oeste
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
     * @brief      Retorna qual a pista que está com o sinal aberto
     *
     * @return     Pista com o sinal aberto
     */
    BaseLane* free_lane();

    /**
     * @brief      Retorna o intervalo de troca de sinal do semáforo
     *
     * @return     Intervalo de troca de sinal (em segundos)
     */
    int interval();

 private:
    int interval_; //! < Tempo de troca de sinal do semáforo (em segundos)

    SemaphoreState state_; //! < Direção em que o sinal está aberto

    ArrayList<BaseLane*> lane_list_; //! < Lista de pistas que vão em direção do
                                     //! semáforo
};

#endif

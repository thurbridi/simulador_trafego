#ifndef VEHICLE_H
#define VEHICLE_H

#include "BaseLane.h"

class BaseLane; // forward declaration

/**
 * @brief      Descreve um veículo para a simulação
 */
class Vehicle {
public:
    /**
     * @brief      Construtor
     *
     * @param[in]  size  Tamanho do veículo (em metros)
     */
    Vehicle(int size);

    /**
     * @brief      Construtor
     *
     * @param[in]  size       Tamanho do veículo (em metros)
     * @param      direction  Pista destino do veículo
     */
    Vehicle(int size, BaseLane* direction);

    /**
     * @brief      Retorna o tamanho do veículo
     *
     * @return     Tamanho do veículo (em metros)
     */
    int size() const;

    /**
     * @brief      Retorna a pista destino do veículo
     *
     * @return     Pista destino do veículo
     */
    BaseLane* destination() const;

private:
    int size_;

    BaseLane* destination_;
};

#endif

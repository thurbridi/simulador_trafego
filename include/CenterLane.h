#ifndef CENTER_LANE_H
#define CENTER_LANE_H

#include "NonConsumerLane.h"
#include "Vehicle.h"

/**
 * @brief      Descreve uma pista que não é nem fonte, nem sumidouro
 */
class CenterLane : public NonConsumerLane {
 public:
    using NonConsumerLane::NonConsumerLane;

    /**
     * @brief      Insere um veículo da pista
     *
     * @param[in]  v     Veículo que será inserido
     *
     * @return     True em caso de sucesso ao inserir, false caso contrário
     */
    bool insertVehicle(const Vehicle& v);
};

#endif

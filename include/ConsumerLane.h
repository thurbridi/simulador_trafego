#ifndef CONSUMER_LANE_H
#define CONSUMER_LANE_H

#include "BaseLane.h"
#include "Vehicle.h"

/**
 * @brief      Descreve a pista sumidouro da simulação
 */
class ConsumerLane : public BaseLane {
 public:
    /**
     * @brief      Construtor
     *
     * @param[in]  space        Tamanho da pista (em metros)
     * @param[in]  travel_time  Tempo de percorrimento da pista (em segundos)
     */
    ConsumerLane(int space, int travel_time);

    /**
     * @brief      Destrutor
     */
    ~ConsumerLane();

    /**
     * @brief      Trata da chegada dos veículos ao fim da pista, retirando-os do sistema
     */
    void arrival() override;

    /**
     * @brief      Insere um veículo na pista caso haja espaço disponível
     *
     * @param[in]  v     Veículo que será inserido
     *
     * @return     Retorna true se inseriu com sucesso, false caso contrário
     */
    bool insertVehicle(const Vehicle& v);

    /**
     * @brief      Retorna o número de veículos que sairam dessa pista
     *
     * @return     Número de carros que já sairam da pista
     */
    int exited() const;

    /**
     * @brief      Retorna o número de carros que estão atualmente na pista
     *
     * @return     Número de carros atualmente na pista
     */
    int size() const override;

 private:
    int exited_; //! < Total de carros que sairam da pista
};

#endif

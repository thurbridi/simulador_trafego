#ifndef SOURCE_LANE_H
#define SOURCE_LANE_H

#include "NonConsumerLane.h"


/**
 * @brief      Descreve a pista fonte na simulação
 */
class SourceLane : public NonConsumerLane {
 public:
     /**
      * @brief      Construtor
      *
      * @param[in]  space           Tamanho da pista (em metros)
      * @param[in]  travel_time     Tempo de percorrimento (em segundos)
      * @param[in]  base_frequency  Frequência base de chegada (criação) de
      *                             veículos (em segundos)
      * @param[in]  variation       Variância da frequência base
      */
     SourceLane(int space, int travel_time, int base_frequency, int variation);

     /**
      * @brief      Adiciona um novo veículo na pista caso haja espaço
      *             suficiente
      *
      * @return     True se o carro foi adicionado com sucesso, false caso
      *             contrário
      */
     bool spawnVehicle();

     /**
      * @brief      Gera o intervalo de tempo para a próxima criação de veículo
      *
      * @return     Tempo para a próxima criação de um veículo (em segundos)
      */
     int spawn_interval();

     /**
      * @brief      Retorna o número de veículos que entraram na pista
      *
      * @return     Total de carros que entraram na pista
      */
     int entered() const;

     /**
      * @brief      Retorna o número de veículos que não conseguiram entrar na
      *             pista (pois a pista estava cheia)
      *
      * @return     Total de carros que não conseguiram entrar na pista
      */
     int missed() const;

 private:
     int base_frequency_;
     int variation_;
     int entered_;
     int missed_;
};

#endif

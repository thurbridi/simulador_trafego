#ifndef SOURCE_LANE_H
#define SOURCE_LANE_H

#include "NonConsumerLane.h"


/**
 * @brief      Descreve a pista fonte na simulação
 *
 * @details    Herda de NonConsumerLane pois ela não elimina carros da simulação
 *             quando chegam no final da pista
 */
class SourceLane : public NonConsumerLane {
 public:
     /**
      * @brief      Construtor
      *
      * @param[in]  space           Espaço livre da pista (em metros)
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
      *             pista devido ao congestionamento
      *
      * @return     Total de carros que não conseguiram entrar na pista
      */
     int missed() const;

 private:
     int base_frequency_; //! < Frequencia base de criação de carros
     int variation_;      //! < Variância da frequencia base
     int entered_;        //! < Total de carros que entraram na pista
     int missed_;         //! < Total de carros que não conseguiram entrar na pista
                          //! < devido ao congestionamento
};

#endif

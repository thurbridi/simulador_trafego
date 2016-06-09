#ifndef NON_CONSUMER_LANE_H
#define NON_CONSUMER_LANE_H

#include <random>
#include "structures/ArrayList.hpp"
#include "BaseLane.h"
#include "Vehicle.h"

/**
 * @brief      Enumeração para as direções a se tomar ao fim da pista
 */
enum Direction {
    kFront, //! < Direção da pista em frente
    kLeft, //! < Direção da pista à esquerda
    kRight //! < Direção da pista à direita
};

/**
 * @brief      Descreve um pista que não elimina os veículos da simulação quando
 *             esses chegam ao fim da pista
 */
class NonConsumerLane : public BaseLane {
 public:
     /**
      * @brief      Construtor
      *
      * @param[in]  space        Tamanho da pista (em metros)
      * @param[in]  travel_time  Tempo de percorrimentp
      */
     NonConsumerLane(int space, int travel_time);

     /**
      * @brief      Destrutor
      */
     ~NonConsumerLane();

     /**
      * @brief      Move o veículo da fila de carros que estão chegando para a
      *             fila de carros que já chegaram
      */
     void arrival() override;

     /**
      * @brief      Troca o veículo de pista
      *
      * @return     True se trocou de pista com sucesso, false caso contrário
      */
     bool moveVehicle();

     /**
      * @brief      Atribui a quais pistas esta pista leva
      *
      * @param[in]  front  Pista a frente
      * @param[in]  left   Pista a esquerda
      * @param[in]  right  Pista a direita
      */
     void set_destinations(std::pair<BaseLane*, int> front,
                           std::pair<BaseLane*, int> left,
                           std::pair<BaseLane*, int> right);

     /**
      * @brief      Mostra qual é o primeiro veículo da pista
      *
      * @return     Primeiro veículo da pista
      */
     Vehicle first_vehicle() const;

     /**
      * @brief      Testa se há veículos esperando para trocar de pista
      *
      * @return     True se houverem veículos prontos para trocar de pista,
      *             false caso contrário
      */
     bool ready() const;

     /**
      * @brief      Retorna a quantidade veículos estão na pista
      *
      * @return     Número de veículos na pista
      */
     int size() const override;

 protected:
     /**
      * @brief      Retorna a fila de saída dos veículos
      *
      * @return     Fila de saída
      */
     Queue<Vehicle>& out();

     /**
      * @brief      Gera a pista destino para o veículo
      *
      * @return     Retorna a pista destino para o primeiro veículo da pista
      */
     BaseLane* destination() const;

     /**
      * @brief      Gera um inteiro entre low e high
      *
      * @param[in]  low   Menor valor do intervalo
      * @param[in]  high  Maior valor do intervalo
      *
      * @return     Um inteiro entre o menor e o maior valor
      */
     int generate(int low, int high) const;

     /**
      * @brief      Retorna a fila de saída dos veículos
      *
      * @return     Fila de saída
      */
     const Queue<Vehicle>& out() const;

 private:
    Queue<Vehicle> out_; //! < Fila de carros que estão prontos para trocar de
                         //! pista

    ArrayList<std::pair<BaseLane*,
                        int>> destination_list_; //! < Lista de pares de pistas
                                                 //! associadas com a sua 
                                                 //! probabilidade de tomada
};

#endif

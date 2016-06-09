#ifndef BASE_LANE_H
#define BASE_LANE_H

#include "structures/Queue.hpp"
#include "Vehicle.h"

class Vehicle;    // forward declaration

/**
 * @brief      Classe abstrata para as pistas
 *
 * @details    Essa classe é uma classe abstrata para as pistas da simulação,
 *             utiliza uma fila de veículos
 */
class BaseLane {
 public:
    /**
     * @brief      Construtor
     *
     * @param[in]  space        Tamanho da pista em metros
     * @param[in]  travel_time  Tempo de percorrimento da pista em segundos
     */
    BaseLane(int space, int travel_time);

    /**
     * @brief      Destrutor
     */
    virtual ~BaseLane();

    /**
     * @brief      Método puramente virtual que trata da chegada dos veículos 
     *             ao fim da pista
     */
    virtual void arrival() = 0;

    /**
     * @brief      Insere um veículo na pista caso haja espaço disponível
     *
     * @param[in]  v     Veículo que será inserido
     *
     * @return     Retorna true se inseriu com sucesso, false caso contrário
     */
    virtual bool insertVehicle(const Vehicle& v);

    /**
     * @brief      Decrementa o tamanho da pista (espaço disponível)
     *
     * @param[in]  space  Espaço que será decrementado
     */
    void decrease_space(int space);

    /**
     * @brief      Incrementa o tamanho da pista (espaço disponível)
     *
     * @param[in]  space  Espaço que será incrementado
     */
    void increase_space(int space);

    /**
     * @brief      Retorna o número de veículos na pista atualmente
     *
     * @return     Número de veículos na pista
     */
    virtual int size() const = 0;

    /**
     * @brief      Retorna o espaço disponível da pista
     *
     * @return     Espaço disponívem em metros
     */
    int space() const;

    /**
     * @brief      Retorna o tempo de percorrimento da pista
     *
     * @return     Tempo de percorrimento da pista em segundos
     */
    int travel_time() const;

 protected:
    /**
     * @brief      Retorna a fila de veículos que estão percorrendo a pista
     *
     * @return     Fila de carros que estão percorrendo a pista
     */
    Queue<Vehicle>& in();

    /**
     * @brief      Retorna a fila de veículos que estão percorrendo a pista
     *
     * @return     Fila de carros que estão percorrendo a pista
     */
    const Queue<Vehicle>& in() const;

 private:
    int space_; //! < Tamanho da pista / espaço livre (em metros)

    int travel_time_; //! < Tempo de percorrimento da pista (em segundos)

    Queue<Vehicle> in_; //! < Fila de carros que estão percorrendo a pista
};

#endif

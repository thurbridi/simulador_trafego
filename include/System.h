#ifndef SYSTEM_H
#define SYSTEM_H

#include <fstream>
#include "structures/ArrayList.hpp"
#include "CenterLane.h"
#include "ConsumerLane.h"
#include "EventHandler.h"
#include "SourceLane.h"

/**
 * @brief      Descreve o sistema da simulação
 *
 * @details    Cria as pistas e semáforos e os conectam de acordo. Também contém
 *             o tratador de eventos, inicializando a simulação e gerando o
 *             relatório.
 */
class System {
 public:
    /**
     * @brief      Construtor
     *
     * @param[in]  simulation_time  Tempo total da simulação (em segundos)
     * @param[in]  semaphore_time   Intervalo de troca de sinal dos semáforos
     */
    System(int simulation_time, int semaphore_time);

    /**
     * @brief      Destrutor
     */
    ~System();

    /**
     * @brief      Prepara a simulação
     *
     * @details    Inicializa todas as pistas, realiza as conexões entre elas,
     *             inicializa os semáforos, o tratador de eventos e também cria
     *             os primeiros eventos que darão início à simulação
     */
    void setUp();

    /**
     * @brief      Inicia a simulação, parando quando todos os eventos até o
     *             tempo especificado sejam processados
     */
    void run();

    /**
     * @brief      Gera o relatório com os dados da simulação
     */
    void report();

 private:
   int simulation_time_;
   int semaphore_time_;

    ArrayList<Semaphore*> sem_;
    ArrayList<SourceLane*> source_;
    ArrayList<CenterLane*> center_;
    ArrayList<ConsumerLane*> consumer_;

    EventHandler handler_;
    std::ofstream ost{"log.txt"};
};

#endif

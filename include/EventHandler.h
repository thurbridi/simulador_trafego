#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "structures/List.hpp"
#include "Event.h"
#include "BaseLane.h"
#include "Semaphore.h"
#include "SourceLane.h"

/**
 * @brief      Classe tratadora de eventos
 *
 * @details    Essa classe cuida da execução de cada evento. Recebe um evento
 *             de uma lista ordenada de eventos, o identifica e trata de acordo
 *             com seu tipo e usa suas informações para executá-lo corretamente
 *             e agendar os próximos eventos de acordo com o resultado
 */
class EventHandler {
 public:
    /**
     * @brief      Construtor
     */
    EventHandler();

    /**
     * @brief      Processa o próximo evento na lista
     */
    void processNextEvent();

    /**
     * @brief      Agenda um novo evento, colocando-o na lista
     *
     * @param[in]  e     Evento que será agendado
     */
    void schedule(Event e);

    /**
     * @brief      Função que executa as ações de eventos do tipo kSpawnVehicle
     *
     * @param      lane  Pista alvo do evento
     *
     * @details    Essa função trata da execução de eventos que criam veículos
     *             em pistas fonte
     */
    void spawnVehicle(SourceLane* lane);

    /**
     * @brief      Função que executa as ações de eventos do tipo kArrival
     *
     * @param      lane  Pista alvo do evento
     *
     * @details    Essa função trata da execução de eventos de avisam da chegada
     *             de veículos no fim da pista
     */
    void arrival(BaseLane* lane) const;

    /**
     * @brief      Função que executa as ações de eventos do tipo kChangeLane
     *
     * @param      sem   Semáforo alvo do evento
     *
     * @details    Essa função trata da execução de eventos de troca de pista em
     *             um cruzamento
     */
    void changeLane(Semaphore* sem);

    /**
     * @brief      Função que executa as ações de eventos do tipo
     *             kChangeSemaphore
     *
     * @param      semaphore  Semáforo alvo do evento
     *
     * @details    Essa função trata da execução de eventos que trocam a pista
     *             aberta de um determinado semáforo
     */
    void changeSemaphore(Semaphore* semaphore);

    /**
     * @brief      Retorna o tempo atual da simulação
     *
     * @return     Tempo atual da simulação (em segundos)
     */
    int current_time() const;

    /**
     * @brief      Retorna o próximo evento da lista
     *
     * @return     Primeiro evento em ordem da lista de eventos
     */
    Event next_event() const;

 private:
    List<Event> event_list_; //! < Lista de eventos da simulação
    Event current_; //! < Evento atual (sendo processado)
};

#endif

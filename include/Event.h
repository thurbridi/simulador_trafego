#ifndef EVENT_H
#define EVENT_H

enum EventType {
    kChangeSemaphore,
    kChangeLane,
    kArrival,
    kSpawnVehicle
};

/**
 * @brief      Descreve o que é um evento para a simulação
 */
class Event {
 public:
	Event();

    /**
     * @brief      Construtor
     *
     * @param[in]  time    Tempo em que o evento irá ocorrer (em segundos)
     * @param[in]  type    Tipo do evento
     * @param      source  Ponteiro genérico para o objeto em que o evento
     *                     atuará
     */
    Event(int time, EventType type, void* source);

    /**
     * @brief      Retorna o tempo em que o evento ocorrerá
     *
     * @return     Tempo em que o evento ocorrerá (segundos)
     */
    int time() const;

    /**
     * @brief      Retorna o tipo do evento
     *
     * @return     Tipo do evento
     */
    EventType type() const;

    /**
     * @brief      Retorna o ponteiro para o objeto alvo do evento
     *
     * @return     Ponteiro para o objeto alvo
     */
    void* source() const;

    bool operator<(const Event& e) const;

    bool operator<=(const Event& e) const;

 private:
    int time_; //! < Tempo em que o evento irá ocorrer (em segundos)

    EventType type_; //! < Tipo do evento

    void* source_; //! < Objeto em que o evento atuará
};

#endif

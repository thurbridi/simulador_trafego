// Copyright [2016] <Filipe Borba>

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "List.hpp"

/**
 * @brief      Coleção de elementos
 */
template<typename T>
class Queue : protected List<T> {
 public:
    /**
     * @brief      Constrói uma fila vazia (usa o construtor da lista)
     */
    using List<T>::List;

    /**
     * @brief      Libera da memória os dados da fila
     */
    ~Queue() { clear(); }

    /**
     * @brief      Insere um dado no fim da fila
     *
     * @param[in]  value    Valor do dado no início da fila
     */
    void push(const T& value) { List<T>::pushBack(value); }

    /**
     * @brief      Retira o dado no início da fila
     *
     * @return     Dado no início da fila
     */
    T pop() { return List<T>::popFront(); }

    /**
     * @brief      Desaloca todos os elementos da fila
     */
    void clear() { List<T>::clear(); }

    /**
     * @brief      Retorna o primeiro elemento da fila
     *
     * @return     Valor do primeiro elemento da fila
     */
    T front() const { return List<T>::front(); }

    /**
     * @brief      Testa se a fila está vazia
     *
     * @return     True se a fila está vazia, false caso contrário
     */
    bool empty() const { return List<T>::empty(); }

    /**
     * @brief      Retorna a quantidade de elementos na fila
     *
     * @return     Quantidade de elementos na fila
     */
    int size() const { return List<T>::size(); }
};

#endif

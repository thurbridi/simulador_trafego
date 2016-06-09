// Copyright [2016] <Filipe Borba>

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "List.hpp"

/**
 * @brief      Cole��o de elementos
 */
template<typename T>
class Queue : protected List<T> {
 public:
    /**
     * @brief      Constr�i uma fila vazia (usa o construtor da lista)
     */
    using List<T>::List;

    /**
     * @brief      Libera da mem�ria os dados da fila
     */
    ~Queue() { clear(); }

    /**
     * @brief      Insere um dado no fim da fila
     *
     * @param[in]  value    Valor do dado no in�cio da fila
     */
    void push(const T& value) { List<T>::pushBack(value); }

    /**
     * @brief      Retira o dado no in�cio da fila
     *
     * @return     Dado no in�cio da fila
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
     * @brief      Testa se a fila est� vazia
     *
     * @return     True se a fila est� vazia, false caso contr�rio
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

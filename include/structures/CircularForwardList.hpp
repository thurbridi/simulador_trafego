// Copyright [2016] <Filipe Borba>

#ifndef CIRCULAR_FORWARD_LIST_HPP
#define CIRCULAR_FORWARD_LIST_HPP

#include "ForwardList.hpp"

/**
 * @brief      Coleção de elementos
 */
template<typename T>
class CircularForwardList : public ForwardList<T> {
 public:
    /**
     * @brief      Inicializa uma lista circular vazia
     */
    CircularForwardList() : ForwardList<T>::ForwardList{} {
        head()->set_next(head());
    }

    /**
     * @brief      Libera da memória os dados da lista
     */
    ~CircularForwardList() { clear(); }
};

#endif

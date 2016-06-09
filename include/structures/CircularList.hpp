// Copyright [2016] <Filipe Borba>

#ifndef CIRCULAR_LIST_HPP
#define CIRCULAR_LIST_HPP

#include "List.hpp"

/**
 * @brief      Coleção de elementos
 */
template<typename T>
class CircularList : public List<T> {
 public:
    /**
     * @brief      Inicializa uma lista circular vazia
     */
     CircularList() : List::List{} {
        head()->set_prev(head());
        head()->set_next(head());
    }
    
    /**
     * @brief      Libera da memória os dados da lista
     */
    ~CircularList() { clear(); }
};

#endif

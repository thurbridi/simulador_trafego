// Copyright [2016] <Filipe Borba>

#ifndef STACK_HPP_
#define STACK_HPP_

#include "ForwardList.hpp"


template<typename T>
class Stack : protected ForwardList<T> {
 public:
    using ForwardList<T>::ForwardList;

    ~Stack() { clear(); }

    void push(const T& value) { pushFront(value); }

    T pop() { return popFront(); }

    void clear() { ForwardList<T>::clear(); }

    T top() const { return at(0); }

    bool empty() const { ForwardList<T>::empty(); }

    int size() const { ForwardList<T>::size(); }
};

#endif

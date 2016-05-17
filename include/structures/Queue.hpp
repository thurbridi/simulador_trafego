// Copyright [2016] <Filipe Borba>

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include "List.hpp"


template<typename T>
class Queue : protected List<T> {
 public:
     using List<T>::List;

    ~Queue() { clear(); }

    void push(const T& value) { List<T>::pushBack(value); }

    T pop() { return List<T>::popFront(); }

    void clear() { List<T>::clear(); }

    T front() { return List<T>::front(); }

    bool empty() const { List<T>::empty(); }

    int size() const { List<T>::size(); }
};

#endif

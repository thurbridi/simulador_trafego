// Copyright [2016] <Filipe Borba>

#ifndef CIRCULARFORWARDLIST_HPP_
#define CIRCULARFORWARDLIST_HPP_

#include "ForwardList.hpp"


template<typename T>
class CircularForwardList : public ForwardList<T> {
 public:
    CircularForwardList() : ForwardList<T>::ForwardList{} {
        head()->set_next(head());
    }

    ~CircularForwardList() { clear(); }
};

#endif

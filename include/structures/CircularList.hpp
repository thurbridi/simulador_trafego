// Copyright [2016] <Filipe Borba>

#ifndef CIRCULARLIST_HPP_
#define CIRCULARLIST_HPP_

#include "List.hpp"


template<typename T>
class CircularList : public List<T> {
 public:
     CircularList() : List::List{} {
        head()->set_prev(head());
        head()->set_next(head());
    }

    ~CircularList() { clear(); }
};

#endif

// Copyright [2016] <Filipe Borba>

#ifndef FORWARDLIST_HPP_
#define FORWARDLIST_HPP_

#include "ForwardLink.hpp"


template<typename T>
class ForwardList {
 public:
    ForwardList() : head_{new ForwardLink<T>{}}, size_{0} {}

    ~ForwardList() { clear(); }

    void pushFront(const T& value) { insertAfter(head(), value); }

    T popFront() {
        if (empty()) {
            throw Empty{};
        }
        return eraseAfter(head());
    }

    void pushBack(const T& value) { insert(size(), value); }

    T popBack() {
        if (empty()) {
            throw Empty{};
        }
        return erase(size() - 1);
    }

    void insert(int position, const T& value) {
        if (position < 0 || size() < position) {
            throw OutOfRange{};
        }
        ForwardLink<T>* it = head();
        for (int i = 0; i < position; ++i) {
            it = it->next();
        }
        insertAfter(it, value);
    }

    T erase(int position) {
        if (position < 0 || size() <= position) {
            throw OutOfRange{};
        }
        ForwardLink<T>* it = head();
        for (int i = 0; i < position; ++i) {
            it = it->next();
        }
        return eraseAfter(it);
    }

    void insert(const T& value) {
        ForwardLink<T>* it = head();
        int pos = 0;
        while (pos < size() && it->next()->data() < value) {
            it = it->next();
            ++pos;
        }
        insertAfter(it, value);
    }

    void clear() {
        while (!empty()) {
            popFront();
        }
    }

    T at(int position) const {
        if (position < 0 || size_ <= position) {
            throw OutOfRange{};
        }
        ForwardLink<T>* it = head()->next();
        for (int i = 0; i < position; ++i) {
            it = it->next();
        }
        return it->data();
    }

    int position(const T& value) const {
        ForwardLink<T>* it = head()->next();
        for (int i = 0; i < size(); ++i) {
            if (it->data() == value) {
                return i;
            }
            it = it->next();
        }
        throw OutOfRange{};
    }

    bool empty() const { return size_ == 0; }

    int size() const { return size_; }

    class Empty{};
    class OutOfRange {};

 protected:
    void insertAfter(ForwardLink<T>* position, const T& value) {
        position->set_next(new ForwardLink<T>{value, position->next()});
        ++size_;
    }

    T eraseAfter(ForwardLink<T>* position) {
        ForwardLink<T>* tmp = position->next();
        position->set_next(tmp->next());
        --size_;
        T value = tmp->data();
        delete tmp;
        return value;
    }

    ForwardLink<T>* find(const T& value) const {
        ForwardLink<T>* it = head()->next();
        for (int i = 0; i < size(); ++i) {
            if (it->data() == value) {
                return it;
            }
            it = it->next();
        }
        return nullptr;
    }

    ForwardLink<T>* head() const { return head_; }

 private:
    ForwardLink<T>* head_;
    int size_;
};

#endif

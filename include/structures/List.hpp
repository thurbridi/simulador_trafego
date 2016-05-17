// Copyright [2016] <Filipe Borba>

#ifndef LIST_HPP_
#define LIST_HPP_

#include "Link.hpp"


template<typename T>
class List {
 public:
    List() : head_{new Link<T>{}}, tail_{head_}, size_{0} {}

    ~List() { clear(); }

    void pushFront(const T& value) { insertAfter(head(), value); }

    T popFront() {
        if (empty()) {
            throw Empty{};
        }
        return erase(head()->next());
    }

    void pushBack(const T& value) { insertAfter(tail(), value); }

    T popBack() {
        if (empty()) {
            throw Empty{};
        }
        return erase(tail());
    }

    void insert(int position, const T& value) {
        if (position < 0 || size() < position) {
            throw OutOfRange{};
        }
        Link<T>* it = head();
        for (int i = 0; i < position; ++i) {
            it = it->next();
        }
        insertAfter(it, value);
    }

    void insert(const T& value) {
        Link<T>* it = head();
        int pos = 0;
        while (pos < size() && it->next()->data() <= value) {
            it = it->next();
            ++pos;
        }
        insertAfter(it, value);
    }

    T erase(int position) {
        if (position < 0 || size() <= position) {
            throw OutOfRange{};
        }
        Link<T>* it = head()->next();
        for (int i = 0; i < position; ++i) {
            it = it->next();
        }
        return erase(it);
    }

    void clear() {
        while (!empty()) {
            popFront();
        }
    }

    T at(int position) const {
        if (position < 0 || size() <= position) {
            throw OutOfRange{};
        }
        Link<T>* it = head()->next();
        for (int i = 0; i < position; ++i) {
            it = it->next();
        }
        return it->data();
    }

    T front() const {
        if (empty()) {
            throw Empty{};
        }
        return head()->data();
    }

    T back() const {
        if (empty()) {
            throw Empty{};
        }
        return tail()->data();
    }

    int position(const T& value) const {
        Link<T>* it = head()->next();
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

    class Empty {};
    class OutOfRange {};

 protected:
    void insertAfter(Link<T>* position, const T& value) {
        Link<T>* link = new Link<T>{value, position, position->next()};
        position->set_next(link);
        if (link->next()) {
            link->next()->set_prev(link);
        }
        if (position == tail_) {
            tail_ = tail_->next();
        }
        ++size_;
    }

    T erase(Link<T>* position) {
        position->prev()->set_next(position->next());
        if (position->next()) {
            position->next()->set_prev(position->prev());
        }
        if (position == tail_) {
            tail_ = tail_->prev();
        }
        --size_;
        T value = position->data();
        delete position;
        return value;
    }

    Link<T>* find(const T& value) const {
        Link<T>* it = head_->next();
        for (int i = 0; i < size_; ++i) {
            if (value == it->data()) {
                return it;
            }
            it = it->next();
        }
        return nullptr;
    }

    Link<T>* head() const { return head_; }

    Link<T>* tail() const { return tail_; }

 private:
    Link<T>* head_;
    Link<T>* tail_;
    int size_;
};

#endif

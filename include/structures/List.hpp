// Copyright [2016] <Filipe Borba>

#ifndef LIST_HPP
#define LIST_HPP

#include "Link.hpp"

/**
 * @brief      Cole��o de elementos
 */
template<typename T>
class List {
 public:
    /**
     * @brief      Constr�i uma lista vazia
     */
    List() : head_{new Link<T>{}}, tail_{head_}, size_{0} {}

    /**
     * @brief      Libera da mem�ria os dados da lista
     */
    ~List() { clear(); }

    /**
     * @brief      Insere um dado no in�cio da lista
     *
     * @param[in]  value     Valor do dado a ser inserido
     */
    void pushFront(const T& value) { insertAfter(head(), value); }

    /**
     * @brief      Retira o dado no in�cio da lista
     *
     * @return     Dado no in�cio da lista
     */
    T popFront() {
        if (empty()) {
            throw Empty{};
        }
        return erase(head()->next());
    }

    /**
     * @brief      Insere um dado no fim da lista
     *
     * @param[in]  value    Valor do dado no in�cio da lista
     */
    void pushBack(const T& value) { insertAfter(tail(), value); }

    /**
     * @brief      Retira o dado no fim da lista
     *
     * @return     Dado no in�cio da lista
     */
    T popBack() {
        if (empty()) {
            throw Empty{};
        }
        return erase(tail());
    }

    /**
     * @brief      Insere um dado em uma posi��o espec�fica da lista
     *
     * @param[in]  position    Posi��o a inserir o dado
     * @param[in]  value       Valor do dado a ser inserido
     */
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

    /**
     * @brief      Insere um dado na lista, em ordem
     *
     * @param[in]  value    Valor do dado a ser inserido
     */
    void insert(const T& value) {
        Link<T>* it = head();
        int pos = 0;
        while (pos < size() && it->next()->data() <= value) {
            it = it->next();
            ++pos;
        }
        insertAfter(it, value);
    }

    /**
     * @brief      Retira um dado de uma posi��o espec�fica da lista
     *
     * @param[in]  position    Posi��o do dado a ser retirado
     *
     * @return     Dado na posi��o escolhida
     */
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

    /**
     * @brief      Desaloca todos os elementos da lista
     */
    void clear() {
        while (!empty()) {
            popFront();
        }
    }

    /**
     * @brief      Retorna o valor do elemento na posi��o desejada
     *
     * @param      position    Posi��o do elemento desejado
     *
     * @return     Valor do elemento na posi��o desejada
     */
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

    /**
     * @brief      Retorna o primeiro elemento da lista
     *
     * @return     Valor do primeiro elemento da lista
     */
    T front() const {
        if (empty()) {
            throw Empty{};
        }
        return head()->next()->data();
    }

    /**
     * @brief      Retorna o �ltimo elemento da lista
     *
     * @return     Valor do �ltimo elemento da lista
     */
    T back() const {
        if (empty()) {
            throw Empty{};
        }
        return tail()->data();
    }

    /**
     * @brief      Posi��o na lista do dado com valor escolhido
     *
     * @param      value    Valor do dado que se deseja saber a posi��o
     *
     * @return     Dado no in�cio da lista
     */
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

    /**
     * @brief      Testa se a lista est� vazia
     *
     * @return     True se a lista est� vazia, false caso contr�rio
     */
    bool empty() const { return size_ == 0; }

    /**
     * @brief      Retorna a quantidade de elementos na lista
     *
     * @return     Quantidade de elementos na lista
     */
    int size() const { return size_; }

    class Empty {}; //! < Erro ao tentar acessar um dado na lista vazia
    class OutOfRange {}; //! < Erro ao tentar acessar uma posi��o inexistente

 protected:
    /**
     * @brief      M�todo interno usado para inserir um dado ap�s um determinado elemento
     *
     * @param      position    Ponteiro para o elemento que se deseja adicionar ap�s
     * @param      value       Valor do dado a ser inserido
     */
    void insertAfter(Link<T>* position, const T& value) {
        Link<T>* link = new Link<T>{value, position, position->next()};
        position->set_next(link);
        if (link->next()) {
            link->next()->set_prev(link);
        } else {
            tail_ = link;
        }
        ++size_;
    }

    /**
     * @brief      M�todo interno usado para retirar um dado
     *
     * @param      position    Ponteiro para o elemento que se deseja retirar
     *
     * @return     Valor do elemento retirado
     */
    T erase(Link<T>* position) {
        position->prev()->set_next(position->next());
        if (position->next()) {
            position->next()->set_prev(position->prev());
        } else {
            tail_ = position->prev();
        }
        --size_;
        T value = position->data();
        delete position;
        return value;
    }

    /**
     * @brief      M�todo interno usado para um elemento com determinado valor
     *
     * @param      value    Valor do elemento o qual se deseja buscar
     *
     * @return     Endere�o na mem�ria do primeiro elemento encontrado com o
     *             valor desejado, nullptr caso contr�rio
     */
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

    /**
     * @brief      Retorna um ponteiro para o primeiro elemento na lista
     *             (sentinela)
     */
    Link<T>* head() const { return head_; }

    /**
     * @brief      Retorna um ponteiro para o �ltimo elemento na lista
     */
    Link<T>* tail() const { return tail_; }

 private:
    Link<T>* head_; //! < Ponteiro para o primeiro elemento da lista (sentinela)
    Link<T>* tail_; //! < Ponteiro para o �ltimo elemento da lista  
    int size_; //! < Quantidade de elementos na lista
};

#endif

// Copyright [2016] <Filipe Borba>

#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

#include "ForwardLink.hpp"

/**
 * @brief      Cole��o de elementos
 */
template<typename T>
class ForwardList {
 public:
    /**
     * @brief      Constr�i uma lista vazia
     */
    ForwardList() : head_{new ForwardLink<T>{}}, size_{0} {}

    /**
     * @brief      Libera da mem�ria os dados da lista
     */
    ~ForwardList() { clear(); }

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
        return eraseAfter(head());
    }

    /**
     * @brief      Insere um dado no fim da lista
     *
     * @param[in]  value    Valor do dado no in�cio da lista
     */
    void pushBack(const T& value) { insert(size(), value); }

    /**
     * @brief      Retira o dado no fim da lista
     *
     * @return     Dado no in�cio da lista
     */
    T popBack() {
        if (empty()) {
            throw Empty{};
        }
        return erase(size() - 1);
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
        ForwardLink<T>* it = head();
        for (int i = 0; i < position; ++i) {
            it = it->next();
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
        ForwardLink<T>* it = head();
        for (int i = 0; i < position; ++i) {
            it = it->next();
        }
        return eraseAfter(it);
    }

    /**
     * @brief      Insere um dado na lista, em ordem
     *
     * @param[in]  value    Valor do dado a ser inserido
     */
    void insert(const T& value) {
        ForwardLink<T>* it = head();
        int pos = 0;
        while (pos < size() && it->next()->data() <= value) {
            it = it->next();
            ++pos;
        }
        insertAfter(it, value);
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
        if (position < 0 || size_ <= position) {
            throw OutOfRange{};
        }
        ForwardLink<T>* it = head()->next();
        for (int i = 0; i < position; ++i) {
            it = it->next();
        }
        return it->data();
    }

    /**
     * @brief      Posi��o na lista do dado com valor escolhido
     *
     * @param      value    Valor do dado que se deseja saber a posi��o
     *
     * @return     Dado no in�cio da lista
     */
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

    class Empty{}; //! < Erro ao tentar acessar um dado na lista vazia
    class OutOfRange {}; //! < Erro ao tentar acessar uma posi��o inexistente

 protected:
    /**
     * @brief      M�todo interno usado para inserir um dado ap�s um determinado elemento
     *
     * @param      position    Ponteiro para o elemento que se deseja adicionar ap�s
     * @param      value       Valor do dado a ser inserido
     */
    void insertAfter(ForwardLink<T>* position, const T& value) {
        position->set_next(new ForwardLink<T>{value, position->next()});
        ++size_;
    }

    /**
     * @brief      M�todo interno usado para retirar um dado ap�s um determinado elemento
     *
     * @param      position    Ponteiro para o elemento anterior ao que se deseja retirar
     *
     * @return     Valor do elemento retirado
     */
    T eraseAfter(ForwardLink<T>* position) {
        ForwardLink<T>* tmp = position->next();
        position->set_next(tmp->next());
        --size_;
        T value = tmp->data();
        delete tmp;
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

    /**
     * @brief      Retorna um ponteiro para o primeiro elemento na lista
     *             (sentinela)
     */
    ForwardLink<T>* head() const { return head_; }

 private:
    ForwardLink<T>* head_; //! < Ponteiro para o primeiro elemento da lista (sentinela)
    int size_; //! < Quantidade de elementos na lista
};

#endif

// Copyright [2016] <Filipe Borba>

#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

#include "ForwardLink.hpp"

/**
 * @brief      Coleção de elementos
 */
template<typename T>
class ForwardList {
 public:
    /**
     * @brief      Constrói uma lista vazia
     */
    ForwardList() : head_{new ForwardLink<T>{}}, size_{0} {}

    /**
     * @brief      Libera da memória os dados da lista
     */
    ~ForwardList() { clear(); }

    /**
     * @brief      Insere um dado no início da lista
     *
     * @param[in]  value     Valor do dado a ser inserido
     */
    void pushFront(const T& value) { insertAfter(head(), value); }

    /**
     * @brief      Retira o dado no início da lista
     *
     * @return     Dado no início da lista
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
     * @param[in]  value    Valor do dado no início da lista
     */
    void pushBack(const T& value) { insert(size(), value); }

    /**
     * @brief      Retira o dado no fim da lista
     *
     * @return     Dado no início da lista
     */
    T popBack() {
        if (empty()) {
            throw Empty{};
        }
        return erase(size() - 1);
    }

    /**
     * @brief      Insere um dado em uma posição específica da lista
     *
     * @param[in]  position    Posição a inserir o dado
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
     * @brief      Retira um dado de uma posição específica da lista
     *
     * @param[in]  position    Posição do dado a ser retirado
     *
     * @return     Dado na posição escolhida
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
     * @brief      Retorna o valor do elemento na posição desejada
     *
     * @param      position    Posição do elemento desejado
     *
     * @return     Valor do elemento na posição desejada
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
     * @brief      Posição na lista do dado com valor escolhido
     *
     * @param      value    Valor do dado que se deseja saber a posição
     *
     * @return     Dado no início da lista
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
     * @brief      Testa se a lista está vazia
     *
     * @return     True se a lista está vazia, false caso contrário
     */
    bool empty() const { return size_ == 0; }

    /**
     * @brief      Retorna a quantidade de elementos na lista
     *
     * @return     Quantidade de elementos na lista
     */
    int size() const { return size_; }

    class Empty{}; //! < Erro ao tentar acessar um dado na lista vazia
    class OutOfRange {}; //! < Erro ao tentar acessar uma posição inexistente

 protected:
    /**
     * @brief      Método interno usado para inserir um dado após um determinado elemento
     *
     * @param      position    Ponteiro para o elemento que se deseja adicionar após
     * @param      value       Valor do dado a ser inserido
     */
    void insertAfter(ForwardLink<T>* position, const T& value) {
        position->set_next(new ForwardLink<T>{value, position->next()});
        ++size_;
    }

    /**
     * @brief      Método interno usado para retirar um dado após um determinado elemento
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
     * @brief      Método interno usado para um elemento com determinado valor
     *
     * @param      value    Valor do elemento o qual se deseja buscar
     *
     * @return     Endereço na memória do primeiro elemento encontrado com o
     *             valor desejado, nullptr caso contrário
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

// Copyright [2016] <Filipe Borba>

#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

/**
 * @brief      Cole��o de elementos
 */
template<typename T>
class ArrayList {
 public:
    /**
     * @brief      Inicializa uma lista vazia com capacidade 100
     */
     ArrayList()
         : data_{new T[kDefaultSize]}, size_{kDefaultSize}, last_{-1}
     {}

    /**
     * @brief      Inicializa uma lista com a capacidade desejada
     *
     * @param[in]  size    Capacidade de armazenamento
     */
    explicit ArrayList(int size) : data_{new T[size]}, size_{size}, last_{-1} {}

    /**
     * @brief      Insere um dado no inicio da lista
     *
     * @param[in]  value    Dado a ser inserido
     */
    void pushFront(const T& value) { insert(0, value); }

    /**
     * @brief      Retira o dado no in�cio da lista
     *
     * @return     Dado no in�cio da lista
     */
	T popFront() { return erase(0); }

    /**
     * @brief      Insere um dado no fim da lista
     *
     * @param[in]      value    Dado a ser inserido
     */
	void pushBack(const T& value) { insert(last_ + 1, value); }
    
    /**
     * @brief      Retira o dado no fim da lista
     *
     * @param[in]  dado     Dado a ser inserido
     */
	T popBack() { return erase(last_); }

    /**
     * @brief      Insere um dado em uma posi��o espec�fica da lista
     *
     * @param[in]  position     Posi��o a inserir o dado
     * @param[in]  value        Dado a ser inserido
     */
	void insert(int position, const T& value) {
        if (full()) {
            throw Full{};
        }
        if (position < 0 || last_ + 1 < position) {
            throw OutOfRange{};
        }
        ++last_;
        for (int i = last_; i > position; --i) {
            data_[i] = data_[i-1];
        }
        data_[position] = value;
    }

    /**
     * @brief      Insere um dado na lista em ordem
     *
     * @param[in]  value    Dado a ser inserido
     */
	void insert(const T& value) {
        if (full()) {
            throw Full{};
        }
        int pos = 0;
        while (pos <= last_ && data_[pos] <= value) {
            ++pos;
        }
        insert(pos, value);
    }

    /**
     * @brief      Retira dado de uma posi��o espec�fica da lista
     *
     * @param[in]  position     Posicao do dado a ser retirado
     *
     * @return     Dado na posi��o escolhida
     */
	T erase(int position) {
        if (empty()) {
            throw Empty{};
        }
        if (position < 0 || last_ + 1 < position) {
            throw OutOfRange{};
        }
        T value = data_[position];
        --last_;
        for (int i = position; i <= last_; ++i) {
            data_[i] = data_[i+1];
        }
        return value;
    }

    /**
     * @brief      Torna a lista vazia, ignorando elementos existentes
     */
	void clear() { last_ = -1;}

    /**
     * @brief      Retorna dado na posi��o escolhida, sem retir�-lo
     *
     * @return     Dado na posi��o escolhida
     */
    T at(int position) const {
        if (position < 0 || size_ <= position) {
            throw OutOfRange{};
        }
        return data_[position];
    }

    /**
     * @brief      Posi��o do dado com valor escolhido na lista
     *
     * @param[in]  value    Valor do dado que se deseja saber a posi��o
     *
     * @return     POsi��o do primeiro dado com o valor desejado
     */
	int position(const T& value) const {
        for (int i = 0; i <= last_; ++i) {
            if (data_[i] == value) {
                return i;
            }
        }
        throw OutOfRange{};
    }

    /**
     * @brief      Retorna a quantidade de elementos na lista
     *
     * @return     Quantidade de elementos na lista
     */
    int size() { return last_ + 1; }

    /**
     * @brief      Testa se a lista est� vazia
     *
     * @return     True se a lista est� vazia, false caso contr�rio
     */
    bool empty() const { return last_ == -1; }

    /**
     * @brief      Testa se a lista est� cheia
     *
     * @return True se a lista est� cheia, false caso contr�rio
     */
	bool full() const { return last_ == size_ - 1; }

    class Empty {}; //! < Erro ao inserir na lista cheia
    class Full {}; //! < Erro ao tentar acessar um dado na fila vazia
    class OutOfRange {}; //! < Erro ao tentar acessar uma posi��o inexistente

 protected:
    enum { kDefaultSize = 100 }; //! < Tamanho padr�o da estrutura

 private:
    T* data_; //! < Ponteiro para posi��o dos dados na mem�ria
    const int size_; //! < Capacidade de armazenamento
    int last_;  //! < Posi��o do �ltimo elemento
};

#endif

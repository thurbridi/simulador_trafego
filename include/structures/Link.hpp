// Copyright [2016] <Filipe Borba>

#ifndef LINK_HPP_
#define LINK_HPP_


//! Link
/*!
    Elemento de uma estrutura de dados duplamente encadeada
*/
template<typename T>
class Link {
 public:
    //! Construtor Padrão
    /*!
        Constroi um elemento vazio
    */
    Link() : data_{nullptr}, prev_{nullptr}, next_{nullptr} {}

    //! Construtor
    /*!
        Inicializa um elemento
        \param data Valor do conteúdo do elemento
        \param next Ponteiro para o próximo elemento
    */
	Link(const T& data,
	     Link<T>* prev = nullptr,
	     Link<T>* next = nullptr)
	     : data_{new T{data}}, prev_ {prev}, next_{next}
    {}

    //! Destrutor
    /*!
        Desaloca o conteúdo do elemento
    */
    ~Link() { delete data_; }

    /*
        Retorna conteúdo do elemento
        \return Conteúdo do elemento
    */
    T data() const { return *data_; }

    /*
        Retorna o endereço na memória do conteúdo do elemento
        \return Endereço de memória do conteúdo elemento se existir, nullptr 
        caso contrário
    */
    T* ref_data() { return data_; }

    /*!
        Retorna um ponteiro para o elemento anterior
        \return Ponteiro para o elemento anterior
    */
    Link* prev() const { return prev_; }

    /*!
        Retorna um ponteiro para o próximo elemento
        \return Ponteiro para o próximo elemento
    */
    Link* next() const { return next_; }

    /*
        Altera o endereço de memória apontado por prev_
        \param next Novo endereço de memória do elemento anterior
    */
    void set_prev(Link* link) { prev_ = link; }

    /*
        Altera o endereço de memória apontado por next_
        \param next Novo endereço de memória do próximo elemento
    */
    void set_next(Link* link) { next_ = link; }

 private:
    T* data_;  /*!< Ponteiro para o conteúdo do elemento */
    Link* prev_;   /*!< Ponteiro para o elemento anterior */
    Link* next_;  /*!< Ponteiro para o próximo elemento */
};

#endif

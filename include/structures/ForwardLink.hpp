// Copyright [2016] <Filipe Borba>

#ifndef FORWARDLINK_HPP_
#define FORWARDLINK_HPP_


//! ForwarLink
/*!
    Elemento de uma estrutura de dados encadeada
*/
template<typename T>
class ForwardLink {
 public:
    //! Construtor Padrão
    /*!
        Constroi um elemento vazio
    */
    ForwardLink() : data_{nullptr}, next_{nullptr} {}

    //! Construtor
    /*!
        Inicializa um elemento
        \param data Valor do conteúdo do elemento
        \param next Ponteiro para o próximo elemento
    */
	explicit ForwardLink(const T& data, ForwardLink<T>* next = nullptr)
        : data_{new T{data}}, next_{next}
    {}

    //! Destrutor
    /*!
        Desaloca o conteúdo do elemento
    */
    ~ForwardLink() { delete data_; }

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
        Retorna um ponteiro para o próximo elemento
        \return Ponteiro para o próximo elemento
    */
	ForwardLink* next() const { return next_; }

    /*
        Altera o endereço de memória apontado por next_
        \param next Novo endereço de memória do próximo elemento
    */
	void set_next(ForwardLink<T>* link) { next_ = link;	}

 private:
    T* data_;  /*!< Ponteiro para o conteúdo do elemento */
    ForwardLink* next_;  /*!< Ponteiro para o próximo elemento */
};

#endif

// Copyright 2016 Arthur Bridi Guazzelli

#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

/**
 * @brief      Elemento usado para estruturas de dados encadeadas.
 *
 * @tparam     T     Tipo do dado tratado pela classe.
 */
template<typename T>
class Elemento {
 private:
  T *info;
  Elemento<T>* _next;

 public:
  /**
   * @brief      Contrutor.
   *
   * @param[in]  info  Dado que será guardado pelo elemento.
   * @param      next  Ponteiro para o próximo elemento. Aponta para nullptr
   *                   quando não existe um próximo elemento.
   */
  Elemento(const T &info, Elemento<T> *next) : info(new T(info)), _next(next) {}

  /**
   * @brief      Destrutor.
   */
  ~Elemento() {
    delete info;
  }

  /**
   * @brief      Pega o próximo elemento.
   *
   * @return     Retorna o ponteiro para o próximo elemento.
   */
  Elemento<T>* getProximo() const {
    return _next;
  }

  /**
   * @brief      Pega o dado armazenado no elemento.
   *
   * @return     Retorna o ponteiro para o dado que está armazenado no elemento.
   */
  T getInfo() const {
    return *info;
  }

  /**
   * @brief      Define o valor do  ponteiro para o proximo elemento.
   *
   * @param      next  Ponteiro para o elemento que se deseja apontar como
   *                   próximo.
   */
  void setProximo(Elemento<T>* next) {
    _next = next;
  }
};

#endif

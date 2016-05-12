// Copyright 2016 Arthur Bridi Guazzelli

#include "ListaEnc.hpp"

/**
 * @brief      FilaEnc implementa a estrutura de dados Fila Encadeada de forma
 *             genérica, a partir de uma lista encadeada.
 *
 * @tparam     T     Tipo dos dados que serão tratados pela fila encadeada.
 */
template <typename T>
class FilaEnc : private ListaEnc<T>{
 public:
  /**
   * @brief      Construtor.
   *
   * @details    O construtor da fila encadeada é idêntico ao construtor da
   *             lista encadeada, que, por herança, será chamado.
   */
  FilaEnc<T>() {}

  /**
   * @brief      Destrutor.
   *
   * @details    O destrutor da fila encadeada é idêntico ao destrutor da
   *             lista encadeada, que, por herança, será chamado.
   */
  ~FilaEnc() {}

  /**
   * @brief      Inclui um elemento com o dado especificado no final (último) da
   *             fila.
   *
   * @param[in]  dado  Dado que será incluso.
   */
  void inclui(const T& dado) {
    ListaEnc<T>::adiciona(dado);
  }

  /**
   * @brief      Retira o elemento que está no começo da fila (primeiro) e
   *             retorna o dado nele contido.
   *
   * @return     Dado contido no elemento que está na "frente" da fila.
   */
  T retira() {
    return ListaEnc<T>::retiraDoInicio();
  }

  /**
   * @brief      Retorna o dado guardado no último elemento da fila, sem retirar
   *             o elemento da fila.
   *
   * @return     Dado contido no último elemento da fila.
   */
  T ultimo() {
    return ListaEnc<T>::getUltimo()->getInfo();
  }

  /**
   * @brief      Retorna o dado guardado no primeiro elemento da fila, sem
   *             retirar o elemento da fila.
   *
   * @return     Dado contido no primeiro elemento da fila.
   */
  T primeiro() {
    return ListaEnc<T>::getHead()->getInfo();
  }

  /**
   * @brief      Avalia se a fila está ou não vazia.
   *
   * @return     Retorna true caso a fila esteja vazia, false caso contrário.
   */
  bool filaVazia() {
    return ListaEnc<T>::listaVazia();
  }

  /**
   * @brief      Descarta todos os elementos da fila.
   */
  void limparFila() {
    ListaEnc<T>::destroiLista();
  }
};

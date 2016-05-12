// Copyright 2016 Arthur Bridi Guazzelli

#include "ListaEnc.hpp"

/**
 * @brief      PilhaEnc implementa a estrutura de dados Pilha Encadeada de forma
 *             genérica, a partir de uma lista encadeada.
 *
 * @details    Como essa pilha encadeada é uma especialização da lista
 *             encadeada, o "topo" da pilha é, na realidade, o início da lista.
 *             Essa decisão foi tomada com base na complexidade constante de se
 *             adicionar e retirar elementos do início da lista.
 *
 * @tparam     T     Tipo dos dados que serão tratados pela pilha encadeada.
 */
template<typename T>
class PilhaEnc : private ListaEnc<T> {
 public:
  /**
   * @brief      Construtor.
   *
   * @details    O construtor da pilha encadeada é idêntico ao construtor da
   *             lista encadeada, que, por herança, será chamado.
   */
  PilhaEnc() {}

  /**
   * @brief      Destrutor.
   *
   * @details    O destrutor da pilha encadeada é idêntico ao destrutor da
   *             lista encadeada, que, por herança, será chamado.
   */
  ~PilhaEnc() {}

  /**
   * @brief      Insere um elemento com o dado especificado no topo da pilha.
   *
   * @param[in]  dado  Dado que será inserido.
   */
  void empilha(const T& dado) {
    ListaEnc<T>::adicionaNoInicio(dado);
  }

  /**
   * @brief      Retira o elemento que está no topo da pilha e retorna seu
   *             conteúdo.
   *
   * @details    Caso a pilha esteja vazia, será tacada um exceção.
   *
   * @return     Dado contido no elemento topo da pilha.
   */
  T desempilha() {
    return ListaEnc<T>::retiraDoInicio();
  }

  /**
   * @brief      Retorna o conteúdo do elemento topo sem removê-lo da pilha.
   *
   * @return     Dado contido no elemento topo da pilha.
   */
  T topo() {
    return ListaEnc<T>::getHead()->getInfo();
  }

  /**
   * @brief      Descarta todos os elementos da pilha.
   */
  void limparPilha() {
    return ListaEnc<T>::destroiLista();
  }

  /**
   * @brief      Avalia se a pilha está ou não vazia.
   *
   * @return     Retorna true caso a pilha esteja vazia, false caso contrário.
   */
  bool PilhaVazia() {
    return ListaEnc<T>::listaVazia();
  }
};

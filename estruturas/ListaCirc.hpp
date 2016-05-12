// Copyright 2016 Arthur Bridi Guazzelli

#include "Elemento.hpp"

/**
 * @brief      ListaCirc implementa a estrutura de dados lista encadeada
 *             circular de forma genérica.
 *
 * @tparam     T     Tipo do dato tratado na lista encadeada.
 */
template <typename T>
class ListaCirc {
 private:
  Elemento<T> *head, *tail;
  int size;

 public:
  /**
   * @brief      Construtor.
   */
  ListaCirc() {
    head = nullptr;
    tail = nullptr;
    size = 0;
  }

  /**
   * @brief      Destrutor.
   */
  ~ListaCirc() {
    destroiLista();
  }

  /**
   * @brief      Adiciona o elemento na posição 0 da lista.
   *
   * @param[in]  dado  Dado contido no elemento que será adicionado.
   */
  void adicionaNoInicio(const T& dado) {
    Elemento<T> *novo = new Elemento<T>(dado, head);
    head = novo;
    if (listaVazia()) {
      novo->setProximo(novo);
      tail = novo;
    }
    ++size;
  }

  /**
   * @brief      Adiciona o elemento na posição especificada.
   *
   * @param[in]  dado  Dado contido no elemento que será adicionado.
   * @param[in]  pos   Posição em que o dado será adicionado. Deve estar contido
   *                    no intervalo [0, size].
   */

  void adicionaNaPosicao(const T& dado, int pos) {
    if (pos < 0 || pos > size) {
      throw "ERRO: POSIÇÃO INVÁLIDA";
    }
    if (pos > 0 && pos < size) {
      Elemento<T> *aux = head;
      Elemento<T> *novo = new Elemento<T>(dado, nullptr);
      for (int i = 0; i < pos - 1; ++i) {
        aux = aux->getProximo();
      }
      novo->setProximo(aux->getProximo());
      aux->setProximo(novo);
      ++size;
    } else if (pos == 0) {
      adicionaNoInicio(dado);
    // if (pos == size)
    } else {
      adiciona(dado);
    }
  }

  /**
   * @brief      Adiciona o elemento na última posição da lista.
   *
   * @param[in]  dado  Dado contido no elemento que será adicionado.
   */
  void adiciona(const T& dado) {
    if (listaVazia()) {
      adicionaNoInicio(dado);
    } else {
      Elemento<T> *novo = new Elemento<T>(dado, head);
      Elemento<T> *aux = head;
      for (int i = 0; i < size - 1; ++i) {
        aux = aux->getProximo();
      }
      aux->setProximo(novo);
      tail = novo;
      ++size;
    }
  }

  /**
   * @brief      Adiciona o elemento em ordem crescente dos dados. Assumindo
   *             que a lista já esteja ordenada.
   *
   * @param[in]  dado  Dado contido no elemento que será adicionado.
   */
  void adicionaEmOrdem(const T& dado) {
    Elemento<T> *probe = head;
    for (int i = 0; i < size; ++i) {
      if (dado < probe->getInfo()) {
        adicionaNaPosicao(dado, i);
        return;
      }
    }
    adiciona(dado);
  }

  /**
   * @brief      Retira o primeiro elemento da lista e retorna o dado nele
   *             contido.
   *
   * @return     Dado contido no elemento retirado.
   */
  T retiraDoInicio() {
    if (listaVazia()) {
      throw "ERRO: LISTA VAZIA";
    } else {
      Elemento<T> *retiraElemento = head;
      head = head->getProximo();
      tail->setProximo(head);
      T dadoRetorno = retiraElemento->getInfo();
      delete retiraElemento;
      --size;
      return dadoRetorno;
    }
  }

  /**
   * @brief      Retira o elemento da posição especificada e retorna o dado nele
   *             contido.
   *
   * @param[in]  pos   Posição do elemento que será retirado. Deve estar contida
   *                    no intervalo [0, size-1].
   *
   * @return     Dado contido no elemento retirado.
   */
  T retiraDaPosicao(int pos) {
    if (pos < 0 || pos > size - 1) {
      throw "ERRO: POSIÇÃO INVÁLIDA";
    }
    if (pos > 0 && pos < size - 1) {
      Elemento<T> *retiraElemento = head->getProximo();
      Elemento<T> *aux = head;
      for (int i = 0; i < pos - 1; ++i) {
        retiraElemento = retiraElemento->getProximo();
        aux = aux->getProximo();
      }
      T dadoRetorno = retiraElemento->getInfo();
      aux->setProximo(retiraElemento->getProximo());
      delete retiraElemento;
      --size;
      return dadoRetorno;
    } else if (pos == 0) {
      return retiraDoInicio();
    // if (pos == size - 1)
    } else {
      return retira();
    }
  }

  /**
   * @brief      Retira o elemento da última posição da lista e retorna o dado
   *             nele contido.
   *
   * @return     Dado contido no elemento retirado.
   */
  T retira() {
    if (listaVazia()) {
      throw "ERRO: LISTA VAZIA";
    } else {
      T dadoRetorno;
      if (size == 1) {
        return retiraDoInicio();
      } else {
        Elemento<T> *aux = head;
        for (int i = 0; i < size - 2; ++i) {
          aux = aux->getProximo();
        }
        tail = aux;
        dadoRetorno = aux->getProximo()->getInfo();
        delete aux->getProximo();
        aux->setProximo(head);
      }
      --size;
      return dadoRetorno;
    }
  }

  /**
   * @brief      Retira o elemento com base no dado nele contido e retorna o
   *             dado.
   *
   * @param[in]  dado  Dado que está no elemento que será retirado.
   *
   * @return     Dado contido no elemento retirado.
   */
  T retiraEspecifico(const T& dado) {
    return retiraDaPosicao(posicao(dado));
  }

  /**
   * @brief      Descarta o primeiro elemento da lista.
   */
  void eliminaDoInicio() {
    if (listaVazia()) {
      throw "ERRO: LISTA VAZIA";
    }
      Elemento<T> *eliminaElemento = head;
      head = head->getProximo();
      delete eliminaElemento;
      --size;
  }

  /**
   * @brief      Busca pela posição do elemento que contém o dado especificado.
   *
   * @param[in]  dado  Dado do elemento que se deseja saber a posição.
   *
   * @return     Posição (índice) do elemento que contém o dado especificado.
   */
  int posicao(const T& dado) const {
    if (listaVazia()) {
      throw "ERRO: LISTA VAZIA";
    } else {
      int posicao = 0;
      Elemento<T> *aux = head;
      while (posicao < size) {
        if (aux->getInfo() == dado) {
          return posicao;
        }
      aux = aux->getProximo();
      ++posicao;
      }
    }
    throw "ERRO: DADO NÃO ENCONTRADO";
  }

  /**
   * @brief      Busca pelo endereço de memória do elemento que contém o dado
   *             especificado.
   *
   * @param[in]  dado  Dado do elemento que se deseja saber o endereço.
   *
   * @return     Endereço de memória do elemento que contém o dado especificado.
   */
  T* posicaoMem(const T& dado) const {
    if (listaVazia()) {
      throw "ERRO: LISTA VAZIA";
    } else {
      int posicao = 0;
      Elemento<T> *aux = head;
      while (posicao < size) {
        if (aux->getInfo() == dado) {
          return aux;
        }
      aux = aux->getProximo();
      ++posicao;
      }
    }
    throw "ERRO: DADO NÃO ENCONTRADO";
  }

  /**
   * @brief      Procura pela lista se existe um elemento com determinado dado.
   *
   * @param[in]  dado  Dado que será usado para realizar a busca.
   *
   * @return     Retorna true caso exista um elemento com o dado especificado,
   *             false caso contrário.
   */
  bool contem(const T& dado) {
    if (listaVazia()) {
      return false;
    } else {
      int posicao = 0;
      Elemento<T> *aux = head;
      while (posicao < size) {
        if (aux->getInfo() == dado) {
          return true;
        }
        aux = aux->getProximo();
        ++posicao;
      }
    }
    return false;
  }

  /**
   * @brief      Mostra o dado guardado no elemento da posição especificada.
   *
   * @param[in]  pos   Índice do elemento.
   *
   * @return     Dado contido no elemento especificado.
   */
  T mostra(int pos) {
    if (pos < 0 || pos > size - 1) {
      throw "ERRO: POSIÇÃO INVÁLIDA";
    }
    Elemento<T> *probe = head;
    for (int i = 0; i < pos; ++i) {
      probe = probe->getProximo();
    }
    return probe->getInfo();
  }

  /**
   * @brief      Retorna o índice do último elemento.
   *
   * @return     Índice do último elemento.
   */
  int verUltimo() {
    return size - 1;
  }

  /**
   * @brief      Avalia se a lista está vazia.
   *
   * @return     Retorna true caso não exista elementos na lista, falso caso
   *             contrário.
   */
  bool listaVazia() const {
    return size == 0;
  }

  /**
   * @brief      Avalia se dois dados são iguais.
   *
   * @param[in]  dado1  Primeiro dado.
   * @param[in]  dado2  Segundo dado.
   *
   * @return     Retorna true caso o primeiro dado seja igual ao segundo dado,
   *             false caso contrário.
   */
  bool igual(T dado1, T dado2) {
    return dado1 == dado2;
  }

  /**
   * @brief      Avalia se um dado é maior que outro.
   *
   * @param[in]  dado1  Primeiro dado.
   * @param[in]  dado2  Segundo dado.
   *
   * @return     Retorna true caso o primeiro dado seja maior que segundo dado,
   *             false caso contrário.
   */
  bool maior(T dado1, T dado2) {
    return dado1 > dado2;
  }

  /**
   * @brief      Avalia se um dado é menor que outro.
   *
   * @param[in]  dado1  Primeiro dado.
   * @param[in]  dado2  Segundo dado.
   *
   * @return     Retorna true caso o primeiro dado seja maior que segundo dado,
   *             false caso contrário.
   */
  bool menor(T dado1, T dado2) {
    return dado1 < dado2;
  }

  /**
   * @brief      Descarta todos os elementos da lista, retornando-a ao seu
   *             estado inicial.
   */
  void destroiLista() {
    while (size != 0) {
      eliminaDoInicio();
    }
  }
};

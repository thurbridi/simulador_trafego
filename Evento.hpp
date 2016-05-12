class Evento {
 private:
  int tempo;


  enum tipo {
    CRIA_CARRO,
    REMOVE_CARRO,
    CHEGADA_NO_SEMAFORO,
    TROCA_SEMAFORO
  };

 public:
  Evento();

  ~Evento();

  int getTempo() {
    return tempo;
  }

  int getTipo() {
    return tipo;
  }
};
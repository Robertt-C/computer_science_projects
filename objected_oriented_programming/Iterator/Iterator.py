from abc import ABC, abstractmethod


class Iterator(ABC):
    @abstractmethod
    def next(self):
        pass

    @abstractmethod
    def has_next(self):
        pass

class Iterator():
  def __init__(self, collection):
    self.collection = collection
    self.index = 0

  def next(self):
    if self.index < len(self.collection):
      item = self.collection[self.index]
      self.index += 1
      return item
    else:
      return None

  def has_next(self):
    return self.index < len(self.collection)


class Figura():
  def __init__(self, nome):
    self.nome = nome

class Quadrado(Figura):
  def __init__(self, lado):
    super().__init__('Quadrado')
    self.lado = lado

class Circulo(Figura):
  def __init__(self, raio):
    super().__init__('Circulo')
    self.raio = raio

class GerenciadorDeFiguras():
  def __init__(self):
    self.figuras = []

  def add(self, figura):
    self.figuras.append(figura)

  def get_iterator(self):
    return Iterator(self.figuras)
  

if __name__ == '__main__':
  gerenciador = GerenciadorDeFiguras()
  gerenciador.add(Quadrado(10))
  gerenciador.add(Circulo(5))
  gerenciador.add(Quadrado(20))

  iterator = gerenciador.get_iterator()
  while iterator.has_next():
    figura = iterator.next()
    if figura.nome == 'Quadrado':
      print(f'Quadrado de lado {figura.lado}')
    else:
      print(f'Circulo de raio {figura.raio}')
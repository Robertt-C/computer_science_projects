from abc import ABC, abstractmethod
import math

class Figura(ABC):

  @abstractmethod
  def factory_method(self):
    pass

  def get_shape(self):
    product = self.factory_method()

    return product
  

class Circulo(Figura):
  def __init__(self, raio) -> None:
    self.raio = raio

  def area(self):
    return 2 * math.pi * math.pow(self.raio)
  
class Quadrado(Figura):
  def __init__(self, lado) -> int:
    self.lado = lado

  def area(self, lado) -> int:
    return lado * lado
  
class TrEquilatero(Figura):
  def __init__(self, lado) -> int:
    self.lado = lado

  def area(self) -> int:
    return math.pow(self.lado) * math.sqrt(3) / 4
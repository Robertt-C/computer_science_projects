from __future__ import annotations
from abc import ABC, abstractmethod
from typing import List




class Observer(ABC):

  @abstractmethod
  def update(self) -> None:
    pass


class Subject():
  def __init__(self) -> None:
    self.observers: Observer = []


  def add(self, observer) -> None:
    self.observers.append(observer)
  
  def remove(self) -> None:
    self.observers.pop()
  
  def notify(self) -> None:
    for observer in self.observers:
      observer.update()


class SubjectPlatformA(Subject):
  def __init__(self) -> None:
    super().__init__()
    self.__temperaturaAmbiente = None


  def setData(self, temperatura) -> None:
    self.__temperaturaAmbiente = temperatura
    self.notify()

  def getData(self) -> None:
    return self.__temperaturaAmbiente


class SubjectPlatformB(Subject):
  def __init__(self) -> None:
    super().__init__()
    self.__pHAguaLocal = None


  def setData(self, phAgua) -> None:
    self.__pHAguaLocal = phAgua
    self.notify()

  def getData(self) -> None:
    return self.__pHAguaLocal


class ObserverUFMG(Observer):
  def __init__(self, subject) -> None:
    self.observes: SubjectPlatformA = subject
    self.dados = None

  
  def update(self) -> None:
    self.dados = self.observes.getData()


class ObserverUnifesp(Observer):
  def __init__(self, subject) -> None:
    self.observes: SubjectPlatformB = subject
    self.dados = None


  def update(self) -> None:
    self.dados = self.observes.getData()




if __name__ == "__main__":

  subject1 = SubjectPlatformA()
  subject2 = SubjectPlatformB()

  observador1 = ObserverUFMG(subject1)
  observador2 = ObserverUnifesp(subject2)

  subject1.add(observador1)
  subject2.add(observador2)


  print(f"Observador 1: {observador1.dados} Observador 2: {observador2.dados}")

  subject1.setData(38)
  subject2.setData(10)

  print(f"Observador 1: {observador1.dados} Observador 2: {observador2.dados}")
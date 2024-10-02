from __future__ import annotations
from abc import ABC, abstractmethod
from typing import List




class Mediator(ABC):

  @abstractmethod
  def notify() -> None:
    pass


class Observer(ABC):

  @abstractmethod
  def update(self) -> None:
    pass


class Subject():
  def __init__(self) -> None:
    self.observers: Observer = []
    self._mediator = None


  def setMediator(self, mediator: Mediator) -> None:
    self._mediator = mediator




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



  
  def notifyMediator(self) -> None:
    self._mediator.notify('A')


class SubjectPlatformB(Subject):
  def __init__(self) -> None:
    super().__init__()
    self.__pHAguaLocal = None


  def setData(self, phAgua) -> None:
    self.__pHAguaLocal = phAgua
    self.notify()

  def getData(self) -> None:
    return self.__pHAguaLocal

  


  def notifyMediator(self) -> None:
    self._mediator.notify('B')



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




class ConcreteMediator(Mediator):
  def __init__(self, subjectPlatformA: SubjectPlatformA, subjectPlatformB: SubjectPlatformB) -> None:
    self._subjectPlatformA =  subjectPlatformA
    self._subjectPlatformB =  subjectPlatformB
    self._subjectPlatformA.setMediator(self)
    self._subjectPlatformB.setMediator(self)


  def notify(self, event: str) -> None:
    if event == 'A':
      self._subjectPlatformA.setData(self._subjectPlatformA.getData() - 1)
    elif event == 'B':
      self._subjectPlatformB.setData(self._subjectPlatformB.getData() - 1)



if __name__ == "__main__":

  subject1 = SubjectPlatformA()
  subject2 = SubjectPlatformB()

  mediator = ConcreteMediator(subject1, subject2)




  print(f"subject 1: {subject1.getData()} subject 2: {subject2.getData()}")

  subject1.setData(10)
  subject2.setData(46)

  print(f"subject 1: {subject1.getData()} subject 2: {subject2.getData()}")

  subject1.notifyMediator()
  subject2.notifyMediator()

  print(f"subject 1: {subject1.getData()} subject 2: {subject2.getData()}")
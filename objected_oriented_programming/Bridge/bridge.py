from __future__ import annotations
from abc import ABC, abstractmethod


class Implementador(ABC):
  
  @abstractmethod
  def dequeue(self):
    pass

  @abstractmethod
  def enqueue(self):
    pass


class Queue:

  def __init__(self, implementador: Implementador) -> None:
    self.implementador = implementador


  def queue(self) -> None:
    pass

  def dequeue(self) -> None:
    pass
  
  def enqueue(self) -> None:
    return print("Implements Queue enqueue")
  
  def isEmpty(self) -> None:
    pass
  
  def size(self) -> int:
    pass


class FIFOqueue(Queue):

  def FIFOdequeue(self):
    return print("Implements FIFO dequeueu")
  
  def FIFOenqueue(self):
    return print("Implements FIFO enqueue")


class QueueA(Implementador):
  def __init__(self) -> None:
    self.queueA = []

  def dequeue(self):
    return print("dequeue QueueA")
  
  def enqueue(self):
    return print("enqueue QueueA")


class QueueB(Implementador):
  def __init__(self) -> None:
    self.queueB = []

  def dequeue(self):
    return print("dequeue QueueB")
  
  def enqueue(self):
    return print("enqueue QueueB")



if __name__ == "__main__":
  queueA = QueueA()

  queue = Queue(queueA)
  fifoQueue = FIFOqueue(queueA)

  queue.enqueue()
  fifoQueue.FIFOenqueue()
from abc import ABC




class Sujeito(ABC):
  pass


class SujeitoReal(Sujeito):
  def operation(self) -> None:
    print("SujeitoReal operation")


class Intermediario(Sujeito):
  def __init__(self, sujeito: SujeitoReal) -> None:
    self._sujeitoReal = sujeito


  def operation(self) -> None:
    self._sujeitoReal.operation()




if __name__ == "__main__":

  sujeitoReal = SujeitoReal()

  clienteProxy = Intermediario(sujeitoReal)

  sujeitoReal.operation()

  clienteProxy.operation()
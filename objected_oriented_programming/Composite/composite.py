""" 
O Congresso é o cliente, o Indivíduo é o indivíduo, a Instituição é o grupo.
"""
from __future__ import annotations
from abc import ABC, abstractmethod
from typing import List


class Componente(ABC):

  def add(self, componente: Componente) -> None:
    pass

  def getFilho(self) -> None:
    pass

  def eComposto(self) -> None:
    pass


class Individuo(Componente):
  def __init__(self, name):
    self.name = name
    self.assento = 0


  def reservaAssento(self) -> None:
    self.assento = 1


  def getAssento(self) -> int:
    return self.assento


  def eComposto(self) -> bool:
    return False


class Instituicao(Componente):
  def __init__(self, nome):
    self.nome = nome
    self.membros: List[Componente] = []
    self.quantidadeMembros = 0
    self.quantidadeAssentosReservados = 0
  

  def addMembros(self, componente: Componente) -> None:
    self.membros.append(componente)

    if componente.eComposto() == False:
      self.quantidadeMembros += 1
      self.quantidadeAssentosReservados += componente.getAssento()
    else:
      self.quantidadeMembros += componente.getQuantidadeMembros()
      self.quantidadeAssentosReservados += componente.getQuantidadeAssentosReservados()


  def getMembros(self) -> None:
    return self.membros

  def getQuantidadeMembros(self) -> int:
    return self.quantidadeMembros

  def getQuantidadeAssentosReservados(self) -> int:
    return self.quantidadeAssentosReservados

  def eComposto(self) -> bool:
    return True


class Congresso():
  def __init__(self):
    self.componente: Componente = None


  def addComponente(self, componente) -> None:
    self.componente = componente


  def totalParticipantes(self) -> int:
   return self.componente.getQuantidadeMembros()


  def totalAssentosReservados(self) -> int:
    return self.componente.getQuantidadeAssentosReservados()




if __name__ == "__main__":
  congresso = Congresso()

  instituicao1 = Instituicao("Unifesp")
  instituicao2 = Instituicao("UFMG")


  membro1 = Individuo("Joao")
  membro2 = Individuo("Pedro")
  membro3 = Individuo("Marcela")
  membro4 = Individuo("Gabriela")

  membro4.reservaAssento()
  membro3.reservaAssento()

  instituicao1.addMembros(membro1)
  instituicao1.addMembros(membro2)
  instituicao2.addMembros(membro3)
  instituicao2.addMembros(membro4)

  instituicao1.addMembros(instituicao2)

  congresso.addComponente(instituicao1)

  print(f"Total de participantes: {congresso.totalParticipantes()}")
  print(f"Total de assentos reservados: {congresso.totalAssentosReservados()}")
  
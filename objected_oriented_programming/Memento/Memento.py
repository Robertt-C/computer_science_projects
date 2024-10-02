from abc import ABC

class OriginatorPlatform():
  def __init__(self, temperature, water_ph) -> None:
    self.temperature = temperature
    self.water_ph = water_ph
    self._memento = None

  
  def set_temperature(self, temperature) -> None:
    self.temperature = temperature
  
  def set_water_ph(self, water_ph) -> None:
    self.water_ph = water_ph

  def create_memento(self) -> Memento:
    return Memento(self.temperature, self.water_ph)
  
  def set_memento(self) -> None:
    self._memento = self.create_memento()


class Memento():
  def __init__(self) -> None:
    self.temperature = None
    self.water_ph = None

  def set_state(self, temperature, water_ph) -> None:
    self.temperature = temperature
    self.water_ph = water_ph

  def get_state(self) -> tuple:
    return (self.temperature, self.water_ph)


class Caretaker():
  def __init__(self, originator) -> None:
    self._originator = originator
    self._mementos = [Memento]

  def backup(self) -> None:
    self._mementos.append(self._originator.create_memento())

  def undo(self) -> None:
    if not len(self._mementos):
      return
    
    memento = self._mementos.pop()

    return memento

if __name__ == "__main__":
  originator = OriginatorPlatform(0, 0)
  caretaker = Caretaker(originator)

  caretaker.backup()

  originator.set_temperature(1)
  originator.set_water_ph(1)

  caretaker.backup()

  originator.set_temperature(2)
  originator.set_water_ph(2)

  caretaker.backup()

  originator.set_temperature(3)
  originator.set_water_ph(3)

  caretaker.backup()

  
  print(caretaker.undo())
  print(caretaker.undo())
  print(caretaker.undo())
  print(caretaker.undo())

from abc import ABC, abstractmethod

class SemaphoreContext():
  def __init__(self, semaphore) -> None:
      self._state = None
      self.change_state(semaphore)

  def change_state(self, state):
      self._state = state
      self._state.context = self


class Semaphore(ABC):
  def __init__(self):
      self._context = None

  @abstractmethod
  def print_colour(self):
    pass


class GreenSemaphore(Semaphore):
  def __init__(self, semaphore_context):
    self._context = semaphore_context
    self._colour = "Green"

  def print_colour(self):
    print(self._colour)
    self._context.change_state(YellowSemaphore())
        

class YellowSemaphore(Semaphore):
  def __init__(self, semaphore_context):
    self._context = semaphore_context
    self._colour = "Yellow"

  def print_colour(self):
    print(self._colour)
    self._context.change_state(RedSemaphore())


class RedSemaphore(Semaphore):
  def __init__(self, semaphore_context):
    self._context = semaphore_context
    self._colour = "Red"

  def print_colour(self):
    print(self._colour)
    self._context.change_state(GreenSemaphore())


if __name__ == "__main__":
  semaphore = SemaphoreContext(GreenSemaphore())
  semaphore.next()
  semaphore.next()
  semaphore.next()
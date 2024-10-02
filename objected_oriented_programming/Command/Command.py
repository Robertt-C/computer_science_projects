from abc import ABC, abstractmethod
from typing import List


class Person:
  def __init__(self, id, name):
    self.id = id
    self.name = name

class Command(ABC):
  @abstractmethod
  def execute(self):
    pass


class New(Command):
  def __init__(self, database: List[Person]) -> None:
    self.database = database

  def execute(self, person):
    print('New command')
    self.database.append(person)
    
class Delete(Command):
  def __init__(self, database: List[Person]) -> None:
    self.database = database

  def execute(self, person):
    print('Delete command')
    self.database.remove(person)

class Get(Command):
  def __init__(self, database: List[Person]) -> None:
    self.database = database

  def execute(self, person):
    print('Get command')
    self.database[person]

class Server():
  def __init__(self, database: List[Person]) -> None:
    self.database = database
    self.commands = dict()

  def insert_commands(self, command_name: str, command: Command):
    self.commands.update({command_name: command})

  def execute_command(self, command: str, person: Person):
    self.commands[command].execute(person)




if __name__ == '__main__':
  database = List[Person]

  server = Server(database)
  server.insert_commands('add', New(database))
  server.insert_commands('remove', Delete(database))
  server.insert_commands('get', Get(database))

  while True:
    command = input('Enter command: ')
    id = input('Enter id: ')
    name = input('Enter name: ')
    person = Person(id, name)

    server.execute_command(command, person)
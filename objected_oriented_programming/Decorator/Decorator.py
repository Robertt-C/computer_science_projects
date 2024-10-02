# Step 1: Create a Simple Object with a Text Attribute
class SimpleText:
    def __init__(self, text):
        self.text = text

    def get_text(self):
        return self.text

# Step 2: Create Decorators
def uppercase_decorator(func):
    def wrapper(*args, **kwargs):
        return func(*args, **kwargs).upper()
    return wrapper

def reverse_decorator(func):
    def wrapper(*args, **kwargs):
        return func(*args, **kwargs)[::-1]
    return wrapper

def html_tag_decorator(func):
    def wrapper(*args, **kwargs):
        return f"<b>{func(*args, **kwargs)}</b>"
    return wrapper

# Step 3: Test Decorators
text_obj = SimpleText("Hello, World!")

# Individual decorators
print(uppercase_decorator(text_obj.get_text)())
print(reverse_decorator(text_obj.get_text)())
print(html_tag_decorator(text_obj.get_text)())

# Cascading decorators
print(html_tag_decorator(reverse_decorator(uppercase_decorator(text_obj.get_text)))())




# Step 1: Define Command Classes
class Command:
    pass

class NullCommand(Command):
    def __str__(self):
        return "NullCommand"

class NewCommand(Command):
    def __init__(self, id, name):
        self.id = id
        self.name = name

    def __str__(self):
        return f"NewCommand(id={self.id}, name={self.name})"

class DeleteCommand(Command):
    def __init__(self, id):
        self.id = id

    def __str__(self):
        return f"DeleteCommand(id={self.id})"

class GetCommand(Command):
    def __init__(self, id):
        self.id = id

    def __str__(self):
        return f"GetCommand(id={self.id})"

class GetAllCommand(Command):
    def __str__(self):
        return "GetAllCommand"

# Step 2: Create a ComandoReader Decorator
class ComandoReader:
    def __init__(self, reader):
        self.reader = reader

    def read(self):
        return self.reader.read()

    def read_comando(self):
        command_str = self.reader.read().strip()
        parts = command_str.split()
        if not parts:
            return NullCommand()
        
        command = parts[0].lower()
        args = parts[1:]

        if command == "new" and len(args) == 2:
            return NewCommand(args[0], args[1])
        elif command == "delete" and len(args) == 1:
            return DeleteCommand(args[0])
        elif command == "get" and len(args) == 1:
            return GetCommand(args[0])
        elif command == "all" and not args:
            return GetAllCommand()
        else:
            return NullCommand()

# Step 3: Test ComandoReader
class StringReader:
    def __init__(self, string):
        self.string = string

    def read(self):
        return self.string

# Test cases
reader = StringReader("new 123 John")
comando_reader = ComandoReader(reader)
command = comando_reader.read_comando()
print(command)  # Output: NewCommand(id=123, name=John)

reader = StringReader("delete 456")
comando_reader = ComandoReader(reader)
command = comando_reader.read_comando()
print(command)  # Output: DeleteCommand(id=456)

reader = StringReader("get 789")
comando_reader = ComandoReader(reader)
command = comando_reader.read_comando()
print(command)  # Output: GetCommand(id=789)

reader = StringReader("all")
comando_reader = ComandoReader(reader)
command = comando_reader.read_comando()
print(command)  # Output: GetAllCommand

reader = StringReader("unknown command")
comando_reader = ComandoReader(reader)
command = comando_reader.read_comando()
print(command)  # Output: NullCommand
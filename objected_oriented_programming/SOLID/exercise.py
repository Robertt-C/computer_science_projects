###--- Contextualização

# Modela-se um sistema bancário simples

from abc import ABC, abstractmethod

class Account(ABC):
    @abstractmethod
    def deposit(self, amount):
        pass
    
    @abstractmethod
    def withdraw(self, amount):
        pass

class CheckingAccount(Account):
    def __init__(self, balance=0):
        self.balance = balance

    def deposit(self, amount):
        self.balance += amount

    def withdraw(self, amount):
        if self.balance >= amount:
            self.balance -= amount
        else:
            print("Insufficient funds")

class SavingsAccount(Account):
    def __init__(self, balance=0):
        self.balance = balance

    def deposit(self, amount):
        self.balance += amount

    def withdraw(self, amount):
        if self.balance >= amount:
            self.balance -= amount
        else:
            print("Insufficient funds")

""" """
class Transaction:
    @staticmethod
    def transfer(from_account, to_account, amount):
        from_account.withdraw(amount)
        to_account.deposit(amount)

# Example usage
if __name__ == "__main__":
    checking_account = CheckingAccount(balance=1000)
    savings_account = SavingsAccount(balance=500)

    print("Before transfer:")
    print("Checking account balance:", checking_account.balance)
    print("Savings account balance:", savings_account.balance)

    Transaction.transfer(checking_account, savings_account, 200)

    print("\nAfter transfer:")
    print("Checking account balance:", checking_account.balance)
    print("Savings account balance:", savings_account.balance)

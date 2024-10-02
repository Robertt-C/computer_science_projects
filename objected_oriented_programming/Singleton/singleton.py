class Cliente:
  def __init__(self, name, id):
    self.name = name
    self.id = id
    self.carrinho = Carrinho()

  def adicionarCarrinho(self, Carrinho):
    carrinho = Carrinho

  def getCarrinho(self):
    return self.carrinho


class Carrinho:
  total = 0
  produtos = []

  def adicionarProduto(self, Produto):
    self.produtos.append(Produto)
    total += Produto.preco
    
  def getTotal(self):
    return self.total


class Produto:
  def __init__(self, nome, id, preco):
    self.nome = nome
    self.id = id
    self.preco = preco

  def getPreco(self):
    return self.preco

class BancoDeDados:
  def __init__(self):
    self.clientes = []
    self.produtos = []

  def adicionaProduto(self, Produto):
    self.produtos.append(Produto)

  def adicionaCliente(self, Cliente):
    self.clientes.append(Cliente)

  def selectCliente(self, id):
    for i in range(len(self.clientes)):
      if self.clientes[i].id == id:
        return self.clientes[i]

  def selectProduto(self, id):
    for i in range(len(self.produtos)):
      if self.produtos[i].id == id:
        return self.produtos[i]


class Facade:
  def __init__(self):
    self.banco = BancoDeDados()
    self.__instancia = None


  def getInstancia(self):
    if self.__instancia == None:
      self.instancia = Facade()
    
    return self.__instancia
    

  def registrar(self, nome, id):
    cliente = Cliente(nome, id)
    carrinho = Carrinho()
    cliente.adicionarCarrinho(carrinho)

  def comprar(self, idProduto, idCliente):
    cliente = self.banco.selectCliente(idCliente)
    produto = self.banco.selectProduto(idProduto)
    cliente.getCarrinho()

  def fecharCompra(self, idCliente):
    cliente = self.banco.selectCliente(idCliente)
    valor = cliente.getCarrinho().getTotal()
    print("processar pagamento")


if __name__ == "__main__":
  """
  produto = Produto("testeNomeProduto", "testeIdProduto", 402)
  cliente = Cliente("testeNomeCliente", "testeIdCliente")

  facade = Facade()

  facade.banco.adicionaProduto(produto)
  facade.banco.adicionaCliente(cliente)

  facade.registrar("testeNomeCliente", "testeIdProduto")
  facade.comprar("testeIdProduto", "testeIdCliente")

  facade.fecharCompra("testeIdCliente")
  """

  ##--- Teste de Singleton
  facade_1 = Facade()
  facade_2 = Facade()
  facade_3 = Facade()

  if id(facade_1) == id(facade_2) & id(facade_2) == id(facade_3):
    print(facade_1, facade_2, facade_3)
  else:
    print("Não Singleton")
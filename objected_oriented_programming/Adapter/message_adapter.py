class INotificador:
  def __init__(self, mensagem, destinatario):
    self.mensagem = mensagem
    self.destinatario = destinatario

  def enviar(mensagem, destinatario):
    print(f"Envia mensagem '{self.mensagem}' para {self.destinatario}")


class NotificadorEmail(INotificador):
  def __init__(self, mensagem, destinatario):
    self.mensagem = mensagem
    self.destinatario = destinatario

  def enviar(self, mensagem, destinatario):
    print(f"Envia mensagem '{self.mensagem}' para {self.destinatario}")


class SMS(INotificador):
  def __init__(self, mensagem, numero):
    self.mensagem = mensagem
    self.numero = numero
   

  def enviarSMS(self):
    print(f"Envia mensagem '{self.mensagem}' para {self.numero}")


class Push(INotificador):
  def __init__(self, mensagem, idDispositivo):
    self.mensagem = mensagem
    self.idDispositivo = idDispositivo
   

  def enviarPush(self):
    print(f"Envia mensagem '{self.mensagem}' para {self.idDispositivo}")




if __name__ == "__main__":
  notificadorEmail = NotificadorEmail("Teste NotificadorEmail", "TesteDestinatario")

  enviaSMS = SMS("Teste AdapterSMS", 40028922)
  enviaSMS.enviarSMS()

  enviaPush = Push("Teste AdapterPush", 42424242)
  enviaPush.enviarPush()

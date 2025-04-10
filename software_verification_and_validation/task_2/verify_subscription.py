###--- Utility classes ---###
class Participant():
  def __init__(self, 
               age: int = 0, 
               proof_time: int = 30,
               term_sign_up: bool = False,
               category: str = None
              ) -> None:
    
    self.age = age
    self.proof_time = proof_time
    self.term_sign_up = term_sign_up
    self.category = category

  
  def set_category(self) -> None:
    if 10 <= self.age <= 14:
      self.category = "Infantile"
      return
    
    if 15 <= self.age <= 17:
      self.category = "Juvenile"
      return
    
    if 18 <= self.age <= 60:
      self.category = "Adult"
      return
    
  
  def set_arbitrary_category(self, 
                             category: str
                            ) -> None:
    
    self.category = category




###--- Utility functions ---###
def verify_sign_up_permission(participant: Participant) -> bool:
  if not verify_age(participant):
    return False
  
  if not verify_category(participant):
    return False
  
  if not verify_proof_time(participant):
    return False
  
  if not verify_term_sign_up(participant):
    return False

  return True


def verify_age(participant: Participant) -> bool:
  if 10 <= participant.age <= 60:
    return True
  
  return False


def verify_category(participant: Participant) -> bool:
  if participant.category not in ["Infantile", "Juvenile", "Adult"]:
    return False
  
  if (10 <= participant.age <= 14) and (participant.category != "Infantile"):
    return False
  
  if (15 <= participant.age <= 17) and (participant.category != "Juvenile"):
    return False
  
  if (18 <= participant.age <= 60) and (participant.category != "Adult"):
    return False
  
  return True


def verify_proof_time(participant: Participant) -> bool:
  if 30 <= participant.proof_time <= 180:
    return True
  
  return False


def verify_term_sign_up(participant: Participant) -> bool:
  if participant.term_sign_up == True:
    return True
  
  return False




if __name__ == "__main__":
  participant = Participant(14, 30, True)
  participant.set_category()

  print(participant.age)
  print(participant.proof_time)
  print(participant.term_sign_up)
  print(participant.category)

  print(verify_sign_up_permission(participant))

  participant.set_arbitrary_category("Teste")

  print(verify_sign_up_permission(participant))
'''
Equivalence partitions

Input conditions                                                 Valid classes            Invalid classes
- Age (A) between 10 and 60, inclusive                           10 <= A <= 60            A > 10 or A > 60 
- Categories,
  - Infantile: age (A) between 10 and 14                         10 <= A <= 14            A < 10 or A > 14
  - Juvenile: age (A) between 15 and 17                          15 <= A <= 17            A < 15 or A > 17
  - Adult: age (A) between 18 and 60                             18 <= A <= 60            A < 18 or A > 60
- proof duration (TD): between 30 and 180 minutes, inclusive     30 <= TD <= 180          TD < 30 or TD > 180  
- sign up the term                                                    Yes                        No
'''

from verify_subscription import Participant
from verify_subscription import verify_sign_up_permission




def test_should_not_accept_age_less_than_10() -> None:
  participant = Participant(age = 9,
                            proof_time = 30,
                            term_sign_up = True)
  
  participant.set_category()


  assert verify_sign_up_permission(participant) == False


def test_should_not_accept_age_greater_than_60() -> None:
  participant = Participant(age = 61,
                            proof_time = 30,
                            term_sign_up = True)
  
  participant.set_category()


  assert verify_sign_up_permission(participant) == False


def test_should_accept_age_between_10_and_60() -> None:
  participant = Participant(age = 35,
                            proof_time = 30,
                            term_sign_up = True)
  
  participant.set_category()


  assert verify_sign_up_permission(participant) == True


def test_should_not_accept_age_between_10_and_14_with_category_different_than_infantile() -> None:
  participant = Participant(age = 9,
                            proof_time = 30,
                            term_sign_up = True,
                            category = "Adult")
  

  assert verify_sign_up_permission(participant) == False


def test_should_not_accept_age_between_15_and_17_with_category_different_than_juvenile() -> None:
  participant = Participant(age = 9,
                            proof_time = 30,
                            term_sign_up = True,
                            category = "Adult")
  

  assert verify_sign_up_permission(participant) == False


def test_should_not_accept_age_between_18_and_60_with_category_different_than_adult() -> None:
  participant = Participant(age = 9,
                            proof_time = 30,
                            term_sign_up = True,
                            category = "Test")
  

  assert verify_sign_up_permission(participant) == False


def test_should_accept_age_between_10_and_14_with_category_infantile() -> None:
  participant = Participant(age = 12,
                            proof_time = 30,
                            term_sign_up = True,
                            category = "Infantile")
  

  assert verify_sign_up_permission(participant) == True


def test_should_accept_age_between_15_and_17_with_category_juvenile() -> None:
  participant = Participant(age = 16,
                            proof_time = 30,
                            term_sign_up = True,
                            category = "Juvenile")
  

  assert verify_sign_up_permission(participant) == True


def test_should_accept_age_between_18_and_60_with_category_adult() -> None:
  participant = Participant(age = 39,
                            proof_time = 30,
                            term_sign_up = True,
                            category = "Adult")
  

  assert verify_sign_up_permission(participant) == True


def test_should_not_accept_proof_time_less_than_30() -> None:
  participant = Participant(age = 35,
                            proof_time = 29,
                            term_sign_up = True)
  
  participant.set_category()


  assert verify_sign_up_permission(participant) == False


def test_should_not_accept_proof_time_greater_than_180() -> None:
  participant = Participant(age = 35,
                            proof_time = 181,
                            term_sign_up = True)
  
  participant.set_category()


  assert verify_sign_up_permission(participant) == False


def test_should_accept_proof_time_between_30_and_180() -> None:
  participant = Participant(age = 35,
                            proof_time = 105,
                            term_sign_up = True)
  
  participant.set_category()


  assert verify_sign_up_permission(participant) == True


def test_should_not_accept_term_sign_up_equals_false() -> None:
  participant = Participant(age = 35,
                            proof_time = 30,
                            term_sign_up = False)
  
  participant.set_category()


  assert verify_sign_up_permission(participant) == False


def test_should_accept_term_sign_up_equals_true() -> None:
  participant = Participant(age = 35,
                            proof_time = 30,
                            term_sign_up = True)
  
  participant.set_category()
  

  assert verify_sign_up_permission(participant) == True
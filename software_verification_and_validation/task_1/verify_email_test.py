from verify_email import verify_email




def test_verify_email():
  email = "eu@gmail.com"

  assert verify_email(email) == True
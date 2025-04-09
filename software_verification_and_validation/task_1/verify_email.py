def verify_email(email: str) -> bool:
  email_prefix: str = None
  email_suffix: str = None
  prefix_suffix: str = None
  suffix_suffix: str = None


  #-- Check if email is empty or full of spaces
  if not email.strip():
    return False

  if not '@' in email:
    return False

  if email.count('@') > 1:
    return False

  email_prefix, email_suffix = email.split('@')
  if not email_prefix.strip():
    return False
  
  if not '.' in email_suffix:
    return False
  
  if email_suffix.count('.') > 1:
    return False
  
  prefix_suffix, suffix_suffix = email_suffix.split('.')
  #-- This check can be enhanced to check the domain name validity
  if not prefix_suffix.strip():
    return False

  #-- This check can be enhanced to check the domain TLD validity
  if not suffix_suffix.strip():
    return False


  return True




if __name__ == "__main__":
  email = "eu@gmail.com"

  print(verify_email(email))
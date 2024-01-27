def min8(password):
  return len(password) >= 8

def containsUpper(password: str):
  for c in password:
    if c.isupper():
      return True
  return False

def containsLower(password: str):
  for c in password:
    if c.islower():
      return True
  return False

def containsNumber(password: str):
  for c in password:
    if c.isnumeric():
      return True
  return False

password = input()

errors = []

if not min8(password):
  errors.append('minimo de 8 caracteres')

if not containsUpper(password):
  errors.append('letra maiuscula')

if not containsLower(password):
  errors.append('letra minuscula')

if not containsNumber(password):
  errors.append('numero')

if len(errors) == 0:
  print('senha valida')
else:
  for error in errors:
    print(error)
import random

def read_string(prompt):
  return input(prompt)

def read_integer(prompt):
  line = read_string(prompt)
  return int(line)
  while not line.isdigit():
    print("Please enter a whole number.")
    line = read_string(prompt)
  return int(line)

def test_user_details():
  name = read_string("What is your name: ")
  if name == "Mom":
    print("What are you doing here?")
  if name == "Cynthia":
    print("Having fun with Python?")
  if name == "Dinesh":
    print("Do you prefer C++ or Python?")
  else:
    print("Hello,", name)

  age = read_integer("What is your age: ")
  print("Awesome, you are", age, "years old.")

def guess_the_number():
  target = random.randrange(1, 100)
  guess = read_integer
  print("I'm thinking of a number between 1 and 100. See if you can guess it!")
  while guess != target:
    guess = read_integer("Guess the number: ")
    if guess < target:
      print("No, the number is greater than", guess)
    elif guess > target:
      print("No, the number is smaller than", guess)
    else:
      print("Wow, you got it! The number was", target)

print("1. Enter user details")
print("2. Guess the number")
print("3. Quit")
option = read_integer("Choose option: ")

while option != 3:
  if option == 1:
    test_user_details()
  if option == 2:
    guess_the_number()
  elif option == 3:
    print("See you soon!")
  else:
    print("Please choose an option from the menu.")

  option = read_integer("Choose option: ")
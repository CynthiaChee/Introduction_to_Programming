from splashkit import *

def read_string(prompt):
    write(prompt)
    result = read_line()
    return result

def read_integer(prompt):
    line = read_string(prompt)
    return int(line)

def test_user_details():
    name = read_string("What is your name: ")
    write_line("Hello, " + name)

test_user_details()
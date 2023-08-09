#Access value 20 from the tuple

user_input = input("Enter a tuple of elements separated by spaces: ")
user_tuple = tuple(user_input.split())

try:
    value_20 = user_tuple[1]
    print("Value at index 1:", value_20)
except IndexError:
    print("The tuple does not have a value at index 1.")



""" Enter a tuple of elements separated by spaces: 20 30 40 50 60 
Value at index 1: 30 """
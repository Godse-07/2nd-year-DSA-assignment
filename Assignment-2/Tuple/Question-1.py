# Reverse the tuple:

def reverse_tuple(tpl):
    return tpl[::-1]

user_input = input("Enter a tuple of elements separated by spaces: ")
user_tuple = tuple(user_input.split())
reversed_tuple = reverse_tuple(user_tuple)
print("Reversed tuple:", reversed_tuple)



""" Enter a tuple of elements separated by spaces: 10 20 30 40 50 60 
Reversed tuple: ('60', '50', '40', '30', '20', '10') """
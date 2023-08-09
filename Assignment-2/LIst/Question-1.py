#Reverse a list in Python

def reverse_list(lst):
    return lst[::-1]

user_input = input("Enter a list of elements separated by spaces: ")
user_list = user_input.split()
reversed_list = reverse_list(user_list)
print("Reversed list:", reversed_list)


""" Enter a list of elements separated by spaces: 10 20 30 
Reversed list: ['30', '20', '10'] """
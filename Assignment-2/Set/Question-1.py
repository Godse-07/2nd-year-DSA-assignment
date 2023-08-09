# Add a list of elements to a set

user_input = input("Enter a list of elements separated by spaces: ")
user_list = user_input.split()
user_set = set(user_list)
print("Set with elements from the list:", user_set)


""" Enter a list of elements separated by spaces: 10 20 3 
Set with elements from the list: {'10', '20', '3'} """
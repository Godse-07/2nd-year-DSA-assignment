#Modify the tuple



user_input = input("Enter a tuple of elements separated by spaces: ")
user_tuple = tuple(user_input.split())

# Converting tuple to list, modifying, and converting back to tuple
modified_list = list(user_tuple)
modified_list[1] = "modified_value"
modified_tuple = tuple(modified_list)

print("Modified tuple:", modified_tuple)



""" Enter a tuple of elements separated by spaces: 1 2 3 4
Modified tuple: ('1', 'modified_value', '3', '4') """
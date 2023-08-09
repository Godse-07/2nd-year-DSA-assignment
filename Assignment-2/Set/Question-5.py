#Remove items from the set at once


user_input = input("Enter a set of elements separated by spaces: ")
user_set = set(user_input.split())

items_to_remove = input("Enter the items to remove separated by spaces: ")
items_to_remove_set = set(items_to_remove.split())

user_set.difference_update(items_to_remove_set)
print("Set after removing items:", user_set)



""" Enter a set of elements separated by spaces: 10 20 30 40 
Enter the items to remove separated by spaces: 20 40 
Set after removing items: {'30', '10'} """
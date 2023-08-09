#Remove all occurrences of a specific item from a list

def remove_all_occurrences(lst, item_to_remove):
    return [item for item in lst if item != item_to_remove]

user_input = input("Enter a list of elements separated by spaces: ")
user_list = user_input.split()

item_to_remove = input("Enter the item you want to remove: ")
filtered_list = remove_all_occurrences(user_list, item_to_remove)
print("List with all occurrences removed:", filtered_list)




""" Enter a list of elements separated by spaces: 10 20 30 40 50 60 
Enter the item you want to remove: 20
List with all occurrences removed: ['10', '30', '40', '50', '60'] """
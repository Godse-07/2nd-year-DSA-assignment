# Replace list’s item with a new value if found

def replace_item_in_list(lst, item_to_replace, new_value):
    if item_to_replace in lst:
        index = lst.index(item_to_replace)
        lst[index] = new_value

user_input = input("Enter a list of elements separated by spaces: ")
user_list = user_input.split()

item_to_replace = input("Enter the item you want to replace: ")
new_value = input("Enter the new value you want to replace with: ")

replace_item_in_list(user_list, item_to_replace, new_value)
print("List after replacement:", user_list)




""" Enter a list of elements separated by spaces: 10 20 30 40 50 60
Enter the item you want to replace: 20
Enter the new value you want to replace with: 100 
List after replacement: ['10', '100', '30', '40', '50', '60'] """
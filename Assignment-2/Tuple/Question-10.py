#Check if all items in the tuple are the same

def are_all_items_same(tpl):
    return all(item == tpl[0] for item in tpl)

user_input = input("Enter a tuple of elements separated by spaces: ")
user_tuple = tuple(user_input.split())

if are_all_items_same(user_tuple):
    print("All items in the tuple are the same.")
else:
    print("Not all items in the tuple are the same.")



""" Enter a tuple of elements separated by spaces: 10 20 30 40 
Not all items in the tuple are the same. """
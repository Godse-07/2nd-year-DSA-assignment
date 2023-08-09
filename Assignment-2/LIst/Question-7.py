#Add new item to the list after a specified item:

def add_item_after_item(lst, item, new_item):
    index = lst.index(item)
    lst.insert(index + 1, new_item)

user_input = input("Enter a list of elements separated by spaces: ")
user_list = user_input.split()

item_to_find = input("Enter the item after which you want to add a new item: ")
new_item = input("Enter the new item you want to add: ")

add_item_after_item(user_list, item_to_find, new_item)
print("List after adding the new item:", user_list)



""" Enter a list of elements separated by spaces: 10 20 30 40
Enter the item after which you want to add a new item: 20
Enter the new item you want to add: 100
List after adding the new item: ['10', '20', '100', '30', '40'] """
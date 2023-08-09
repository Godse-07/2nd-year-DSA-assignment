#Count the number of occurrences of item ‘x’ from a tuple

user_input = input("Enter a tuple of elements separated by spaces: ")
user_tuple = tuple(user_input.split())

item_to_count = input("Enter the item to count occurrences for: ")
count = user_tuple.count(item_to_count)
print(f"Number of occurrences of '{item_to_count}': {count}")




""" Enter a tuple of elements separated by spaces: 10 10 10 10 20 30 
Enter the item to count occurrences for: 10
Number of occurrences of '10': 4 """
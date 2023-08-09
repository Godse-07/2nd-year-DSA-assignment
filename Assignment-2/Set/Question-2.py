#Return a new set of identical items from two sets

user_input1 = input("Enter the first set of elements separated by spaces: ")
user_input2 = input("Enter the second set of elements separated by spaces: ")
set1 = set(user_input1.split())
set2 = set(user_input2.split())

common_items = set1.intersection(set2)
print("Identical items in both sets:", common_items)



""" Enter the first set of elements separated by spaces: 10 20 30 
Enter the second set of elements separated by spaces: 20 80 90 
Identical items in both sets: {'20'} """
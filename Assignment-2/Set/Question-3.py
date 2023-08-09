#Get only unique items from two sets

user_input1 = input("Enter the first set of elements separated by spaces: ")
user_input2 = input("Enter the second set of elements separated by spaces: ")
set1 = set(user_input1.split())
set2 = set(user_input2.split())

unique_items = set1.symmetric_difference(set2)
print("Unique items from both sets:", unique_items)



""" Enter the first set of elements separated by spaces: 10 20 30 40 
Enter the second set of elements separated by spaces: 70 20 30 
Unique items from both sets: {'40', '10', '70'} """
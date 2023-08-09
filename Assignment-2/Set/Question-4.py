#Update the first set with items that don’t exist in the second set

user_input1 = input("Enter the first set of elements separated by spaces: ")
user_input2 = input("Enter the second set of elements separated by spaces: ")
set1 = set(user_input1.split())
set2 = set(user_input2.split())

set1.update(set1.difference(set2))
print("Updated set1:", set1)



""" Enter the first set of elements separated by spaces: 10 20 30 40 50 
Enter the second set of elements separated by spaces: 40 50 30 40 50
Updated set1: {'30', '40', '50', '20', '10'} """
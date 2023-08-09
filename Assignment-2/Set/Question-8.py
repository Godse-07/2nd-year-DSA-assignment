#Update set1 by adding items from set2, except common items

user_input1 = input("Enter the first set of elements separated by spaces: ")
user_input2 = input("Enter the second set of elements separated by spaces: ")
set1 = set(user_input1.split())
set2 = set(user_input2.split())

unique_elements_set2 = set2.difference(set1)
set1.update(unique_elements_set2)
print("Updated set1:", set1)



""" Enter the first set of elements separated by spaces: 10 20 30 40 
Enter the second set of elements separated by spaces: 50 60 70 80
Updated set1: {'50', '60', '80', '40', '10', '20', '70', '30'} """
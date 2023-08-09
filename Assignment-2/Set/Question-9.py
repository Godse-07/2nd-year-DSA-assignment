#Remove items from set1 that are not common to both set1 and set2

user_input1 = input("Enter the first set of elements separated by spaces: ")
user_input2 = input("Enter the second set of elements separated by spaces: ")
set1 = set(user_input1.split())
set2 = set(user_input2.split())

common_elements = set1.intersection(set2)
set1.intersection_update(common_elements)
print("Set1 after removing non-common elements:", set1)



""" Enter the first set of elements separated by spaces: 10 20 30
Enter the second set of elements separated by spaces: 30 40 50
Set1 after removing non-common elements: {'30'} """
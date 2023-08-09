#Check if two sets have any elements in common. If yes, display the common elements

user_input1 = input("Enter the first set of elements separated by spaces: ")
user_input2 = input("Enter the second set of elements separated by spaces: ")
set1 = set(user_input1.split())
set2 = set(user_input2.split())

common_elements = set1.intersection(set2)
if common_elements:
    print("Common elements:", common_elements)
else:
    print("No common elements between the sets.")



""" Enter the first set of elements separated by spaces: 10 20 30 40 50
Enter the second set of elements separated by spaces: 50 60 70 
Common elements: {'50'} """
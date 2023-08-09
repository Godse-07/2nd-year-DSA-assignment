#Return a set of elements present in Set A or B, but not both

user_input1 = input("Enter the first set of elements separated by spaces: ")
user_input2 = input("Enter the second set of elements separated by spaces: ")
set1 = set(user_input1.split())
set2 = set(user_input2.split())

result_set = set1.symmetric_difference(set2)
print("Elements present in either set, but not both:", result_set)



""" Enter the first set of elements separated by spaces: 10 20 30 
Enter the second set of elements separated by spaces: 40 20 10 
Elements present in either set, but not both: {'30', '40'} """
#Swap two tuples in Python


user_input1 = input("Enter the first tuple of elements separated by spaces: ")
user_input2 = input("Enter the second tuple of elements separated by spaces: ")
tuple1 = tuple(user_input1.split())
tuple2 = tuple(user_input2.split())

tuple1, tuple2 = tuple2, tuple1
print("Swapped tuples:")
print("Tuple 1:", tuple1)
print("Tuple 2:", tuple2)



""" Enter the first tuple of elements separated by spaces: 10 20 30 40 
Enter the second tuple of elements separated by spaces: 100 200 300
Swapped tuples:
Tuple 1: ('100', '200', '300')
Tuple 2: ('10', '20', '30', '40') """
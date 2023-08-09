#Iterate both lists simultaneously

user_input1 = input("Enter the first list of elements separated by spaces: ")
user_input2 = input("Enter the second list of elements separated by spaces: ")
list1 = user_input1.split()
list2 = user_input2.split()

print("Iterating both lists simultaneously:")
for item1, item2 in zip(list1, list2):
    print(item1, item2)


""" Enter the first list of elements separated by spaces: 10 20 30 40 50
Enter the second list of elements separated by spaces: 60 70 80 90 100
Iterating both lists simultaneously:
10 60
20 70
30 80
40 90
50 100 """
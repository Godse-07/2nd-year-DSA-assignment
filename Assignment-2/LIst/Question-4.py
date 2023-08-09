""" Concatenate two lists in the following order: """

def concatenate_lists(lst1, lst2):
    return lst1 + lst2

user_input1 = input("Enter the first list of elements separated by spaces: ")
user_input2 = input("Enter the second list of elements separated by spaces: ")
list1 = user_input1.split()
list2 = user_input2.split()
concatenated_list = concatenate_lists(list1, list2)
print("Concatenated list:", concatenated_list)



""" Enter the first list of elements separated by spaces: 1 2 3 4 
Enter the second list of elements separated by spaces: 5 6 7 8
<<<<<<< HEAD
Concatenated list: ['1', '2', '3', '4', '5', '6', '7', '8'] """
=======
Concatenated list: ['1', '2', '3', '4', '5', '6', '7', '8'] """
>>>>>>> 26a1270729412c56599928ae3a23f121c40fb755

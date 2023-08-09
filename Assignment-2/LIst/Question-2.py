#Concatenate two lists index-wise.

def concatenate_lists_index_wise(lst1, lst2):
    return [item1 + item2 for item1, item2 in zip(lst1, lst2)]

user_input1 = input("Enter the first list of elements separated by spaces: ")
user_input2 = input("Enter the second list of elements separated by spaces: ")
list1 = user_input1.split()
list2 = user_input2.split()

if len(list1) != len(list2):
    print("Both lists must have the same length for index-wise concatenation.")
else:
    concatenated_list = concatenate_lists_index_wise(list1, list2)
    print("Concatenated list:", concatenated_list)



""" 
Enter the first list of elements separated by spaces: 10 20 30 40
Enter the second list of elements separated by spaces: 50 60 00 20
Concatenated list: ['1050', '2060', '3000', '4020'] """
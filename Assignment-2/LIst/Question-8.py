#Extend nested list by adding the sublist

def extend_nested_list(lst, sublist):
    lst.extend(sublist)

user_input1 = input("Enter the first list of elements separated by spaces: ")
user_input2 = input("Enter the sublist separated by spaces to be added: ")
list1 = user_input1.split()
sublist = user_input2.split()

extend_nested_list(list1, sublist)
print("Extended list:", list1)




""" Enter the first list of elements separated by spaces: 10 20 30 40 50 60 
Enter the sublist separated by spaces to be added: 100 200
Extended list: ['10', '20', '30', '40', '50', '60', '100', '200'] """
#Remove empty strings from the list of strings:

def remove_empty_strings(lst):
    return [item for item in lst if item != ""]

user_input = input("Enter a list of strings separated by spaces: ")
user_list = user_input.split()
filtered_list = remove_empty_strings(user_list)
print("List with empty strings removed:", filtered_list)

"""
Enter a list of strings separated by spaces: 10 20 30 40 
List with empty strings removed: ['10', '20', '30', '40'] """
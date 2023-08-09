#Merge two Python dictionaries into one

dict1_input = input("Enter the first dictionary in key:value format separated by spaces: ")
dict2_input = input("Enter the second dictionary in key:value format separated by spaces: ")

dict1 = dict(item.split(":") for item in dict1_input.split())
dict2 = dict(item.split(":") for item in dict2_input.split())

merged_dict = {**dict1, **dict2}
print("Merged dictionary:", merged_dict)





""" Enter the first dictionary in key:value format separated by spaces: name:John age:30 city:New York
Enter the second dictionary in key:value format separated by spaces: occupation:Engineer gender:Male age:30
Merged dictionary: {'name': 'John', 'age': '30', 'city': 'New York', 'occupation': 'Engineer', 'gender': 'Male'} """

#Rename a key of a dictionary

user_input = input("Enter a dictionary in key:value format separated by spaces: ")
old_key = input("Enter the old key name: ")
new_key = input("Enter the new key name: ")

given_dict = dict(item.split(":") for item in user_input.split())

if old_key in given_dict:
    given_dict[new_key] = given_dict.pop(old_key)

print("Dictionary after renaming:", given_dict)



""" Enter a dictionary in key:value format separated by spaces: name:John age:30 city:New York occupation:Engineer
Enter the old key name: occupation
Enter the new key name: job
Dictionary after renaming: {'name': 'John', 'age': '30', 'city': 'New York', 'job': 'Engineer'}
 """
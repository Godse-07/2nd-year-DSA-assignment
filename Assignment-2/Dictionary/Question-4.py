#Create a dictionary by extracting the keys from a given dictionary

user_input = input("Enter a dictionary in key:value format separated by spaces: ")
given_dict = dict(item.split(":") for item in user_input.split())

keys_list = list(given_dict.keys())
keys_dict = {key: None for key in keys_list}

print("Dictionary with extracted keys:", keys_dict)



""" Enter a dictionary in key:value format separated by spaces: name:John age:30 city:New York occupation:Engineer
given_dict = {'name': 'John', 'age': '30', 'city': 'New York', 'occupation': 'Engineer'}
keys_dict = {'name': None, 'age': None, 'city': None, 'occupation': None}
Dictionary with extracted keys: {'name': None, 'age': None, 'city': None, 'occupation': None} """

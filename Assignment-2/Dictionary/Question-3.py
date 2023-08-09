#Initialize a dictionary with a default value

from collections import defaultdict

default_value = input("Enter the default value for the dictionary: ")
keys_input = input("Enter a list of keys separated by spaces: ")

keys_list = keys_input.split()
default_dict = defaultdict(lambda: default_value)

for key in keys_list:
    default_dict[key]  # This will initialize all keys with the default value.

print("Initialized dictionary:", dict(default_dict))



""" Enter the default value for the dictionary: 1
Enter a list of keys separated by spaces: 20 30 40 50 
Initialized dictionary: {'20': '1', '30': '1', '40': '1', '50': '1'} """
#Change the value of a key in a nested dictionary


user_input = input("Enter a nested dictionary in key:value format separated by spaces: ")
key_to_change = input("Enter the key for which you want to change the value: ")
new_value = input("Enter the new value: ")

nested_dict = dict(item.split(":") for item in user_input.split())
keys_list = key_to_change.split('.')

# Iterate through the keys to access the inner dictionary
inner_dict = nested_dict
for key in keys_list[:-1]:
    inner_dict = inner_dict.setdefault(key, {})

# Update the value of the specified key
inner_dict[keys_list[-1]] = new_value

print("Nested dictionary after the change:", nested_dict)



"""
Enter a nested dictionary in key:value format separated by spaces: person:{"name:John age:30 city:New York"} employee:{"name:Sarah age:25 city:Chicago"}
Enter the key for which you want to change the value: person.name
Enter the new value: Alex
Nested dictionary after the change: {'person': {'name': 'Alex', 'age': '30', 'city': 'New York'}, 'employee': {'name': 'Sarah', 'age': '25', 'city': 'Chicago'}}
"""
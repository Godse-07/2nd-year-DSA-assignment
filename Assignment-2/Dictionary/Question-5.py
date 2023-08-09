#Delete a list of keys from a dictionary

user_input = input("Enter a dictionary in key:value format separated by spaces: ")
keys_to_delete_input = input("Enter the list of keys to delete separated by spaces: ")

given_dict = dict(item.split(":") for item in user_input.split())
keys_to_delete = keys_to_delete_input.split()

for key in keys_to_delete:
    given_dict.pop(key, None)

print("Dictionary after deletion:", given_dict)



""" Enter a dictionary in key:value format separated by spaces: name:John age:30 city:New York occupation:Engineer
Enter the list of keys to delete separated by spaces: age occupation
Dictionary after deletion: {'name': 'John', 'city': 'New York'} """

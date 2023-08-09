#Check if a value exists in a dictionary

user_input = input("Enter a dictionary in key:value format separated by spaces: ")
value_to_check = input("Enter the value to check in the dictionary: ")

given_dict = dict(item.split(":") for item in user_input.split())

if value_to_check in given_dict.values():
    print("The value exists in the dictionary.")
else:
    print("The value does not exist in the dictionary.")



""" Enter a dictionary in key:value format separated by spaces: name:John age:30 city:New York occupation:Engineer
Enter the value to check in the dictionary: Engineer
The value exists in the dictionary. """

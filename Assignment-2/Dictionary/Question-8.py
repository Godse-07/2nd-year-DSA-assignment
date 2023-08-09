#Get the key of the minimum value from the following dictionary

user_input = input("Enter a dictionary in key:value format separated by spaces: ")
given_dict = dict(item.split(":") for item in user_input.split())

if given_dict:
    min_key = min(given_dict, key=given_dict.get)
    print("Key with minimum value:", min_key)
else:
    print("The dictionary is empty.")


""" 
Enter a dictionary in key:value format separated by spaces: name:John age:30 city:New York occupation:Engineer
Key with minimum value: age
"""

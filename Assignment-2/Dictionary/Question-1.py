#Convert two lists into a dictionary


keys_input = input("Enter a list of keys separated by spaces: ")
values_input = input("Enter a list of values separated by spaces: ")

keys_list = keys_input.split()
values_list = values_input.split()

if len(keys_list) != len(values_list):
    print("Both lists should have the same length to create the dictionary.")
else:
    result_dict = dict(zip(keys_list, values_list))
    print("Resulting dictionary:", result_dict)



""" Enter a list of keys separated by spaces: 10 20 30 40 
Enter a list of values separated by spaces: 100 200 300 400
Resulting dictionary: {'10': '100', '20': '200', '30': '300', '40': '400'} """
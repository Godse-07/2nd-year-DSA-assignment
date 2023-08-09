#Sort a tuple of tuples by the 2nd item

user_input = input("Enter a list of tuples (each tuple contains two elements) separated by spaces: ")
user_list_of_tuples = [tuple(item.split()) for item in user_input.split(',')]

sorted_tuples = sorted(user_list_of_tuples, key=lambda x: x[1])
print("Sorted tuples:", sorted_tuples)




""" Enter a list of tuples (each tuple contains two elements) separated by spaces: 10 20, 30 5, 15 25, 5 30
Sorted tuples: [('30', '5'), ('10', '20'), ('15', '25'), ('5', '30')] """

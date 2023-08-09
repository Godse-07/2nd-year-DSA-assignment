#Turn every item of a list into its square

def square_list_items(lst):
    return [int(item)**2 for item in lst]

user_input = input("Enter a list of elements separated by spaces: ")
user_list = user_input.split()
squared_list = square_list_items(user_list)
print("Squared list:", squared_list)

""" 
Enter a list of elements separated by spaces: 10 20 30 
Squared list: [100, 400, 900] """
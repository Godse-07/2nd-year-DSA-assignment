#Copy specific elements from one tuple to a new tuple

user_input = input("Enter a tuple of elements separated by spaces: ")
user_tuple = tuple(user_input.split())

start_index = int(input("Enter the start index to copy from: "))
end_index = int(input("Enter the end index to copy until (exclusive): "))

new_tuple = user_tuple[start_index:end_index]
print("New tuple:", new_tuple)



""" Enter a tuple of elements separated by spaces: 10 20 30 40 
Enter the start index to copy from: 2
Enter the end index to copy until (exclusive): 4
New tuple: ('30', '40') """
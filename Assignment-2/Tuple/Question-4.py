#Unpack the tuple into 4 variables

user_input = input("Enter a tuple of 4 elements separated by spaces: ")
user_tuple = tuple(user_input.split())

if len(user_tuple) != 4:
    print("Please enter a tuple with exactly 4 elements.")
else:
    var1, var2, var3, var4 = user_tuple
    print("Unpacked variables:", var1, var2, var3, var4)



""" Enter a tuple of 4 elements separated by spaces: 10 20 30 40 
Unpacked variables: 10 20 30 40 """
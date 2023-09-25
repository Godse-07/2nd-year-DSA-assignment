/* Given a positive number ‘n’, generate binary numbers between 1 to n using */



from collections import deque

def generate_binary_numbers(n):
    result = []
    queue = deque()
    queue.append('1')

    while n > 0:
        binary_number = queue.popleft()
        result.append(binary_number)

        # Generate next binary numbers by appending '0' and '1' to the current number
        queue.append(binary_number + '0')
        queue.append(binary_number + '1')

        n -= 1

    return result

n = int(input("Enter a positive number: "))
binary_numbers = generate_binary_numbers(n)
print(f"Binary numbers between 1 and {n}:")
for binary_number in binary_numbers:
    print(binary_number)




/* output */

Enter a positive number: 5
Binary numbers between 1 and 5:
1
10
11
100
101




/* c code */

    KHUD SE KARLE YAAR
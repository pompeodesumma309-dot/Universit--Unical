user_string = input("Inserisci la stringa: ")

max_length = 0

current_length = 1

for i in range(0, len(user_string)):

    if i == len(user_string)-1 or user_string[i] != user_string[i+1]:

        if current_length > max_length:

            max_length = current_length

        current_length = 1

    else:        

        current_length += 1        

        

print(max_length)
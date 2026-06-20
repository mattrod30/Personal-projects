import random

while True:
    smallest_number=1
    largest_number=20
    attempt_count=0 
    remaining_attempts = 5
    random_number = random.randint(smallest_number, largest_number)

    print("Number Guessing Game!")
    print(f"I'm thinking of a number from {smallest_number} to {largest_number}.")
    print("_" * 40)

    while True:
        try:
            guess = int(input ("Enter guess: "))
        except ValueError:
            print("Invalid input")
            continue
            
        remaining_attempts -=1
        attempt_count +=1

        if guess == 0 or guess > 20:
            print ("Number not in range!")
            continue

        if guess < random_number:
            print("Not quite, guess higher!")
        elif guess > random_number:
            print("Not quite, guess lower!")
        else:
            print(f"Correct, you got it in {attempt_count} attempts. Nice job!")
            break

        if remaining_attempts == 0:
            print(f"You ran out of guesses! The number was {random_number}")
            break
        

    new_round = input("Play another round? (y/n): ")

    if new_round.lower() != "y":
        print("Game ended.")
        break
                

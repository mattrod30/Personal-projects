import random

HANGMAN_STAGES = [
    """
       -----
       |   |
           |
           |
           |
          ===
    """,  
    """
       -----
       |   |
       O   |
           |
           |
          ===
    """, 
    """
       -----
       |   |
       O   |
       |   |
           |
          ===
    """,  
    """
       -----
       |   |
       O   |
      /|   |
           |
          ===
    """, 
    """
       -----
       |   |
       O   |
      /|\  |
           |
          ===
    """,
    """
       -----
       |   |
       O   |
      /|\  |
      /    |
          ===
    """,  
    """
       -----
       |   |
       O   |
      /|\  |
      / \  |
          ===
    """   
]

word_collection = ["Banana", "Orange", "Grape", "Prime", 
                   "Game", "Basketball", "Soccer"]

print ("Let's play Hangman!")
correct_word = random.choice(word_collection).lower()
blank_spaces = ["_"] * len(correct_word)
guess_attempts = 6
stage = 0
while guess_attempts > 0 and "_" in blank_spaces:
    letter_guess = input("Guess a letter: ").lower()

    if len(letter_guess) > 1 or not letter_guess.isalpha():
        print ("Must enter a single letter only")
        continue

    if letter_guess in correct_word:
        print(f"Yes, there is a {letter_guess} in this word")
        for i, letter in enumerate (correct_word):
            if letter == letter_guess:
                blank_spaces[i] = letter_guess
                print (" ".join(blank_spaces))
    else:
        print(f"Sorry, there is no {letter_guess} in this word")
        guess_attempts -= 1
        stage += 1
        print (HANGMAN_STAGES[stage])
        print (f"Attempts left: {guess_attempts}")

if "_" not in blank_spaces:
    print(f"You got the word right, nice job! The word was {correct_word}")
else:
    print(f"Game over, better luck next time! The correct word was {correct_word}")
  

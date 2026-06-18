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

word_choice = random.choice(word_collection)
stage_tracker = 0

while True:
    letter_guess = input("Pick a letter to guess for the word: ")

    if len(letter_guess) > 1:
        print("You must only guess a letter!")

    if letter_guess in word_choice:
        print (f"Yes, there is a {letter_guess} in this word.")
    else:
        print (f"There is no {letter_guess} in this word")
        stage_tracker += 1
        print (HANGMAN_STAGES[stage_tracker])

    if stage_tracker == 7:
        break

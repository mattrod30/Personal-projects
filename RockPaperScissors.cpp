#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;

int main() {
	string choice;
	srand(time(0));
	int wins = 0;
	int losses = 0;
	vector <string> moves = { "rock", "paper", "scissors" };

	cout << "Welcome to my best of 3 Rock, Paper, Scissors game!" << endl;

	do {
		cout << "Pick your move, rock, paper, or scissors: ";
		cin >> choice;

		int randomChoice = rand() % moves.size();
		cout << "\nThe computer picked: " << moves[randomChoice] << endl;


		if (choice == "rock" && moves[randomChoice] == "paper") {
			cout << "You chose rock, the computer chose paper." << endl;
			cout << "Computer wins!" << endl;
			losses++;
		}

		else if (choice == "paper" && moves[randomChoice] == "paper") {
			cout << "Tie!" << endl;
		}
		else if (choice == "rock" && moves[randomChoice] == "rock") {
			cout << "Tie!" << endl;
		}

		else if (choice == "scissors" && moves[randomChoice] == "scissors") {
			cout << "Tie!" << endl;
		}

		else if (choice == "scissors" && moves[randomChoice] == "paper") {
			cout << "You chose scissors, the computer chose paper." << endl;
			cout << "You win!" << endl;
			wins++;
		}

		else if (choice == "paper" && moves[randomChoice] == "rock") {
			cout << "You chose paper, the computer chose rock." << endl;
			cout << "You win!" << endl;
			wins++;
		}
		else if (choice == "scissors" && moves[randomChoice] == "rock") {
			cout << "You chose scissors, the computer chose rock." << endl;
			cout << "Computer wins!" << endl;
			losses++;
		}
		else if (choice == "paper" && moves[randomChoice] == "scissors") {
			cout << "You chose paper, the computer chose scissors." << endl;
			cout << "Computer wins!" << endl;
			losses++;
		}
		else if (choice == "rock" && moves[randomChoice] == "scissors") {
			cout << "You chose rock, the computer chose scissors." << endl;
			cout << "You win!" << endl;
			wins++;
		}
		else
			cout << "Invalid input" << endl;
	

		cout << "-----" << endl;
		cout << "Player wins: " << wins << endl;
		cout << "Computer wins: " << losses << endl;
		cout << "-----" << endl;
		
	} while (wins < 2 && losses < 2);

	cout << endl;
	if (wins == 2)
		cout << "You win " << wins << " - " << losses << endl;
	else cout << "The computer wins " << losses << " - " << wins << endl;
	

	return 0;

} 

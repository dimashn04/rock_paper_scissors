#include <iostream>
#include <ctime>

char getUserChoice();
char getAIChoice();
void showChoice(char choice);
void chooseWinner(char player, char AI);

int main() {
    char player;
    char AI;

    player = getUserChoice();
    std::cout << "Your choice: ";
    showChoice(player);

    AI = getAIChoice();
    std::cout << "AI's choice: ";
    showChoice(AI);

    chooseWinner(player, AI);

    return 0;
}

char getUserChoice() {
    char player;

    std::cout << "Rock, paper, scissors game!\n";

    do{
        std::cout << "Choose one of the following!\n";
        std::cout << "***************************\n";
        std::cout << "'r' for rock\n";
        std::cout << "'p' for paper\n";
        std::cout << "'s' for scissors\n";
        std::cin >> player;

        if(player != 'r' && player != 'p' && player != 's') {
            std::cout << "Please enter a valid input!\n";
        }
    }while(player != 'r' && player != 'p' && player != 's');

    return player;
}

char getAIChoice() {
    srand(time(0));
    int num = rand() % 3 + 1;

    switch(num) {
        case 1:
            return 'r';
        case 2:
            return 'p';
        case 3:
            return 's';
    }
    return 0;
}

void showChoice(char choice) {
    switch(choice) {
        case 'r':
            std::cout << "Rock\n";
            break;
        case 'p':
            std::cout << "Paper\n";
            break;
        case 's':
            std::cout << "Scissors\n";
            break;
    }
}

void chooseWinner(char player, char AI) {
    switch(player){
        case 'r':
            if(AI == 'r') {
                std::cout << "It's a tie!\n";
            } else if(AI == 'p') {
                std::cout << "You lose!\n";
            } else {
                std::cout << "You win!\n";
            }
            break;
        case 'p':
            if(AI == 'p') {
                std::cout << "It's a tie!\n";
            } else if(AI == 's') {
                std::cout << "You lose!\n";
            } else {
                std::cout << "You win!\n";
            }
            break;
        case 's':
            if(AI == 's') {
                std::cout << "It's a tie!\n";
            } else if(AI == 'r') {
                std::cout << "You lose!\n";
            } else {
                std::cout << "You win!\n";
            }
            break;
    }
}
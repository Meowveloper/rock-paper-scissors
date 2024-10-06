#include <iostream>
#include <limits>
#include <ctime>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);
void clearInput();

int main ()
{
    char player;
    char computer;
    std::cout << '\n';
    std::cout << "********** Rock Paper Scissors Game **********\n";
    player = getUserChoice();
    std::cout << "You chose : ";
    showChoice(player);
    computer = getComputerChoice();
    std::cout << "Computer chose : ";
    showChoice(computer);
    chooseWinner(player, computer);
    std::cout << "**********************************************\n";
    std::cout << '\n';
    return 0;
}

char getUserChoice()
{

    char player;

    std::cout << "Choose one option" << '\n';
    std::cout << "r for rock\n";
    std::cout << "p for paper\n";
    std::cout << "s for scissors\n";
    std::cout << "type here : ";
    std::cin >> player;

    if(std::cin.fail()) 
    {
        std::cout << '\n' << "!!Invalid value please choose again!!\n";
        clearInput();
        return getUserChoice();
    }

    switch (player)
    {
        case 'r' : return player; break;
        case 'p' : return player; break;
        case 's' : return player; break;
        case 'R' : return 'r'; break;
        case 'P' : return 'p'; break;
        case 'S' : return 's'; break;
    
        default: 
            std::cout << "Invalid value please choose again!!\n";
            clearInput();
            return getUserChoice();
        break;
    } 

}

char getComputerChoice()
{
    srand(time(NULL));
    int randNum = (rand() % 3) + 1;
    char computer = 'r';

    switch (computer)
    {
        case 1: computer = 'r'; break;
        case 2: computer = 'p'; break;
        case 3: computer = 's'; break;
        default: break;
    }
    return computer;

}

void showChoice(char choice)
{
    switch (choice)
    {
        case 'r': std::cout << "Rock\n"; break;
        case 'p': std::cout << "Paper\n"; break;
        case 's': std::cout << "Scissors\n"; break;
        default: break;
    }

}

void chooseWinner(char player, char computer)
{
    if (player == computer) 
    {
        std::cout << "It's a Tie!!\n";
        return;
    }
    switch (player)
    {
        case 'r': 
            if(computer == 'p') std::cout << "You Lose!!\n";
            if(computer == 's') std::cout << "You Win !!\n";
        break;
        case 'p': 
            if(computer == 's') std::cout << "You Lose!!\n";
            if(computer == 'r') std::cout << "You Win !!\n";
        break;
        case 's': 
            if(computer == 'r') std::cout << "You Lose!!\n";
            if(computer == 'p') std::cout << "You Win !!\n";
        break;
        default : 
            std::cout << "Something wrong!\n";
        break;
    }

}

void clearInput () 
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
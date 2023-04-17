#include <iostream>
#include <time.h>

char PlayeChoice()
{
    std::cin.clear();
    char input;
    std::cin >> input;

    return input;
}

char CompChoice()
{
    srand(time(NULL));

    int num = rand() % 3;

    if (num == 0)
        return 'r';
    if (num == 1)
        return 'p';
    if (num == 2)
        return 's';
}

void CheckWinner(char uchoice, char cchoice)
{
    std::cout << "Comp played " << cchoice << ".\n";

    if ((uchoice == 'r' && cchoice == 'p') || (uchoice == 'p' && cchoice == 's') || (uchoice == 's' && cchoice == 'r'))
    {
        std::cout << "Computer wins!\n";
        return;
    }
    else if (uchoice == 'r' && cchoice == 'r')
    {
        std::cout << "Tie.\n";
        return;
    }
    else if (uchoice == 'p' && cchoice == 'p')
    {
        std::cout << "Tie.\n";
        return;
    }
    else if (uchoice == 's' && cchoice == 's')
    {
        std::cout << "Tie.\n";
        return;
    }
    else
    {
        std::cout << "You win!\n";
        return;
    }
}

bool CheckProperInput(char uchoice)
{
    if (uchoice != 'r' && uchoice != 'p' && uchoice != 's')
    {
        std::cout << "Not valid input. Try again.\n";
        return true;
    }
    else
        return false;
}

int main()
{
    std::cout << "Welcome to Jan Ken Po\n";
    std::cin.clear();
    std::cout << "Enter r for rock, p for paper, or s for scissors.\n\n";

    bool bPlayAgain = false;
    do
    {
        bPlayAgain = false;
        
        char uchoice;
        bool bProperInput;
        do
        {
            std::cout << "\n>> ";
            uchoice = PlayeChoice();
            bProperInput = CheckProperInput(uchoice);
        } while (bProperInput);

        char cchoice = CompChoice();

        CheckWinner(uchoice, cchoice);

        char response;
        std::cout << "\nWould you like to play again? (y/n)\n>> ";
        std::cin >> response;

        if (response == 'y' || response == 'Y')
            bPlayAgain = true;
        else
            bPlayAgain = false;

    } while (bPlayAgain == true);

    return 0;
}

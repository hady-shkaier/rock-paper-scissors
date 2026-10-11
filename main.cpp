#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

enum enOptions
{
    Rock = 1,
    Paper = 2,
    Scissors = 3
};

enum enWinner
{
    Player1 = 1,
    Computer = 2,
    Draw = 3
};

struct stGameResult
{
    short Rounds;
    short Player1Wins = 0;
    short ComputerWins = 0;
    short Draws = 0;
    string FinalWinner;
};

struct stRoundInfo
{
    int numberOfRound;
    enOptions player1Choice;
    enOptions computerChoice;
    string winnerName;
    enWinner winner;
};

int readNumberInRange(string message, short from, short to)
{
    int num;
    do
    {
        cout << message << endl;
        cin >> num;
    } while (num < from || num > to);

    return num;
}

int randomNumber(short from, short to)
{
    return (rand() % (to - from + 1) + from);
}

bool isComputerWinner(stRoundInfo roundInfo)
{
    return ((roundInfo.player1Choice == enOptions::Paper && roundInfo.computerChoice == enOptions::Scissors) ||
            (roundInfo.player1Choice == enOptions::Scissors && roundInfo.computerChoice == enOptions::Rock) ||
            (roundInfo.player1Choice == enOptions::Rock && roundInfo.computerChoice == enOptions::Paper));
}

string getWinner(enWinner winner)
{
    string arrWinner[] = {"Player1", "Computer", "Draw"};
    return arrWinner[winner - 1];
}

string getOption(enOptions option)
{
    string arrOptions[] = {"Rock", "Paper", "Scissors"};
    return arrOptions[(int)option - 1];
}

enWinner finalWinnerOfGame(stGameResult gameresult)
{
    if (gameresult.ComputerWins > gameresult.Player1Wins)
        return enWinner::Computer;
    else if (gameresult.ComputerWins < gameresult.Player1Wins)
        return enWinner::Player1;
    else
        return enWinner::Draw;
}

void printGameResult(stGameResult gameResult)
{
    cout << "\t\t\t\t_____________________________________________________________\n\n";
    cout << "\t\t\t\t\t\t  +++ G a m e  O v e r +++\n";
    cout << "\t\t\t\t_____________________________________________________________\n\n";
    cout << "\t\t\t\t_______________________[Game Results ]_______________________\n\n";
    cout << "\t\t\t\tGame Rounds        : " << gameResult.Rounds << endl;
    cout << "\t\t\t\tPlayer1 won times  : " << gameResult.Player1Wins << endl;
    cout << "\t\t\t\tComputer won times : " << gameResult.ComputerWins << endl;
    cout << "\t\t\t\tDraw times         : " << gameResult.Draws << endl;
    cout << "\t\t\t\tFinal winner       : " << gameResult.FinalWinner << endl;
    cout << "\t\t\t\t_____________________________________________________________\n\n";
}

enWinner winnerOfRound(stRoundInfo roundInfo)
{
    if (roundInfo.computerChoice == roundInfo.player1Choice)
        return enWinner::Draw;
    else if (isComputerWinner(roundInfo))
        return enWinner::Computer;
    else
        return enWinner::Player1;
}

void setScreenColor(enWinner winner)
{
    switch (winner)
    {
    case enWinner::Player1:
        system("color 2F");
        break;
    case enWinner::Computer:
        system("color 4F");
        cout << "\a";
        break;
    default:
        system("color 6F");
        break;
    }
}

void printRoundResult(stRoundInfo roundInfo)
{
    cout << "\n_____________ Round [" << roundInfo.numberOfRound << "] _____________\n\n";
    cout << "Player1  Choice: " << getOption(roundInfo.player1Choice) << endl;
    cout << "computer Choice: " << getOption(roundInfo.computerChoice) << endl;
    cout << "Round Winner   : " << roundInfo.winnerName << endl;
    cout << "_____________________________________\n\n\n";
    setScreenColor(roundInfo.winner);
}

void updateScore(enWinner winner, stGameResult &gameResult)
{
    switch (winner)
    {
    case enWinner::Computer:
        gameResult.ComputerWins++;
        break;
    case enWinner::Player1:
        gameResult.Player1Wins++;
        break;
    default:
        gameResult.Draws++;
        break;
    }
}

void playRounds(short countOfRounds)
{

    stGameResult gameResult;
    stRoundInfo roundInfo;
    for (short roundNumber = 1; roundNumber <= countOfRounds; roundNumber++)
    {
        roundInfo.numberOfRound = roundNumber;
        roundInfo.player1Choice = (enOptions)readNumberInRange("Your Choice: [1]:Rock, [2]:Paper, [3]:Scissors ? ", 1, 3);
        roundInfo.computerChoice = (enOptions)randomNumber(1, 3);
        roundInfo.winner = winnerOfRound(roundInfo);
        roundInfo.winnerName = getWinner(roundInfo.winner);
        printRoundResult(roundInfo);

        updateScore(roundInfo.winner, gameResult);
    }

    gameResult.Rounds = countOfRounds;
    gameResult.FinalWinner = getWinner(finalWinnerOfGame(gameResult));

    printGameResult(gameResult);
}

bool playAgain(string message)
{
    char playAgain;
    do
    {
        cout << message;
        cin >> playAgain;

    } while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N');
    if (playAgain == 'y' || playAgain == 'Y')
        return true;
    else
        return false;
}

void resetScreen()
{
    system("cls");
    system("color 0F");
}

void startSystem()
{
    do
    {
        resetScreen();
        playRounds(readNumberInRange("How Many Rounds 1 to 10 ? ", 1, 10));
    } while (playAgain("\t\t\t\tDo you want to play again? Y/N?"));
}

int main()
{
    srand((unsigned)time(NULL));
    startSystem();
    return 0;
}
// Created By HaDy
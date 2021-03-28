/*****************************************************************************
 C++ Programming - From Problem Analysis to Program Design 5th Edition
 Chapter 9 - Exercise 7
 markdhoad@gmail.com
 
 Write a program that allows the user to enter the last names of five candidates
 in a local election and the number of votes received by each candidate. The 
 program should then output each candidate’s name, the number of votes
 received, and the percentage of the total votes received by the candidate. 
 Your program should also output the winner of the election.
 *****************************************************************************/


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int findWinner(int votes[]);
void printResults(string candidates[], int votes[]);
double calculatePercentage(int votes[], int vote);

const int numberOfCandidates = 5;

int main()
{
    
    string candidates[numberOfCandidates];
    int votes[numberOfCandidates];

    
    cout << "Enter 5 candidates followed by number of votes recieved: ";
    for (int i = 0; i < numberOfCandidates; i++) {
        cin >> candidates[i] >> votes[i];
    }
    printResults(candidates, votes);
    cout << "The Winner of the Election is " << candidates[findWinner(votes)] << endl;
    return 0;
}

double calculatePercentage(int votes[], int vote){
    int sumOfVotes = 0;
    
    for (int i = 0; i < numberOfCandidates; i++) {
        sumOfVotes += votes[i];
    }
    
    double percentage = static_cast<double>(vote) / static_cast<double>(sumOfVotes);

    return percentage*100;
}


void printResults(string candidates[], int votes[]){
    cout << "Candidate Votes Received % of Total Votes" << endl;
    cout << fixed << showpoint << setprecision(2) << endl;
    for (int i = 0; i < numberOfCandidates; i++) {
        
        cout << candidates[i] << setw(15) << votes[i] << setw(15);
        double percentage = calculatePercentage(votes, votes[i]);
        
        cout << percentage << endl;
        
    }
}

int findWinner(int votes[]){
    int winner = 0;
    for (int i = 0; i < numberOfCandidates; i++) {
        if (votes[winner] <= votes[i])
            winner = i;
    }
    return winner;
}

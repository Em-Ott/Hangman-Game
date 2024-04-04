/*
Name: Emily Ott
Class: CPSC 121, Spring 2024
Date: 03/25/24
PA 6 Assignment
Description: This program takes a repeating list of student ID, GPA, standing, and age and reads it from an external file
Calculates means (of latter three) and standard deviation (of GPA) and out puts it to an external file
Notes: 
*I recognize a headerfile does not need to be .h but you requested 2 .cpp files and 1 .h
*No outside sources used
*Bonus attempted 
*/

#ifndef OTT_PA7_H
#define OTT_PA7_H

#include <iostream>
#include <fstream>
#include <string>
//Below 2 are both used for rand
#include <cstdlib>
#include <ctime>

using namespace std;

string randomNumberToWord(string wordList[], int wordsRead);
void arrayFiller(char arrayToBeFilled[]);
void alphabetFiller(char arrayToBeFilled[]);
void printIncorrectGuess(int incorrectGuesses);
void showLetters(char availableLetters[], char visibleLetters[], int wordLength);
bool checkIfCorrect(char visibleLetters[], int wordLength, char userGuess, string randomWord);
bool replay();


#endif

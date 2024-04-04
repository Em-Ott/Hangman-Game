#include "Ott_PA7.h"

/*************************************************************
* Function: string randomNumberToWord(string wordList[], int wordsRead)
* Date Created: 04/03/24
* Date Last Modified: 04/03/24
* Description: This functions selects a random word from the word list 
* that hasn't been read before.
* Input parameters: The list of words and the number of items in that list.
* Returns: The random word.
* Pre: The list has to be read from the file and the amount of times its been read have had to be counted.
* Post: Returns a random word.
*************************************************************/
string randomNumberToWord(string wordList[], int wordsRead){
        int randomNumber, wordsInSelection = 0;
        string randomWord, selectionList[100];
        srand(time(0));
        for (int i = 0; i < wordsRead; ++i){
            if (wordList[i] != "-"){
                selectionList[wordsInSelection] = wordList[i];
                ++wordsInSelection;
            }
        }
        randomNumber = rand()%wordsInSelection;
        randomWord = selectionList[randomNumber];

        /*
        since we start modifying our two different lists 
        the same words no longer match up and 
        we have to reverse search to remove it from the pool
        */
        for (int i = 0; i < wordsRead; ++i){
            if (wordList[i] == randomWord){
                wordList[i] = "-";
            }
        }
        
        return randomWord;
}

/*************************************************************
* Function: void arrayFiller(char arrayToBeFilled[])
* Date Created: 04/03/24
* Date Last Modified: 04/03/24
* Description: This functions fills an array (maximum size 45) with '-'s
* Input parameters: The array to be filled with '-'
* Returns: Nothing but the array is changed to have '-'s
* Pre: The array has to be read.
* Post: The array is changed to be filled with '-'s.
*************************************************************/
void arrayFiller(char arrayToBeFilled[]){
    for (int i = 0; i < 45; ++i){
        arrayToBeFilled[i] = '-';
    }
}

/*************************************************************
* Function: void alphabetFiller(char arrayToBeFilled[])
* Date Created: 04/03/24
* Date Last Modified: 04/03/24
* Description: This functions fills an array from a to z (maximum size is size of the alphabet)
* Input parameters: The array to be filled 
* Returns: Nothing but the array is changed to have lowercase letters in alphabetical order
* Pre: The array has to be read.
* Post: The array is changed to be filled with lowercase letters in alphabetical order.
*************************************************************/
void alphabetFiller(char arrayToBeFilled[]){
    char startingLetter = 'a';
    for (int i = 0; startingLetter <= 'z'; ++i, ++startingLetter){
        arrayToBeFilled[i] = startingLetter;
    }
}

/*************************************************************
* Function: void printIncorrectGuess(int incorrectGuesses)
* Date Created: 04/03/24
* Date Last Modified: 04/03/24
* Description: This functions prints out how many incorrect guesses are left.
* Input parameters: The number of incorrect guesses left.
* Returns: Nothing
* Pre: The incorrect guesses has to match how many times the user hasn't messed up (max is 7)
* Post: A statement is printed to console.
*************************************************************/
void printIncorrectGuess(int incorrectGuesses){
    cout << incorrectGuesses << " incorrect guesses are remaining." << endl;
}

/*************************************************************
* Function: void showLetters(char availableLetters[], char visibleLetters[], int wordLength)
* Date Created: 04/03/24
* Date Last Modified: 04/03/24
* Description: This function prints out available and visible letters.
* Input parameters: The lists with available and visible letters and the word length
* Returns: Nothing
* Pre: The lists to be filled out with either -s or letters and 
* the amount of letters in the random word
* Post: The lists are printed
*************************************************************/
void showLetters(char availableLetters[], char visibleLetters[], int wordLength){
    for (int i = 0; i < wordLength; ++i){
                cout << visibleLetters[i];
            }
            cout << endl << "Available letters: ";
    for (int i = 0; i < 26; ++i){
               cout << availableLetters[i];
    }
}

/*************************************************************
* Function: bool checkIfCorrect(char visibleLetters[], int wordLength, char userGuess, string randomWord)
* Date Created: 04/03/24
* Date Last Modified: 04/03/24
* Description: This function determines if a letter is in the word
* Input parameters: The list of visible letters, letters in the random word,
* what the user's guess is, and the random word.
* Returns: If the guess is correct.
* Pre: The list of visible letters, the length of the word through .size() or .length(),
* the user's guess needs to be inputted through a cin, and the random word 
* Post: The visible letters list is modified to show the user's guess if it is in the word
*************************************************************/
bool checkIfCorrect(char visibleLetters[], int wordLength, char userGuess, string randomWord){
    bool userGuessValid = false;
    for (int i = 0; i < wordLength; ++i){
        if (randomWord.at(i) == userGuess){
            cout << "Good guess! " << userGuess << " is in the word!" << endl;
            visibleLetters[i] = userGuess;
            userGuessValid = true;
            //I would like to break here but we have to keep going in case the letter is used twice
        } 
    }
    return userGuessValid;
}

/*************************************************************
* Function: bool replay()
* Date Created: 04/03/24
* Date Last Modified: 04/03/24
* Description: This function asks the user if they would like to replay the game,
* takes their input, and returns whether or not they want to
* Input parameters: None
* Returns: If they want to replay the game, either true or false.
* Pre: None
* Post: True or false is returned and if it is true the loop in the main function continues
*************************************************************/
bool replay(){
    bool gameReplay;
    int playAgain;
    cout << "Would you like to play again? If so, answer 1." << endl;
    cin >> playAgain;
    if (playAgain == 1){
        gameReplay = true;
        cout << "Let's do it! ";
    } else {
        cout << "Bye then! It was a fun game!" << endl;
        gameReplay = false;
    }
    return gameReplay;
}
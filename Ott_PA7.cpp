/*
This is a game of hangman I made for my CS 121 class.
It is intended to read in a list of words from a file (words.txt) is the file we were told to put
File can be modified in coding if needed.
Then it proceeds as a normal game of hangman, can be replayed, and when 
replayed the words won't be repeated.
Overall it was a pretty fun assignment although I got stuck on some small errors (using == when I should've used =)
*/

#include "Ott_PA7.h"

int main(){
    ifstream wordChoicesFile;
    string wordChoices[100], randomWord;
    int wordsRead = 0, incorrectGuesses = 7, wordsGuessed = 0; 
    char availableLetters[26];
    //visible letters length is 45 as the longest word as 45 letters so there will be no word with more letters
    char visibleLetters[45], userGuess;
    bool gameReplay = true, gameEnd = false, userGuessValid = false;

    wordChoicesFile.open("words.txt"); 

    arrayFiller(visibleLetters);

    //could make this into a function but basically everything would need to be passed by reference so I think that's redundant
    //reads file
    while(!wordChoicesFile.eof()){
        wordChoicesFile >> wordChoices[wordsRead];
        ++wordsRead;
    }

    while (gameReplay == true) {
        //resetting conditions
        gameEnd = false;
        gameReplay = false;
        incorrectGuesses = 7;
        arrayFiller(visibleLetters);
        alphabetFiller(availableLetters);
        //generates unique seed based on time
        randomWord = randomNumberToWord(wordChoices, wordsRead);
        cout << randomWord.length() << " is your word size." << endl;
        do {
            //main game loop
            showLetters(availableLetters, visibleLetters, randomWord.length());
            cout << endl;
            printIncorrectGuess(incorrectGuesses);
            cout << "Please enter your guess as a lower case letter:" << endl;
            cin >> userGuess;

            for (int i = 0; i < 26; ++i){
                //checks if it's a valid guess then if valid checks if it's correct
                if (availableLetters[i] == userGuess){
                    availableLetters[i] = '-';
                    //checks if their guess matches up with any letter in the word
                    userGuessValid = checkIfCorrect(visibleLetters, randomWord.length(), userGuess, randomWord);
                   if (userGuessValid == false){
                        incorrectGuesses -= 1;
                        cout << "Nice try. Unfortunately, " << userGuess << " is not in the word." << endl;
                        printIncorrectGuess(incorrectGuesses);
                   }
                   //resetting the status of whether their guess is right or wrong
                   userGuessValid = false;
                } 
            }
            //This allows me to check if any of the current letters have - it isn't guessed
            //But if it's fully guessed gameEnd will equal true and the loop will end.
            gameEnd = true;
            for (int i = 0; i < randomWord.length(); ++i){
                if (visibleLetters[i] == '-'){
                    gameEnd = false;
                }
            }
            if (gameEnd == true){
                cout << "Congratulations! You won!" << endl;
            }
            if (incorrectGuesses == 0){
                gameEnd = true;
                cout << "Sorry! You lost!" << endl;
            }

        } while (gameEnd == false);

        wordsGuessed += 1;
        if (wordsGuessed == wordsRead){
            cout << "You guessed everything! Good job!" << endl;
            break;
        }
        gameReplay = replay();

    }

    wordChoicesFile.close();

    return 0;
}
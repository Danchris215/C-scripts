#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> //for time()
using namespace std;

int main(){
    //this will ensure that the numbers generated during program's execution are different each time 
    srand(time(0));
    //the reason for the above comment is because rand is a determnistic algorithmand given the same seed, wll always produce the same sequence of numbers.
    // the essence of taking modulo of the randomly generated number is to make sure that our answer lies between 0 and 99. The addition of 1 makes our range to be between 1 and 100.
    int secretNumber = rand() % 100 + 1;
    int guess;
    
    cout << "Welcome to the Number Guessing Game!!" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;
    
    while(true){
        cout << "Enter your guess: ";
        cin >> guess;
        
        if(guess < secretNumber){
            cout << "Too low!" << endl;
        }else if (guess > secretNumber){
            cout << "Too high!" << endl;
        }else{
            cout << "Congratulations! You guessed the number in " << 0 << "attempts." << endl;
            break;
        }
    }
    return 0;
}

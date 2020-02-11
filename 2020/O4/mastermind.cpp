#include "headers/mastermind.h"

void playMastermind() {
    // Global constants
    constexpr int size = 4;
    constexpr int letters = 6;
    const char lower = 'A';
    const char upper = lower + letters - 1;

    // Game variables
    int correctColorAndPos = 0;
    int correctColor = 0;
    unsigned int lives = 16;
    string code = randomizeString(size, lower, upper);
    string guess = "";

    // Graphics variables
    constexpr int winW = 500;
    constexpr int winH = 900;
    Point winTl{100, 100};
    string winTitle = "mastermind";
    MMWindow win{winTl, winW, winH, winTitle, 0, 0, winTl, {winW - winTl.x, winTl.y + 45} };
   
    win.initGraphics(); 
    win.wait_for_button();
    //cout << code << endl;
    while(lives) {
        // Read user input
        cout << "Guess: ";
        guess = readInputToString(size, lower, upper);

        // Update game values
        correctColorAndPos = checkCharactersAndPosition(code, guess);
        win.wh = correctColorAndPos;
        correctColor = checkCharacters(code, guess) - correctColorAndPos;
        win.bl = correctColor;
        
        // Update graphics
        win.updateGraphics(guess);
        win.wait_for_button();

        // End if end-conditions are met, otherwise inform user of game values and continue
        if(correctColorAndPos == size || !lives) {
            break;
        }
        else {
            lives--;
            cout << "Correct colors: " << correctColor << '\n'
                 << "Correct positions and colors: " << correctColorAndPos<< '\n'
                 << "Lives remaining: " << lives << '\n';   
        }
    } // EOF game loop

    // Draw code
    win.revealCode(code);
    win.wait_for_button();

    // Draw ending message?

    // Print ending message
    cout << (lives ? "You won!" : "You lost!") << '\n';
}

int checkCharactersAndPosition(string code, string guess) {
    int count = 0;
    for(int i = 0; i < code.length(); i++) {
        if(guess[i] == code[i]) {
            count++;
        }
    }
    return count;
}

int checkCharacters(string code, string guess) {
    int count = 0;
    for(const char guessChar : guess) {  
        string::iterator iter = find(code, guessChar);   // Iterate through the code, try to find the currect character of guess     
        if(iter != code.end()) {                         // if find() does not return code.end(), it found the guess char in the code
            count++;
            code.erase(iter);                            // Remove the character that we counted from the code, to prevent double-counting
        }
    }
    return count;
}
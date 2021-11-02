// Jessica Reyes ID223
// Fall 2021 Do You Want to Keep Adventuring?

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// global variables
int totalHealth = 30;
int totalTreasure = 0;

int rollDie(int sides = 6);

void myStory() {
    cout << "You just had a long weekend...before you know it, here we are, it's Monday all over again...\n";
    cout << "You have " << totalHealth << " health points...\n";
}

char AskYesNo(string question = "Do you want to continue adventuring?") {
    char input;
    do {
        cout << question << endl;
        cout << "(y/n) >> ";
        cin >> input;
        
        
    } while(input != 'y' && input != 'n');
    
    return input;
}



void Ending() {
    if (totalHealth > 0) {
        
        
        cout << "You return home with " << totalTreasure << " pieces!\n";
        
    } else { 
        
        cout << "Your health is " << totalHealth << " you must recharge!\n";
        cout << "You return home with " << totalTreasure << " treasure!\n";
    }
    return;
}

void theAdventure() {
    while (totalHealth > 0)
    {
        if (AskYesNo() == 'y') {
            int Attack = rollDie();
            int Block = rollDie();
            if (Block >= Attack) {
                totalTreasure += 10;
                totalHealth -= 1;
                cout << "Let's go adventuring!\n";
                cout << "You have successfully blocked!\n";
                cout << "You lose 1 health point and gain 10 treasure!\n";
                cout << "Your total health is now " << totalHealth << " and you have " << totalTreasure << " treasure!\n";
            } else if (Block < Attack) {
                
                totalHealth -= 5;
                cout << "Your health is now " << totalHealth << " and you have " << totalTreasure << " treasure...\n";

            }
            } else {
            cout << "Your current health is " << totalHealth << ".\n";
            cout << "Your current amout of treasure is " << totalTreasure << ".\n";
            return;
        }
    }
        
}
int main() {
    srand(time(0));
    myStory();
    theAdventure();
    Ending();
    return 0;
    
}
int rollDie(int sides) {
    return rand() % sides + 1;
}
// Jessica Reyes ID223
//Fall 2021 Adventure #1

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <unistd.h>
using namespace std;

int main() {
    cout << "Welcome to Adventure #1.\n";
    

    int health = 10;
    int block;
    int attack;
    int turns = 0;

    srand(time(0));

    do {
        turns++;
        int block = rand() % 5;
        int attack = rand() % 5;

        cout << block << " " << attack << endl;

        if (block >= attack) {
            sleep(5);
            
        }
        else if (block < attack) {
            health -= 5;
            cout << "Your health is now: " << health << "\n";
            sleep(5);
            
        }
        
    } while(turns <= 3 && health > 0);  

    if (health > 0) {
        cout << "Success, you won the game in the luck of randomness!";
    } 
    else {       
        cout << "Your health 0 or below healthy, you need to see a DOCTOR...";
    }
}
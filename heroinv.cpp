// Jessica Reyes ID223
// Fall 2021 Hero's Inventory

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string hikeInput;
    int totalItems = 10; 
    string items[10] = { "Water", "Almonds", "Apple", 
                        "Sandwich", "Banana", "Airhorn",
                        "Watch", "Sunglasses", "Blanket", "Sunscreen"};

    

    cout << "\nHello!  Welcome to Climbing the mountain in Yellowstone Park!\n";
    cout << "\nThere are limited sources you can request to get you through the hike to reach the top of the mountain!  You will have the option of more healthy snacks to choose from or something to protect you from bears!\n";

    cout << "\nYou will be given 3 items to start with:\n";
    for (int i = 0; i < 3; i++) {
        cout << "\n" << items[i] << "";
        
    }
    cout << "\n\nSo you begin your journey on this new hike you have never experienced and really needed something to get started, so you drink some water to keep you from being dehydrated...\n";
   
    items[0] = "";

    cout << "So what can you do to keep the blazing sun out of your eyes?\n";
    cin >> hikeInput;

    items[7] = hikeInput;

    
    cout << "\nYou reach a point to take a break and want a typical 'picnic type' snack...So what is it that sounds perfect to eat right now?\n";
    cin >> hikeInput;

    cout << "\nYou decide to eat your " << hikeInput << " along with " << items[1] << " and are finally energized and want to reach the top of this mountain!\n";
    
    items[1] = "";
    items[3] = "";

    cout << "\nYou now have:\n";
    for(int i = 0; i < totalItems; i++) {
        if(items[i] != "") {
            cout << "" << items[i] << "\n";
        }
    }
    cout << "\nYou are reaching the hottest part of the day and want to use what before it's too late?\n";
    cin >> hikeInput;

    cout << "\nThen you need what to sit down on what to apply all of that " << hikeInput << " evenly where the sun might burn you?\n";
    cin >> hikeInput;
    

    items[8] = ""; 
    items[9] = "";

    cout << "\nOk, you're ready to complete this mountain with the remaining supplies: \n";
    for(int i = 0; i < totalItems; i++) {
        if(items[i] != "") {
            cout << "" << items[i] << "\n";
        }
    }
    cout << "\nWhat would you like to eat now that you are 3/4 up this mountain?\n";
    cin >> hikeInput;

    cout << "\nAnd finally you enter the top part of the mountain where you see a bear guarding the very top part\n";
    cout << "\nDo you scare the bear off with the " << items[5] << " or do you give them a valuable treasure?...\n";
    cin >> hikeInput;

    for(int i = 0; i < 1; i++) {
        if(hikeInput == items[6]) { 
            cout << "\nCongratulations you have reached the top of the mountain in Yellowstone National Park!\n";
        }
        else if(hikeInput == items[5]) {
            cout << "\nYou frightened the bear with " << items[5] << "and lost the game...";

        }
        else {
            cout << "\nThe bear wasn't hungry and only wanted to know what time it was!\n";

        }
    }

}

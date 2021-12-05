// Jessica Reyes ID223
// Fall 2021 Types, Variables, and I/O

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    // variables
    const int perDay = 2;
    const int cupsWater = 8;
    int drinkToday, drinkYesterday, cupsH20;
    string name;

    // get the information
    cout << "How much water are you drinking in a day?\n\n";
    cout << "Please enter the following information to find out if you are drinking enough water...\n";

    cout << "Enter how many cups of water you drank today: ";
    cin >> drinkToday;

    cout << "Enter how many cups of water you drank yesterday: ";
    cin >> drinkYesterday;

    cupsH20 = drinkToday + drinkYesterday;

    cout << "Enter your name: ";
    cin >> name;

    // my calculations for drinking water.

    cout << "\nHello, " << name << "." << " It looks like you consumed " << cupsH20 << " cups in the last two days.";
    cout << " So on average you are drinking about " << cupsH20 / perDay  << " cups per day. \n";
    cout << "\nIf you are below the recommended, 8 cups per day...  Which means, " << name << ", you need to drink more water; to avoid dehydration which can lead to headaches.\n";
    cout << "\nIf " << name << ", you are drinking 8 cups or more; BRAVO, you're on a GREAT path to better health!\n";

  

    // bool
    
    cout << "\nWell are you drinking 8 glasses of water per day? " << bool(cupsH20 / perDay >= 8);

    cout << "\nIf you have scored a 0, meaning False, then " << name << " please drink more water!  Otherwise, if you see a 1, keep up your pace!\n";

    // Increment & Decrement Operators

    drinkToday++;
    drinkYesterday--;

    cout << "\nSo, for incremental operators, I have added one extra cup to your today's intake, " << drinkToday << " cups, showing 1 more cup to today.\n";
    cout << "\nSince I added one extra cup to today, let's subract one from yesterday's, which shows, " << drinkYesterday << ", showing one less, to show the decrement operator.\n";

    // += and -=

    drinkToday -= 1;
    drinkToday += 3;

    cout << "\nLet's say you would like to add 3 more cups to todays intake, which would be " << drinkToday << " because today is still not over!\n";


    // enumerators
    enum health {DRINKER = 8, DAYS = 7};


    cout << "\nSo, for the average person, should be drinking, " << DRINKER * DAYS << " cups of water per week; which would equivalant to " << DRINKER * DAYS * 8 << " ounces of water!\n";

    // float
    const float perday = 8.5f;
    const float perounce = 8.10f;

    cout << "\nBe sure to drink " << perday * perounce << " fluid ounces of water each day, if you want to be abit of an overachiever!\n";

    cout << "\nI hope this encourages you, to overall drink more water, for better health!\n";
}
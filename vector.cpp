// Jessica Reyes ID223
// Fall 2021 A Vector of Names

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cout << "Welcome to the list of names!\n";

    // creating the names in a vector
    vector<string> names;
    names.push_back("Lily");
    names.push_back("Brady");
    names.push_back("Jessica");

    vector<string>::iterator changeIter;
    vector<string>::const_iterator readIter;
    vector<string>::iterator removeIter;

    string userInput;

    // list of names
    cout << "Names:\n";
    for(readIter = names.begin(); readIter != names.end(); ++readIter) {
        cout << *readIter << endl;
    }

    do {
        cout << "What would you like to do?\n";
        cin >> userInput;
        if(userInput == "Add") {
            cout << "What name would you like to add?\n";
            cin >> userInput;
            names.push_back(userInput);
            cout << "The name " << userInput << " has been added to the list.\n";
        }
        
        else if(userInput == "Change") {
            cout << "What name would you like to change?\n";
            cin >> userInput;

            // looking for the name
            for(changeIter = names.begin(); changeIter != names.end(); ++changeIter) {
                if(*changeIter == userInput) {
                    cout << "I have found the name!\n";
                    cout << "What would you like to change it to?\n";
                    cin >> userInput;
                    string temp = *changeIter;  // this is the old value
                    *changeIter = userInput;
                    cout << temp << " has been changed to " << *changeIter << ".\n";
                    break;  // the change has been made - break out of the for loop.
                }// end of if statement that looks for a name.

                if(changeIter + 1 == names.end()) {
                    cout << "I could NOT find the name entered.\n";
                }// end of  "couldn't find the name" if-statement
            }// end of for loop
        }// end of "change" else-if statement

        // Removing a name from the list
        else if(userInput == "Remove") {
            cout << "What name would you like to remove?\n";
            cin >> userInput;

        
        
            for(removeIter = names.begin(); removeIter != names.end(); ++removeIter) {
                if(*removeIter == userInput) {
                    names.erase(std::remove(names.begin(), names.end(), userInput), names.end());
                    cout << *removeIter << " has been removed from list.\n";
                    break;  // the change has been made - break out of the for loop.
                }

                if(removeIter + 1 == names.end()) {
                    cout << "I could NOT find the name entered.\n";
                }
            }
        }

        // Sorting the names in our list
        else if(userInput == "Sort") {
            
            sort(names.begin(), names.end());
            cout << "Sorted Names in our list:\n";
            for (readIter = names.begin(); readIter != names.end(); ++readIter) {
                cout << *readIter << endl;
            }
        }
        
        else if (userInput == "Quit" || userInput == "quit") {
            cout << "Thank you for modifying the list, Goodbye!\n";
            break; // break out of the do-while loop
        
        }
        else {
            cout << "That is not one of the options.\n";
                
            }
        
        
    } while(userInput != "Quit" || userInput != "quit");  
    // end of do-while loop
}
// end of int(main)
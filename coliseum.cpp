// Jessica Reyes ID223
// Fall 2021 Coliseum

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Enemy {
    
private:
    friend void Peek(const Enemy& givenEnemy);
    friend ostream& operator<<(ostream& os, const Enemy& givenEnemy);
    string name;
    int health;
    int damage;
    int damageType;
public:
    // constructor
    Enemy(const string& givenName = "") { name = givenName; }
    string GetName() const { return name; }

    void Attack(string name) {
        int damageType = rand() % 25;
        int damage = rand() % 25;

        cout << GetName() << " " << damageType << " " << name << " " << damage;
        if (damageType >= damage) {
            cout << "\n" << GetName() << " wins and get's to battle again, while " << name << " lost.\n";
        }
        else if (damageType <= damage) {
            cout << "\n" << name << " loses and doesn't get to battle.\n";
        }

    }
    

    
    // ~Enemy() {
    //     delete M_name;
    // }
    // void Attack1() {
    //     srand(time(0));
    //     int randomNumber = rand();
    //     int damageType = (randomNumber % 25) + 1;
    //     int damage = (randomNumber % 25) + 1;
    //     cout << "June: " << damageType << " Jill: " << damage << ".\n";
    //     if (damageType <= damage) {
            
    //         cout << "June lost and Jill gets to battle Jack!\n";
    //         int health = -10;
    //     }
    //     else if (damageType >= damage) {
    //         cout << "June wins and gets to battle Jack!\n";        
                     
    //     }
    // }
    // void Attack2() {
    //     srand(time(0));
    //     int randomNumber = rand();
    //     int damageType = (randomNumber % 25) + 1;
    //     int damage = (randomNumber % 25) + 1;
    //     cout << "Jack: " << damageType << " Jill: " << damage << ".\n";
    //     // m_Name = new string;
    //     if (damageType <= damage) {
            
    //         cout << "Jack lost and Jill gets to battle Sunny!\n";
    //         int health = -10;
    //     }
    //     else if (damageType >= damage) {
    //         cout << "Jack wins and gets to battle Sunny!\n";        
                     
    //     }

    // }
    // void Attack3() {
    //     srand(time(0));
    //     int randomNumber = rand();
    //     int damageType = (randomNumber % 25) + 1;
    //     int damage = (randomNumber % 25) + 1;
    //     cout << "Sunny: " << damageType << " Jack: " << damage << ".\n";
    //     // m_Name = new string;
    //     if (damageType <= damage) {
            
    //         cout << "Jack lost and Sunny, Sunny is the winner!\n";
    //     }
    //     else if (damageType >= damage) {
    //         cout << "Jack wins and gets to battle Sunny!\n";   
    //     }
    // }

};

void Peek(const Enemy& givenEnemy) {
    cout << givenEnemy.name << endl;
}

ostream& operator<<(ostream& os, const Enemy& givenEnemy) {
    os << givenEnemy.name;
    return os;
}


class Characters {
public:
    // constructor
    Characters(int spaces = 1) { enemys.reserve(spaces); }
    void Add(const Enemy& givenEnemy) { enemys.push_back(givenEnemy); }
    void RollCall() const {
        for(int i = 0; i < enemys.size(); i++) {
            cout << enemys[i].GetName() << endl;
        }
    }
private:
    vector<Enemy> enemys;
};

int main() {
        srand(time(0));
        int randomNumber = rand();
    

    Characters superFriends(4);

    superFriends.Add(Enemy("Jack"));
    superFriends.Add(Enemy("Jill"));
    superFriends.Add(Enemy("Sunny"));
    superFriends.Add(Enemy("June"));
    Enemy jack("Jack");
    Enemy jill("Jill");
    Enemy sunny("Sunny");
    Enemy june("June");


    // jack.Attack1(); 
    // jill.Attack2();
    // sunny.Attack3();

    jack.Attack("Jill");
    jill.Attack("Sunny");
    sunny.Attack("June");
    june.Attack("Jack");




}

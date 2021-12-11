// Jessica Reyes ID223
// Fall 2021 Final Project

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

enum en_DIRS {NORTH, EAST, SOUTH, WEST};
enum en_FOREST {MOUNTAINS, GARDENS, NATURETRAIL, CABIN, HOTSPRINGS, WEEPINGWILLOW, GROCERY, WATERFALL, REDWOOD, BUTTERFLY, BOATRIDE, PANDO, LOG, EVERGREEN, LILYPAD, ASPEN, CAMP, CONVENIENCE, COTTONWOOD, EASTERN};
enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK, SLEEP, RELAX};
enum en_NOUNS {GATE_DOOR, SUNGLASSES, SHOES, CAMERA, MONEY, BACKPACK, WATERBOTTLE, SUNSCREEN, HEADPHONES, BICYCLE, HAT, MASONJAR, BOAT, PICNICBASKET, TENT};

const int NONE = -1;
const int DIRS = 4;
const int FOREST = 20;
const int VERBS = 10;
const int NOUNS = 15;

// bool debug = false;

class Words
{
// private:
//     string m_Word;
//     int m_Code;
//     int GetCode() const;
//     string GetWord() const;    
    
public:
    string word;
    int code;
    // Words(string& word, int code);
    // void set_directions(int code, string word);
    // void set_verbs(int code, string word);
    // Get_directions() const; 
    // Get_verbs() const;   

    // constructor
    Words();
    // destructor
    ~Words();
};
// constructor definition
Words::Words()
{}
// destructor definition
Words::~Words()
{}

// void Words::set_directions()
// {   
//     m_Code = code;
//     m_Word = word;
// }

// void Words::set_verbs(int code, string& word) 
// {   
//     m_Code = code;
//     m_Word = word;
// }



// Words::Words(string word, int code)
// {
//     set_directions(code, word);
//     set_verbs(code, word);
// }


// inline int Words::GetCode() const
// {
//     return (m_Code);
// }

// inline string Words::GetWord() const
// {
//     return (m_Word);
// }

class Room
{
public:
    string description;
    int exits_to_room[DIRS];
    // constructor
    Room();
    // destructor
    ~Room();
};
// constructor definition
Room::Room()
{}
// destructor definition
Room::~Room()
{}

class Noun
{
// private:
//     string m_Word;
//     string m_Description;
//     int m_Code;
//     int m_Location;
//     string Get_Word();
//     string Get_Description();
//     int Get_Code();
//     int Get_Location();

public:
    Noun(string word, string description, int code, int location);
    bool inventory;
    string word;
    string description;
    int code;
    int location;
    bool can_carry;
    
    

    // constructor
    Noun();
    // destructor
    ~Noun();
};
// constructor definition
Noun::Noun()
{}
// destructor definition
Noun::~Noun()
{}

// inline string Noun::Get_Word() 
// {
//     return (m_Word);
// }

// inline string Noun::Get_Description() 
// {
//     return (m_Description);
// }

// inline int Noun::Get_Code() 
// {
//     return (m_Code);
// }

// inline int Noun::Get_Location() 
// {
//     return (m_Location);
// }
// Noun::Noun(string word, string description, int code, int location):
//     m_Word(word),
//     m_Description(description),
//     m_Code(code),
//     m_Location(location)
// {}

// void displayList(vector<string>& list) {
//     for(int i = 0; i < 12; i++) {
//         cout << list[i] << endl;
//     }
// }

void set_rooms(vector<Room>& rms) {
    // if(debug) cout << "starting set_rooms().\n";

    rms[MOUNTAINS].description.assign("mountainous area");
    rms[MOUNTAINS].exits_to_room[NORTH] = LOG;
    rms[MOUNTAINS].exits_to_room[EAST] = NONE;
    rms[MOUNTAINS].exits_to_room[SOUTH] = NATURETRAIL;
    rms[MOUNTAINS].exits_to_room[WEST] = NONE;

    rms[GARDENS].description.assign("Botanical Gardens");
    rms[GARDENS].exits_to_room[NORTH] = NONE;
    rms[GARDENS].exits_to_room[EAST] = NONE;
    rms[GARDENS].exits_to_room[SOUTH] = CABIN;
    rms[GARDENS].exits_to_room[WEST] = NONE;

    rms[NATURETRAIL].description.assign("hiking trails");
    rms[NATURETRAIL].exits_to_room[NORTH] = MOUNTAINS;
    rms[NATURETRAIL].exits_to_room[EAST] = CABIN;
    rms[NATURETRAIL].exits_to_room[SOUTH] = NONE;
    rms[NATURETRAIL].exits_to_room[WEST] = NONE;

    rms[CABIN].description.assign("cabin home");
    rms[CABIN].exits_to_room[NORTH] = GARDENS;
    rms[CABIN].exits_to_room[EAST] = HOTSPRINGS;
    rms[CABIN].exits_to_room[SOUTH] = WEEPINGWILLOW;
    rms[CABIN].exits_to_room[WEST] = NATURETRAIL;

    rms[HOTSPRINGS].description.assign("relaxation area to the Hotsprings");
    rms[HOTSPRINGS].exits_to_room[NORTH] = NONE;
    rms[HOTSPRINGS].exits_to_room[EAST] = NONE;
    rms[HOTSPRINGS].exits_to_room[SOUTH] = NONE;
    rms[HOTSPRINGS].exits_to_room[WEST] = CABIN;

    rms[WEEPINGWILLOW].description.assign("Weeping Willow Tree");
    rms[WEEPINGWILLOW].exits_to_room[NORTH] = CABIN;
    rms[WEEPINGWILLOW].exits_to_room[EAST] = GROCERY;
    rms[WEEPINGWILLOW].exits_to_room[SOUTH] = REDWOOD;
    rms[WEEPINGWILLOW].exits_to_room[WEST] = NONE;

    rms[GROCERY].description.assign("grocery store");
    rms[GROCERY].exits_to_room[NORTH] = NONE;
    rms[GROCERY].exits_to_room[EAST] = NONE;
    rms[GROCERY].exits_to_room[SOUTH] = NONE;
    rms[GROCERY].exits_to_room[WEST] = WEEPINGWILLOW;

    rms[WATERFALL].description.assign("waterfall area");
    rms[WATERFALL].exits_to_room[NORTH] = NONE;
    rms[WATERFALL].exits_to_room[EAST] = REDWOOD;
    rms[WATERFALL].exits_to_room[SOUTH] = BOATRIDE;
    rms[WATERFALL].exits_to_room[WEST] = NONE;

    rms[REDWOOD].description.assign("Redwood Trees");
    rms[REDWOOD].exits_to_room[NORTH] = WEEPINGWILLOW;
    rms[REDWOOD].exits_to_room[EAST] = BUTTERFLY;
    rms[REDWOOD].exits_to_room[SOUTH] = NONE;
    rms[REDWOOD].exits_to_room[WEST] = WATERFALL;

    rms[BUTTERFLY].description.assign("swarms of butterflies");
    rms[BUTTERFLY].exits_to_room[NORTH] = NONE;
    rms[BUTTERFLY].exits_to_room[EAST] = NONE;
    rms[BUTTERFLY].exits_to_room[SOUTH] = NONE;
    rms[BUTTERFLY].exits_to_room[WEST] = REDWOOD;

    rms[BOATRIDE].description.assign("boat ride around the waterfall");
    rms[BOATRIDE].exits_to_room[NORTH] = WATERFALL;
    rms[BOATRIDE].exits_to_room[EAST] = PANDO;
    rms[BOATRIDE].exits_to_room[SOUTH] = NONE;
    rms[BOATRIDE].exits_to_room[WEST] = NONE;

    rms[PANDO].description.assign("Pando Trees");
    rms[PANDO].exits_to_room[NORTH] = NONE;
    rms[PANDO].exits_to_room[EAST] = NONE;
    rms[PANDO].exits_to_room[SOUTH] = NONE;
    rms[PANDO].exits_to_room[WEST] = BOATRIDE;

    rms[LOG].description.assign("Log Cabin");
    rms[LOG].exits_to_room[NORTH] = NONE;
    rms[LOG].exits_to_room[EAST] = EVERGREEN;
    rms[LOG].exits_to_room[SOUTH] = MOUNTAINS;
    rms[LOG].exits_to_room[WEST] = NONE;

    rms[EVERGREEN].description.assign("Evergreen Trees");
    rms[EVERGREEN].exits_to_room[NORTH] = NONE;
    rms[EVERGREEN].exits_to_room[EAST] = LILYPAD;
    rms[EVERGREEN].exits_to_room[SOUTH] = NONE;
    rms[EVERGREEN].exits_to_room[WEST] = LOG;

    rms[LILYPAD].description.assign("Lily Pad Trails");
    rms[LILYPAD].exits_to_room[NORTH] = NONE;
    rms[LILYPAD].exits_to_room[EAST] = CAMP;
    rms[LILYPAD].exits_to_room[SOUTH] = ASPEN;
    rms[LILYPAD].exits_to_room[WEST] = EVERGREEN;

    rms[ASPEN].description.assign("Aspen Trees");
    rms[ASPEN].exits_to_room[NORTH] = LILYPAD;
    rms[ASPEN].exits_to_room[EAST] = NONE;
    rms[ASPEN].exits_to_room[SOUTH] = NONE;
    rms[ASPEN].exits_to_room[WEST] = NONE;

    rms[CAMP].description.assign("Camp Site");
    rms[CAMP].exits_to_room[NORTH] = NONE;
    rms[CAMP].exits_to_room[EAST] = COTTONWOOD;
    rms[CAMP].exits_to_room[SOUTH] = CONVENIENCE;
    rms[CAMP].exits_to_room[WEST] = LILYPAD;

    rms[CONVENIENCE].description.assign("Convenience Store");
    rms[CONVENIENCE].exits_to_room[NORTH] = CAMP;
    rms[CONVENIENCE].exits_to_room[EAST] = COTTONWOOD;
    rms[CONVENIENCE].exits_to_room[SOUTH] = NONE;
    rms[CONVENIENCE].exits_to_room[WEST] = NONE;

    rms[COTTONWOOD].description.assign("Cottonwood Trees");
    rms[COTTONWOOD].exits_to_room[NORTH] = NONE;
    rms[COTTONWOOD].exits_to_room[EAST] = NONE;
    rms[COTTONWOOD].exits_to_room[SOUTH] = EASTERN;
    rms[COTTONWOOD].exits_to_room[WEST] = CAMP;

    rms[EASTERN].description.assign("Eastern Waterfall");
    rms[EASTERN].exits_to_room[NORTH] = COTTONWOOD;
    rms[EASTERN].exits_to_room[EAST] = NONE;
    rms[EASTERN].exits_to_room[SOUTH] = NONE;
    rms[EASTERN].exits_to_room[WEST] = NONE;
}

void set_directions(vector<Words> &dir) {
    // if(debug) cout << "starting set_directions().\n";
    dir[NORTH].code = NORTH;
    dir[NORTH].word = "NORTH";
    dir[EAST].code = EAST;
    dir[EAST].word = "EAST";
    dir[SOUTH].code = SOUTH;
    dir[SOUTH].word = "SOUTH";
    dir[WEST].code = WEST;
    dir[WEST].word = "WEST";
}

void set_verbs(vector<Words> &vbs) {
    // if(debug) cout << "starting set_verbs().\n";
    enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK, SLEEP, RELAX};

    vbs[GET].code = GET;
    vbs[GET].word = "GET";
    vbs[DROP].code = DROP;
    vbs[DROP].word = "DROP";
    vbs[USE].code = USE;
    vbs[USE].word = "USE";
    vbs[OPEN].code = OPEN;
    vbs[OPEN].word = "OPEN";
    vbs[CLOSE].code = CLOSE;
    vbs[CLOSE].word = "CLOSE";
    vbs[EXAMINE].code = EXAMINE;
    vbs[EXAMINE].word = "EXAMINE";
    vbs[INVENTORY].code = INVENTORY;
    vbs[INVENTORY].word = "INVENTORY";
    vbs[LOOK].code = LOOK;
    vbs[LOOK].word = "LOOK";
    vbs[SLEEP].code = SLEEP;
    vbs[SLEEP].word = "SLEEP";
    vbs[RELAX].code = RELAX;
    vbs[RELAX].word = "RELAX";
}

void set_nouns(vector<Noun> &nns) {
    // if(debug) cout << "starting set_nouns().\n";
    enum en_NOUNS {GATE_DOOR, SUNGLASSES, SHOES, CAMERA, MONEY, BACKPACK, WATERBOTTLE, SUNSCREEN, HEADPHONES, BICYCLE, HAT, MASONJAR, BOAT, PICNICBASKET, TENT};

    nns[GATE_DOOR].word = "DOOR";
    nns[GATE_DOOR].code = GATE_DOOR;
    nns[GATE_DOOR].description = "a closed gate";
    nns[GATE_DOOR].can_carry = false;
    nns[GATE_DOOR].location = WEEPINGWILLOW;
    nns[GATE_DOOR].inventory = false;
    nns[SUNGLASSES].word = "SUNGLASSES";
    nns[SUNGLASSES].code = SUNGLASSES;
    nns[SUNGLASSES].description = "sunglasses";
    nns[SUNGLASSES].can_carry = true;
    nns[SUNGLASSES].location = HOTSPRINGS;
    nns[SUNGLASSES].inventory = false;
    nns[SHOES].word = "SHOES";
    nns[SHOES].code = SHOES;
    nns[SHOES].description = "a pair of running shoes";
    nns[SHOES].can_carry = true;
    nns[SHOES].location = NATURETRAIL;
    nns[SHOES].inventory = false;
    nns[CAMERA].word = "CAMERA";
    nns[CAMERA].code = CAMERA;
    nns[CAMERA].description = "a camera to capture photos";
    nns[CAMERA].can_carry = true;
    nns[CAMERA].location = GARDENS;
    nns[CAMERA].inventory = false;
    nns[MONEY].word = "MONEY";
    nns[MONEY].code = MONEY;
    nns[MONEY].description = "some money to go shopping";
    nns[MONEY].can_carry = true;
    nns[MONEY].location = GROCERY;
    nns[MONEY].inventory = false;
    nns[BACKPACK].word = "BAG";
    nns[BACKPACK].code = BACKPACK;
    nns[BACKPACK].description = "a backpack filled with necessities";
    nns[BACKPACK].can_carry = true;
    nns[BACKPACK].location = MOUNTAINS;
    nns[BACKPACK].inventory = false;
    nns[WATERBOTTLE].word = "WATER";
    nns[WATERBOTTLE].code = WATERBOTTLE;
    nns[WATERBOTTLE].description = "a water bottle to quench your thirst";
    nns[WATERBOTTLE].can_carry = true;
    nns[WATERBOTTLE].location = NATURETRAIL;
    nns[WATERBOTTLE].inventory = false;
    nns[SUNSCREEN].word = "SPF";
    nns[SUNSCREEN].code = SUNSCREEN;
    nns[SUNSCREEN].description = "a bottle of sunscreen";
    nns[SUNSCREEN].can_carry = true;
    nns[SUNSCREEN].location = HOTSPRINGS;
    nns[SUNSCREEN].inventory = false;
    nns[HEADPHONES].word = "HEADPHONES";
    nns[HEADPHONES].code = HEADPHONES;
    nns[HEADPHONES].description = "a pair of sound proof headphones";
    nns[HEADPHONES].can_carry = true;
    nns[HEADPHONES].location = LILYPAD;
    nns[HEADPHONES].inventory = false;
    nns[BICYCLE].word = "BICYCLE";
    nns[BICYCLE].code = BICYCLE;
    nns[BICYCLE].description = "a vintage bicycle";
    nns[BICYCLE].can_carry = true;
    nns[BICYCLE].location = NATURETRAIL;
    nns[BICYCLE].inventory = false;
    nns[HAT].word = "HAT";
    nns[HAT].code = HAT;
    nns[HAT].description = "a hat to shade your eyes from the sun";
    nns[HAT].can_carry = true;
    nns[HAT].location = MOUNTAINS;
    nns[HAT].inventory = false;
    nns[MASONJAR].word = "JAR";
    nns[MASONJAR].code = MASONJAR;
    nns[MASONJAR].description = "a mason jar to capture butterlies";
    nns[MASONJAR].can_carry = true;
    nns[MASONJAR].location = BUTTERFLY;
    nns[MASONJAR].inventory = false;
    nns[BOAT].word = "BOAT";
    nns[BOAT].code = BOAT;
    nns[BOAT].description = "a boat with fishing rods";
    nns[BOAT].can_carry = true;
    nns[BOAT].location = BOATRIDE;
    nns[BOAT].inventory = false;
    nns[PICNICBASKET].word = "BASKET";
    nns[PICNICBASKET].code = PICNICBASKET;
    nns[PICNICBASKET].description = "a picnic basket filled with goodies";
    nns[PICNICBASKET].can_carry = true;
    nns[PICNICBASKET].location = CAMP;
    nns[PICNICBASKET].inventory = false;
    nns[TENT].word = "TENT";
    nns[TENT].code = TENT;
    nns[TENT].description = "a massive tent for your family";
    nns[TENT].can_carry = true;
    nns[TENT].location = CAMP;
    nns[TENT].inventory = false;
}

void section_command(string Cmd, string &wd1, string &wd2) {
    // if(debug) {
    //     cout << "Starting section_command().\n";
    //     cout << "Cmd = " << endl;
    //     cout << "wd1 = " << endl;
    //     cout << "wd2 = " << endl;
    // }
    string sub_str;
    vector<string> words;
    char search = ' ';
    short i, j;

    for(i = 0; i < Cmd.size(); i++) 
    {
        if(Cmd.at(i) != search)
        {
            sub_str.insert(sub_str.end(), Cmd.at(i));
        }
        if(i == Cmd.size() - 1)
        {
            words.push_back(sub_str);
            sub_str.clear();
        }
        if(Cmd.at(i) == search)
        {
            words.push_back(sub_str);
            sub_str.clear();
        }
    }
    for(i = words.size() - 1; i > 0; i--)
    {
        if(words.at(i) == "")
        {
            words.erase(words.begin() + i);
        }
    }
    for(i = 0; i < words.size(); i++)
    {
        for(j = 0; j < words.at(i).size(); j++)
        {
            if(islower(words.at(i).at(j)))
            {
                words.at(i).at(j) = toupper(words.at(i).at(j));
            }
        }
    }
    if(words.size() == 0)
    {
        cout << "No command given" << endl;
    }
    if(words.size() == 1)
    {
        wd1 = words.at(0);
    }
    if(words.size() == 2)
    {
        wd1 = words.at(0);
        wd2 = words.at(1);
    }
    if(words.size() > 2)
    {
        cout << "Command too long. Only type one or two words (direction or verb and noun)" << endl;
    }
}

void look_around(int loc, vector<Room> &rms, vector<Words> &dir, vector<Noun> &nns)
{
    // if(debug) cout << "Starting look_around().\n";

    int i;
    cout << "I am in the " << rms[loc].description << "." << endl;

    for(i = 0; i < DIRS; i++)
    {
        if(rms[loc].exits_to_room[i] != NONE)
        {
            cout << "There is an exit " << dir[i].word << " to a " << rms[rms[loc].exits_to_room[i]].description << "." << endl;
        }
    }
    
    // The look command should check which objects (nouns) are in the current room and report them to the player.
    for(i = 0; i < NOUNS; i++) 
    {
        if(nns[i].location == loc)
        {
            cout << "I see " << nns[i].description << "." << endl;
        }
    }
}

void get_item(int loc, vector<Noun> &nns, string wd2)
{
    int i;
    for(i = 0; i < NOUNS; i++)
    {
        if(nns[i].location == loc && nns[i].word == wd2)
        {
            if(nns[i].can_carry != false)
            {
                nns[i].inventory = true;
                cout << "You now have " << nns[i].word << endl;
            }
            else
            {
                cout << "That is not an option." << endl;
            }
        }
    }
}

void inventory(vector<Noun> &nns)
{
    int i, numItems;
    numItems = 0;
    
    cout << "These are items in your inventory: " << endl;
    for(i = 0; i < NOUNS; i++)
    {
        if(nns[i].inventory == true)
        {
            cout << nns[i].word << endl;
            numItems++;
        }
    }
    if(numItems == 0)
    {
        cout << "There is nothing in your inventory at this time." << endl;
    }
}

void examine(vector<Noun> &nns)
{
    int i, numItems;
    numItems = 0;
    
    cout << "Details on your inventory:" << "\nThere is:" << endl;
    for(i = 0; i < NOUNS; i++)
    {
        if(nns[i].inventory == true)
        {
            cout << nns[i].description << "!" << endl;
            numItems++;
        }
    }
    if(numItems == 0)
    {
        cout << "...Nothing here to examine in your inventory...\n" << endl;
    }             
}

// void drop(int loc, vector<Noun> &nns, vector<Words> &vbs, vector<Room> &rms)
// {
//     int i;

//     for(i = 0; i< NOUNS; i++)
//     {
//         if(nns[i].inventory == true)
//         {
            
//             cout << "You have dropped " << i << nns[i].location << endl;
//             cout << "New inventory is: " << nns[i].inventory << endl;
            
//         }  
//     }
// }

// void drop(int loc, vector<Noun> &nns, vector<Words> &vbs)
// {
//     int i;
//     cout << "You have removed " << nns[i].word << " from your inventory." << endl;
    
// }

bool parser(int &loc, string wd1, string wd2, vector<Words> &dir, vector<Words> &vbs, vector<Room> &rms, vector<Noun> &nns) {
    // if(debug) {
    //     cout << "Starting parser().\n";
    //     cout << "loc = " << loc << endl;
    //     cout << "wd1 " << wd1 << endl;
    //     cout << "wd2 " << wd2 << endl;
    //     cout << "first dir in dir = " << (*dir).word << endl;
    //     cout << "first verb in vbs = " << (*vbs).word << endl;
    //     cout << "first room in rms = " << (*rms).description << endl;
    //     cout << "first noun in nns = " << (*nns).word << endl;
    // }

    static bool doorIsOpen = false;     // false is closed door

    int i;
    for(i = 0; i < DIRS; i++)
    {
        if(wd1 == dir[i].word)
        {
            if(rms[loc].exits_to_room[dir[i].code] != NONE)
            {
                loc = rms[loc].exits_to_room[dir[i].code];
                cout << "I have now entered the " << rms[loc].description << "." << endl;

                // A special case for the corridor storeroom door.
                // grocery and weepingwillow gate
                if(loc == GROCERY || loc == WEEPINGWILLOW)
                {
                    nns[GATE_DOOR].location = loc;
                }
                return true;
            }
            else
            {
                cout << "No exit that way." << endl;
                return true;
            }
        }
    }

    int VERB_ACTION = NONE;

    int NOUN_MATCH = NONE;

    for(i = 0; i < VERBS; i++)
    {
        if(wd1 == vbs[i].word)
        {
            VERB_ACTION = vbs[i].code;
            break;
        }
    }

    if(wd2 != "")
    {
        for(i = 0; i < NOUNS; i++)
        {
            if(wd2 == nns[i].word)
            {
                NOUN_MATCH = nns[i].code;
                break;
            }
        }
    }

    // if(debug) {
    //     cout << "verb action = " << VERB_ACTION << endl;
    //     cout << "noun match = " << NOUN_MATCH << endl;
    // }

    if(VERB_ACTION == NONE)
    {
        cout << "No valid command entered." << endl;
        return true;
    }

    // if(VERB_ACTION == DROP)
    // {
    //     drop(loc, nns, vbs);        
    // }
    // if(VERB_ACTION == DROP)
    // {
    //     drop(loc, nns, vbs, rms);
    // }
    if(VERB_ACTION == SLEEP)
    {
        if(NOUN_MATCH == TENT && loc == CAMP)
        {
            if(nns[i].inventory == true)
            {
                cout << "Mission Accomplished: I get to finally sleep!" << endl;
            }
        }
        else if(nns[i].inventory == false)
        {
            cout << "I'm so sorry you don't have the supplies to sleep at this time. Try finding the Camping site!" << endl;
        }
    }
    if(VERB_ACTION == RELAX)
    {
        if((NOUN_MATCH == SUNGLASSES || NOUN_MATCH == SUNSCREEN) && loc == HOTSPRINGS)
        {
            if(nns[i].inventory == true)
            {
                cout << "Hooray! I am relaxing finally!" << endl;
            }
        }
        else if(nns[i].inventory == false)
        {
            cout << "I'm so sorry you don't have supplies to relax at this time. Try visiting the HotSprings to find some relaxation time!" << endl;
        }
    }
    if(VERB_ACTION == EXAMINE)
    {
        examine(nns);
    }

    if(VERB_ACTION == INVENTORY)
    {
        inventory(nns);
    }
   
    if(VERB_ACTION == GET)
    {
        get_item(loc, nns, wd2);
    }

    if(VERB_ACTION == LOOK)
    {
        look_around(loc, rms, dir, nns);
        return true;
    } 

    if(VERB_ACTION == CLOSE)
    {
        if(NOUN_MATCH == GATE_DOOR)
        {
            if(loc == WEEPINGWILLOW || loc == GROCERY)
            {
                if(doorIsOpen == true)
                {
                    doorIsOpen = false;
                    rms[WEEPINGWILLOW].exits_to_room[EAST] = GROCERY;
                    rms[GROCERY].exits_to_room[WEST] = WEEPINGWILLOW;
                    nns[GATE_DOOR].description.clear();
                    nns[GATE_DOOR].description.assign("a closed gate");
                    cout << "I have closed the gate." << endl;
                    return true;
                }
            }
            else if (doorIsOpen == false)
            {
                cout << "The gate is already closed." << endl;
                return true;
            }
        }
        else 
        {
            cout << "There is no gate to close here." << endl;
            return true;
        }
    }

    if(VERB_ACTION == OPEN)
    {
        if(NOUN_MATCH == GATE_DOOR)
        {
            if(loc == WEEPINGWILLOW || loc == GROCERY)
            {
                if(doorIsOpen == false)
                {
                    doorIsOpen = true;
                    rms[WEEPINGWILLOW].exits_to_room[EAST] = GROCERY;
                    rms[GROCERY].exits_to_room[WEST] = WEEPINGWILLOW;
                    nns[GATE_DOOR].description.clear();
                    nns[GATE_DOOR].description.assign("an open gate");
                    cout << "I have opened the gate." << endl;
                    return true;
                }
            }
            else if (doorIsOpen == true)
            {
                cout << "The gate is already open." << endl;
                return true;
            }
        }
        else
        {
            cout << "There is no gate to open here." << endl;
            return true;
        }
    }
    return false;
}

int main() {
    // if(debug) cout << "Starting main().\n";
    string command;
    string word_1;
    string word_2;

   

    // Room rooms[ROOMS];
    // set_rooms(rooms);
    // const int ROOMS = 11;
    vector<Room> rooms(FOREST);
    set_rooms(rooms);

    // Words directions[DIRS];
    // set_directions(directions);
    // const in DIRS = 4;
    vector<Words> directions(DIRS);
    set_directions(directions);

    // Words verbs[VERBS];
    // set_verbs(verbs);
    // const int VERBS = 8;
    vector<Words> verbs(VERBS);
    set_verbs(verbs);

    // Noun nouns[NOUNS];
    // set_nouns(nouns);
    // const int NOUNS = 6;
    vector<Noun> nouns(NOUNS);
    set_nouns(nouns);

    int location = NATURETRAIL;

    // if(debug) cout << "Setup is complete. Starting the main game loop.\n";

    while(word_1 != "QUIT")
    {
        command.clear();
        cout << "What shall I do? ";
        getline(cin, command);

        word_1.clear();
        word_2.clear();

        section_command(command, word_1, word_2);

        if(word_1 != "QUIT")
        {
            parser(location, word_1, word_2, directions, verbs, rooms, nouns);
        }
    }
    return 0;
} 
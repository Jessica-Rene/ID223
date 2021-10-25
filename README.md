# ID223
C++
## Description of Assignement:

welcome the player <br />
set up the game  <br />
    int health = 10, attack, block, turns = 0 <br />
    seed the random number generator <br />
start the loop <br /> 
    add 1 to turns  <br />
    start the encounter <br />
        randomly generate numbers for attack (range = 0-4) and block (range = 0-4) <br />
        if block is greater or equal to attack, successful block <br />
        otherwise, subtract attack value from health. <br />
keep looping while health is greater than zero and fewer than 4 turns have happened <br />

if health is greater than 0, congratulate player <br />
otherwise, tell the player they're dead. <br />

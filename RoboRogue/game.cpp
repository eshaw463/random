#include <iostream>  
// Dead project but it was good practice. I should have figured out the actual gameplay before everything else. 
// Could have also though of a fun game idea instead of a terminal text rpg. 

#include <string>
#include <cmath>
#include <vector>

#include "yourRobot.cpp"
#include "enemyBot.cpp"

#define ll long long


// Main functions. Had this in a seperate file but I ended up with circular includes statements.
// This is why I would need a header with functions. But I can't just have a header with includes because it creates a loop.
// Basically unlike Java, C++ doesn't already see the other files, so only this file (game.cpp) can see the other two

void ggs(){
    std::cout<< "You lost. Restart to try again. Thank you for playing!" << std::endl;

    exit(0);
}

void turns(yourRobot rob, enemyBot eBot){
    // input robots and then do turn order & attacks & stuff
    int ttt = 0;
    bool fightOver = false;

    while (ttt != -1){
        if (rob.getHp() <= 0 || eBot.getHp() <= 0) fightOver = true;

        if (fightOver) break;


        if(ttt % 2 == 0){
            // even turn
            std::cout<< eBot.getName() << " hp: " << eBot.getHp() << std::endl;
            std::cout<< rob.getName() << " hp: " << rob.getHp() << std::endl;

            rob.combatActions();

        } else {
            // odd turn
            std::cout<< eBot.getName() << " hp: " << eBot.getHp() << std::endl;
            std::cout<< rob.getName() << " hp: " << rob.getHp() << std::endl;

            // enemy combat actions !!!!!!
        }

        ttt++;
        // never ending loop, will break out of when fight ends
    }
    if (fightOver && rob.getHp() <= 0){

        rob.printStats();
        ggs();
    }
}

void round1_2(){
    // random enemy bot creations
    // call turns
}

void round3_4(){

}

void round5_6(){

}

void round7_8(){

}

void round9(){

}

void round10(){

}

void upgrades(){
    // upgrades, random choice of 3 parts or something
}




int main(){
    std::cout<< "Your heard beats with the pace of racing horces, each quick stomp on the mud- a convulsion of your coronary muscles." << std::endl;
    std::cout<< "You finally made it. You arrived at your destination." << std::endl;

    std::cout<< "Welcome to RoboRogue. Now is your chance to prove yourself & your robotics skills in the arena." << std::endl;
    std::cout<< "Endless opprotunities await for the winner of each tournament, and you might just be able to win." << std::endl;
    std::cout<< "That is... after you can build your robot." << std::endl;

    std::cout<< "" << std::endl;
    std::cout<< "Design your robot. You have 10 points to allocate." << std::endl;
    std::cout<< "What is its name?" << std::endl;
    std::string nameIn;
    std::cin >> nameIn;

    yourRobot rob(nameIn,1,1,1,1,1,0);
    std::cout<< "Stats: " << std::endl;
    rob.printStats();
    int pointsToAllocate = 10;

    while (pointsToAllocate > 0){
    int adder = 0;
    bool valid = false;

    while (!valid){
    std::cout<< "How many points will you add to hp?" << std::endl;
    std::cin >> adder;
    if (adder <= pointsToAllocate) {
        valid = true;
        rob.addHp(adder);
        pointsToAllocate-=adder;
    } else {std::cout<< "invalid entry" << std::endl;}

    }
    valid = false;
    while (!valid){
    std::cout<< "How many points will you add to atk?" << std::endl;
    std::cin >> adder;
    if (adder <= pointsToAllocate) {
        valid = true;
        rob.addAtk(adder);
        pointsToAllocate-=adder;
    } else {std::cout<< "invalid entry" << std::endl;}

    }
    valid = false;
    while (!valid){
    std::cout<< "How many points will you add to def?" << std::endl;
    std::cin >> adder;
    if (adder <= pointsToAllocate) {
        valid = true;
        rob.addDef(adder);
        pointsToAllocate-=adder;
    } else {std::cout<< "invalid entry" << std::endl;}

    }
    valid = false;
    while (!valid){
    std::cout<< "How many points will you add to speed?" << std::endl;
    std::cin >> adder;
    if (adder <= pointsToAllocate) {
        valid = true;
        rob.addSpeed(adder);
        pointsToAllocate-=adder;
    } else {std::cout<< "invalid entry" << std::endl;}

    }
    valid = false;
    while (!valid){
    std::cout<< "How many points will you add to flip?" << std::endl;
    std::cin >> adder;
    if (adder <= pointsToAllocate) {
        valid = true;
        rob.addFlip(adder);
        pointsToAllocate-=adder;
    } else {std::cout<< "invalid entry" << std::endl;}

    }
    }
    std::cout<< "This is your robot" << std::endl;
    rob.printStats();
    
    std::cout<< "Before you are finished, an organizer of the event approaches you. \n'How about you add an extra part to your robot, they say. Expense if on me.'" << std::endl;
    upgrades();

    std::cout<< "Round 1 Begins!" << std::endl;
    round1_2();
    std::cout<< "Victory in Round 1!" << std::endl;
    upgrades();

    std::cout<< "Round 2 Begins!" << std::endl;
    round1_2();
    std::cout<< "Victory in Round 2!" << std::endl;
    upgrades();

    std::cout<< "Round 3 Begins!" << std::endl;
    round3_4();
    std::cout<< "Victory in Round 3!" << std::endl;
    upgrades();

    std::cout<< "Round 4 Begins!" << std::endl;
    round3_4();
    std::cout<< "Victory in Round 4!" << std::endl;
    upgrades();

    std::cout<< "Round 5 Begins!" << std::endl;
    round5_6();
    std::cout<< "Victory in Round 5!" << std::endl;
    upgrades();

    std::cout<< "Round 6 Begins!" << std::endl;
    round5_6();
    std::cout<< "Victory in Round 6!" << std::endl;
    upgrades();

    std::cout<< "Round 7 Begins!" << std::endl;
    round7_8();
    std::cout<< "Victory in Round 7!" << std::endl;
    upgrades();

    std::cout<< "Round 8 Begins!" << std::endl;
    round1_2();
    std::cout<< "Victory in Round 8!" << std::endl;
    upgrades();

    std::cout<< "Round 9 Begins!" << std::endl;
    round9();
    std::cout<< "Victory in Round 9!" << std::endl;
    upgrades();

    std::cout<< "Round 10 Begins!" << std::endl;
    round10();
    std::cout<< "Victory in Round 10!" << std::endl;

    // Winning message, credits, return 0; 




    // to add: 10 rounds, uprgade processes after each round, damage calcs, enemy robots

    //Rogue choice (choose which part to add or something like that, maybe a sponsorship, etc)
    // then do a round, repeat
    
    // I would like to make it more complex but like... it is what it is. I can add complexity with special parts that add
    // new options in combat that can do crazy things to stats
    // choose to put some of these on specific enemy bots bots

    // then add display LMAO
    // and/or colored text

    // could honestly make this a top-down shooter instead in the future if I really wanted to
    // battlebots roguelike
}
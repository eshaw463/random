#include <string>
#include <iostream>

// bot AI ideas: runaway bot that runs away and you need speed or luck for, can also have rushdown & alternate
// brute force bot
// flame bot
// flipper bot
// rest will just be some stat builds

class enemyBot{

    std::string name;
    int hp;
    int atk;
    int def;
    int speed;
    int flip;
    int fire;

    public:
        enemyBot(std::string n, int h, int a, int d, int s, int fl, int fi){
            name = n;
            hp = h;
            atk = a;
            def = d;
            speed = s;
            flip = fl;
            fire = fi;
        }

        std::string getName() {return name;}
        int getHp() {return hp;}
        int getAtk() {return atk;}
        int getDef()  {return def;}
        int getSpeed() {return speed;}
        int getFlip() {return flip;}
        int getFire() {return fire;}

        void printStats(){
            std::cout<< name << std::endl;
            std::cout<< "hp: " << hp << std::endl;
            std::cout<< "atk: " << atk << std::endl;
            std::cout<< "def: " << def << std::endl;
            std::cout<< "speed: " << speed << std::endl;
            std::cout<< "flip: " << flip << std::endl;
            std::cout<< "fire: " << fire << std::endl;
        }

        void addHp(int num) {hp += num;}
        void addAtk(int num) {atk += num;}
        void addDef(int num)  {def += num;}
        void addSpeed(int num) {speed += num;}
        void addFlip(int num) {flip += num;}
        void addFire(int num) {fire += num;}

        void takeDamage();
        void tryToFlip();

        void combatActions(){}

    private:
};
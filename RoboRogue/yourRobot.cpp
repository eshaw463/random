#include <string>
#include <iostream>



class yourRobot{

    std::string name;
    int hp;
    int atk;
    int def;
    int speed; // determines who goes first and also damage of some attacks
    int flip;
    int fire;

    bool mini_flamethrower = false;
    bool flipper = false;
    bool explosive_round = false;

    bool gOn;
    bool rOn;

    public:
        yourRobot(std::string n, int h, int a, int d, int s, int fl, int fi){
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

        void takeDamage(int enemyAtk){
            bool escaped = false;

            if (gOn){} // semirandom chance to guard the attack based on def
                // chance for enemy to take self damage from recoil
            if (rOn){} // semirandom chance to avoid the attack based on speed
                // chance for enemy to hit a wall & take self damage 

            if (!escaped){
            switch (enemyAtk){
                case 0: // damage calcs
                case 1:
                case 4:
                case 5:
                case 6:
                }
            }

            rOn = false;
            gOn = false;
        }



        void tryToFlip();

        void combatActions(){
            std::cout<< name << "'s turn." << std::endl;
            
            std::cout<< "Actions: \n" << "[0] Careful Attack, \n" << "[1] Rushdown Attack, \n" << "[2] Guard, \n" << "[3] Run, \n";
            if (mini_flamethrower) std::cout<< "[4] Spray Fire, \n";
            if (flipper) std::cout<< "[5] Flip Opponent, \n";
            if (explosive_round) std::cout<< "[6] Explosive Round, \n";
            std::cout << "[9] See Stats" << std::endl;


            int act = 0;
            bool validIn = false;

            while (!validIn){
                std::cin >> act;
                switch (act){
                    case 0: validIn=true;
                    case 1: validIn=true;
                    case 2: validIn=true; std::cout<< "You attempted to guard." << std::endl; gOn = true;
                    case 3: validIn=true; std::cout<< "You attempted to run." << std::endl; rOn = true;

                    case 4:
                        if (mini_flamethrower) {validIn=true;}
                        else std::cout<< "Invalid Input" << std::endl;
                    case 5:
                        if (flipper) {validIn=true;}
                        else std::cout<< "Invalid Input" << std::endl;
                    case 6:
                        if (explosive_round) {validIn=true;}
                        else std::cout<< "Invalid Input" << std::endl;
                    case 9:
                        printStats();
                        // should print enemy stats too somehow, ig this cpp can include the other but not vice versa??? 
                        // I wish they could see each other bc I might need it for damage calcs

                    default: std::cout<< "Invalid Input" << std::endl;
                }
            }
        }

    private:
};
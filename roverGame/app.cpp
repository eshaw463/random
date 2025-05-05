#include <iostream>


std::string game[20][40];
void draw();
void spaceFill();
void handleInput();

int plX = 19;
int plY = 9;

int main(){

	std::cout<<"Hello World"<<std::endl;

	spaceFill();
	draw();


	bool run = true;
	while (run) {
		handleInput();
	}


	return 0;
}

void spaceFill(){
	for (int i = 0; i < 20; i++){
		for (int k = 0; k < 40; k++){
			game[i][k] = ".";
		}	
	}
}

void draw(){

	for (int i = 0; i < 20; i++){
		game[i][0] = "#";
		game[i][39] = "#";
	}

	for (int i = 0; i < 40; i++){
		game[0][i] = "#";
		game[19][i] = "#";
	}

	game[plY][plX] = "A";
	


	for (int i = 0; i < 20; i++){
		for (int k = 0; k < 40; k++){
			std::cout<<game[i][k];
		}	
		std::cout<<""<<std::endl;
	}

}

void handleInput() {
    std::string input;
    std::cin >> input;

    game[plY][plX] = ".";

    for (int i = 0; i < input.length(); i++) { // I'll make movement vimlike later
        char current = input[i];	 	// I want to make it easy to tell whats going on with colors and a responsive drawing board that shows
						// where you would end up with colors indicating how much of movement it uses and which steps the path is
							// ngl I really want to make this java rn bc it would make it way easier but also I need to learn this
        switch (current) {
            case 'w':
                plY--;
                break;
            case 'a':
                plX--;
                break;
            case 'd':
                plX++;
                break;
            case 's':
                plY++;
                break;
        }
    }
	
    draw();
}


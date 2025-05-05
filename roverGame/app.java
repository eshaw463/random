import java.util.*;

class Rover{
    int hp = 1;
    int lvl = 1;
    String icon = "A";

    int x;
    int y;

    Rover(int bX, int bY){
        x=bX;
        y=bY;
    }
}



public class app {

    protected static String[][] game = new String[20][40]; // I don't want people to see without scouts so I want to make the board into separate parts
    protected static String[][] game2 = new String[20][40];
    protected static String[][] game3 = new String[20][40];
    protected static String[][] game4 = new String[20][40];
    protected static String[][] game5 = new String[20][40];
    protected static String[][] game6 = new String[20][40];

    // 1  2  3
    // 4  5  6

    // will implement movement between later


    // arrayList of rovers
    protected static ArrayList<Rover> teamA = new ArrayList<>(); // will incorporate limits later
    protected static ArrayList<Rover> teamB = new ArrayList<>();
    protected static Rover selectedRover;

    public static void main(String[] args) {

        loadData(); // should start the game by filling data into game
        draw();

        boolean run = true;
        while (run) {
            handleInput();
        }

    }

    public static void loadData() {
        for (int i = 0; i < 20; i++) {
            for (int k = 0; k < 40; k++) {
                game[i][k] = ".";
            }
        }

        teamA.add(new Rover(6,6));
        teamA.add(new Rover(8,8));
        teamA.add(new Rover(10,10));
        selectedRover = teamA.get(0);
        

    }

    static void draw() {

        for (int i = 0; i < 20; i++) {
            game[i][0] = "#";
            game[i][39] = "#";
        }

        for (int i = 0; i < 40; i++) {
            game[0][i] = "#";
            game[19][i] = "#";
        }

        for (Rover r: teamA){
            game[r.y][r.x] = "A";
        }

        for (Rover r: teamB){
            game[r.y][r.x] = "B";
        }

        for (int i = 0; i < 20; i++) {
            for (int k = 0; k < 40; k++) {
                System.out.print(game[i][k]);
            }
            System.out.println("");
        }


        // UI elements after

        int selRovName = 0;
        for (int i = 0; i < teamA.size(); i++){
            if (selectedRover == teamA.get(i)) selRovName = i;
        }

        System.out.println("Rover: " + selRovName);
    }

    static void handleInput() {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();

        String[] splitInput = input.split(" ");
        String command = splitInput[0];
        String argument = "noArg";

        try {
        argument = splitInput[1];
        } catch (Exception e){
            // lmao input better ig
        }
        

        switch (command) {
            case "m": // move
                move(argument, selectedRover);
                break;
            case "r": // switch robot
                selectBot(Integer.parseInt(argument));
                break;
            case "help": // display help menu
                break;
            case "info": // display info menu
                printInfo();
                break;
        }

    }

    static void move(String input, Rover r) {
        game[r.y][r.x] = "."; // removes where the rover used to be. Drawing will be redone with data soon

        for (int i = 0; i < input.length(); i++) { // I'll make movement vimlike later
            String current = input.substring(i, i + 1);	 	
            
            // I want to make it easy to tell whats going on with colors and a responsive drawing board that shows
            // where you would end up with colors indicating how much of movement it uses and which steps the path is
            
            switch (current) {
                case "w" ->
                    r.y--;
                case "a" ->
                    r.x--;
                case "d" ->
                    r.x++;
                case "s" ->
                    r.y++;
            }
        }

        draw();
    }

    static void selectBot(int bot){
        selectedRover = teamA.get(bot);
        draw();
    }

    static void printInfo(){
        int selRovName = 0;
        for (int i = 0; i < teamA.size(); i++){
            if (selectedRover == teamA.get(i)) selRovName = i;
        }

        System.out.println("Rover: "+ selRovName);
        System.out.println("hp: "+ selectedRover.hp + "   x: "+ selectedRover.x + "   y: "+ selectedRover.y);
        System.out.println("Level: "+ selectedRover.lvl);
    }

}

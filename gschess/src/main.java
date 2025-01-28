import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;
import java.util.jar.JarEntry;

public class main {

  // creating logic with text & terminal before I move to JFrame with buttons and images
  public static piece[][] board = new piece[32][48];
  private static boolean gameOver = false;
  private static int buttonMode = 0;
  private static String currentCol = "w";

  public static JButton[][] buttonsA = new JButton[32][48];

  public static int OLDY,OLDX;


  public static void main(String[] args) {

    for (int i = 0; i < 32; i++) {
      for (int j = 0; j < 48; j++) {
        board[i][j] = new empty("e"); //sets empty space
      }
    }


    jset();
    populate();
    redraw();

  }


  public static void redraw() {
    System.out.println();

    String RESET = "\u001B[0m";
    String YELLOW = "\u001B[33m";

    for (int i = 0; i < 32; i++) {
      System.out.println();
      for (int j = 0; j < 48; j++) {

        if (board[i][j].getColor().equals("b")) {
          //System.out.print(YELLOW + " " + board[i][j] + " " + RESET);
          // find a way to redraw to buttons
          buttonsA[i][j].setText(" " + board[i][j] + " ");
          buttonsA[i][j].setForeground(Color.orange);
          

        } else if (board[i][j].getColor().equals("w")) {
          //System.out.print(" " + board[i][j] + " ");
          //find a way to redraw to buttons
          buttonsA[i][j].setText(" " + board[i][j] + " ");
          buttonsA[i][j].setForeground(Color.white);

        } else {
          buttonsA[i][j].setText(" " + board[i][j] + " ");
          buttonsA[i][j].setForeground(Color.CYAN);
        }
      }
    }
  }

  public static void populate() {
    for (int i = 0; i < 8; i++) {
      board[30][20 + i] = new pawn("w");
      board[1][20 + i] = new pawn("b");
    }

    board[31][20] = new rook("w");
    board[31][21] = new knight("w");
    board[31][22] = new bishop("w");
    board[31][23] = new king("w");
    board[31][24] = new queen("w");
    board[31][25] = new bishop("w");
    board[31][26] = new knight("w");
    board[31][27] = new rook("w");

    board[0][20] = new rook("b");
    board[0][21] = new knight("b");
    board[0][22] = new bishop("b");
    board[0][23] = new queen("b");
    board[0][24] = new king("b");
    board[0][25] = new bishop("b");
    board[0][26] = new knight("b");
    board[0][27] = new rook("b");

  }

  public static void turns() {
    Scanner sc = new Scanner(System.in);

    gameOver = false;
    int turn = 1;

    while (!gameOver) {

      if (turn % 2 != 0){ // white moves
        currentCol = "w";


      } else { // black moves
        currentCol = "b";


      }


      checkOver();
      turn++;
    }

  }

  public static void checkOver(){
    int bKings = 0;
    int wKings = 0;

    for (int i = 0; i < 32; i++) {
      for (int j = 0; j < 48; j++) {

        if(board[i][j] instanceof king && board[i][j].getColor().equals("w")) wKings++;
        if(board[i][j] instanceof king && board[i][j].getColor().equals("b")) bKings++;

      }
    }

    if(wKings == 0){
      System.err.println("BLACK WINS");
      gameOver = true;
    } else if(bKings == 0){
      System.err.println("WHITE WINS");
      gameOver = true;
    }

  }

  public static void jset(){
    JFrame frame = new JFrame("GS-Chess");
    frame.setSize(960, 540);
    frame.setLocationRelativeTo(null);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setVisible(true);
    frame.setExtendedState(frame.getExtendedState() | JFrame.MAXIMIZED_BOTH);


    JPanel mainpanel = new JPanel();
    mainpanel.setBackground(new Color(20, 20, 20));
    GridBagLayout grid = new GridBagLayout();
    GridBagConstraints gbc = new GridBagConstraints();
    mainpanel.setLayout(grid);


    ActionListener BL = new ActionListener() {//all buttons
      public void actionPerformed(ActionEvent e) {
        buttonAction(e);
      }
    };


    JPanel[] panels = new JPanel[32];
    for (int i = 0; i < 32; i++) {
      panels[i] = new JPanel();
      panels[i].setBackground(new Color(20, 20, 20));
      panels[i].setLayout(new FlowLayout(FlowLayout.LEFT, 0, 0));
      gbc.gridx = 0;
      gbc.gridy = i;
      mainpanel.add(panels[i], gbc);


      for (int j = 0; j < 48; j++) {

        buttonsA[i][j] = new JButton();
        buttonsA[i][j].setPreferredSize(new Dimension(26, 22)); //26, 22
        buttonsA[i][j].setBackground(new Color(20, 20, 20));
        panels[i].add(buttonsA[i][j]);
        buttonsA[i][j].addActionListener(BL);
        buttonsA[i][j].setText(board[i][j].toString());

        buttonsA[i][j].setFont(new Font("Arial", Font.PLAIN, 10));
        buttonsA[i][j].setMargin(new Insets(0, 0, 0, 0));

        buttonsA[i][j].putClientProperty("x", i);
        buttonsA[i][j].putClientProperty("y", j);

      }
    }


    frame.add(mainpanel);
  }

  public static void buttonAction(ActionEvent e){
    JButton clickedButton = (JButton) e.getSource();
    int x = (int) clickedButton.getClientProperty("x");
    int y = (int) clickedButton.getClientProperty("y");

    if(buttonMode == 0){
      // select the button
    if(board[x][y].getColor().equals(currentCol)){
      if(board[x][y] instanceof pawn){
        ((pawn) board[x][y]).move();
        redraw();
      } else if (board[x][y] instanceof king){
        ((king) board[x][y]).move();
      } else if(board[x][y] instanceof queen){
        ((queen) board[x][y]).move();
      } else if(board[x][y] instanceof bishop){
        ((bishop) board[x][y]).move();
      } else if (board[x][y] instanceof knight) {
        ((knight) board[x][y]).move();
      } else if(board[x][y] instanceof rook){

      }
      buttonMode = 1;
    }

    } else if (buttonMode == 1){
      // move a piece here OR select if your own piece is here
      if(board[x][y].getColor().equals(currentCol)) {
        if (board[x][y] instanceof pawn) {
          ((pawn) board[x][y]).move();
        } else if (board[x][y] instanceof king) {
          ((king) board[x][y]).move();
        } else if (board[x][y] instanceof queen) {
          ((queen) board[x][y]).move();
        } else if (board[x][y] instanceof bishop) {
          ((bishop) board[x][y]).move();
        } else if (board[x][y] instanceof knight) {
          ((knight) board[x][y]).move();
        } else if (board[x][y] instanceof rook) {
          ((rook) board[x][y]).move();
        }
      } else {
        // do swap. Honestly would've been easier w/ just a button array from the beginning & swaps
      }

    }



  }


}

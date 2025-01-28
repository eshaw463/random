public class empty extends piece{
public int moveto = 0;

  public empty(String c){
    super(c);

    super.setColor("e");
  }


  public String toString(){
    if(moveto == 0){
      return " ";
    }
    return "v";
  }
}

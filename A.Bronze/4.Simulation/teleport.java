import java.util.*;
import java.io.*;

class teleport {
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new File("teleport.in"));
    int a = sc.nextInt();
    int b = sc.nextInt();
    int x = sc.nextInt();
    int y = sc.nextInt();

    int distance1 = Math.abs(a-b);

    int distance2 = Math.abs(Math.min(a,b)-Math.min(x,y))
                  + Math.abs(Math.max(a,b)-Math.max(x,y));

    FileWriter fw = new FileWriter("teleport.out");
    fw.write(Math.min(distance1, distance2) + "\n");
    fw.close();
  }
}
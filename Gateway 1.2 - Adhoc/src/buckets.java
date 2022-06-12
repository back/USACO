import java.io.*;
import java.util.*;

class buckets {
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new File("buckets.in"));

    int bX=0, bY=0, lX=0, lY=0, rX=0, rY=0;

    for(int i=0; i<10; i++){
      String line = sc.nextLine();
      if (line.indexOf('B')>-1) {
        bX = line.indexOf('B');
        bY = i;
      }
      if (line.indexOf('L')>-1) {
        lX = line.indexOf('L');
        lY = i;
      }
      if (line.indexOf('R')>-1) {
        rX = line.indexOf('R');
        rY = i;
      }
    }

    int xDis = Math.abs(bX - lX);
    int yDis = Math.abs(bY - lY);
    int ans = xDis + yDis - 1;

    if (xDis == 0 && rX == bX)
      if (rY > Math.min(bY,lY) && rY < Math.max(bY,lY))
        ans += 2;
    if (yDis == 0 && rY == bY)
      if (rX > Math.min(bX,lX) && rX < Math.max(bX,lX))
        ans += 2;


    FileWriter fw = new FileWriter("buckets.out");
    fw.write(ans + "\n");
    fw.close();
  }
}
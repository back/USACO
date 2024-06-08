import java.util.*;
import java.io.*;

class promote {
  public static void main(String[] args) throws Exception {

    Scanner sc = new Scanner(new File("promote.in"));

    int[] promo = new int[4];

    for(int i = 0; i<promo.length; i++) {
      int a = sc.nextInt();
      int b = sc.nextInt();
      promo[i] = b - a;
      sc.nextLine();
    }

    promo[2] += promo[3];
    promo[1] += promo[2];

    FileWriter fw = new FileWriter("promote.out");
    fw.write(promo[1] + "\n");
    fw.write(promo[2] + "\n");
    fw.write(promo[3] + "\n");
    fw.close();
  }
}
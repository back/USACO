import java.io.*;
import java.util.*;

class word {
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new File("word.in"));
    int n = sc.nextInt();
    int k = sc.nextInt();
    sc.nextLine();

    FileWriter fw = new FileWriter("word.out");

    int c = 0;
    for(String word: sc.nextLine().split(" ")){
      if (word.length() + c > k) {
        fw.write("\n");
        c = 0;
      }
      if (c>0) fw.write(" ");
      fw.write(word);
      c += word.length();
    }
    fw.write("\n");
    fw.close();
  }
}
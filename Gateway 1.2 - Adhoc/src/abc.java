import java.util.*;

class abc {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int[] n = new int[7];
    for(int i=0; i<n.length; i++) n[i] = sc.nextInt();

    Arrays.sort(n);

    System.out.print(n[0] + " ");
    System.out.print(n[1] + " ");
    System.out.println( (n[6]-n[0]-n[1]) );
  }
}
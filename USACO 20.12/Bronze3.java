import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Bronze3 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        int[][] c = new int[n][6];
        for (int i = 0; i < n; i++) {
            int direction = "E".equals(sc.next()) ? 1 : 2;
            int x = sc.nextInt();
            int y = sc.nextInt();
            sc.nextLine();
            c[i][0] = x + y;        // rank
            c[i][1] = i;            // serial position
            c[i][2] = direction;    // 1 means E, 2 means N
            c[i][3] = x;
            c[i][4] = y;
            c[i][5] = 0;            // final answer, how many grass covered (0 means infinite)
        }

        // Sorting by rank
        Arrays.sort(c, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return a[0] == b[0] ? a[1]-b[1] : a[0]-b[0];
            }
        });

        // Reverse processing: Make sure the higher ranked cows determined first
        for(int i=n-2; i>=0; i--)
            for(int j=i+1; j<n; j++) {
                if (c[i][2] == 1 && c[j][2] == 2)
                    if (c[i][4] > c[j][4] && c[i][0] < c[j][0])
                        if (c[j][5] == 0 || c[j][5] + c[j][4] >= c[i][4]) {
                            int blocked_length = c[j][3] - c[i][3];
                            if (c[i][5] == 0 || blocked_length < c[i][5])
                                c[i][5] = blocked_length;
                        }
                if (c[i][2] == 2 && c[j][2] == 1)
                    if (c[i][3] > c[j][3] && c[i][0] < c[j][0])
                        if (c[j][5] == 0 || c[j][5] + c[j][3] >= c[i][3]) {
                            int blocked_length = c[j][4] - c[i][4];
                            if (c[i][5] == 0 || blocked_length < c[i][5])
                                c[i][5] = blocked_length;
                        }
            }


        // Sort back by serial position for correct output
        Arrays.sort(c, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return a[1]-b[1];
            }
        });


        // output the final answer
        for(int[] x : c)
            System.out.println( x[5]>0 ? x[5] : "Infinity" );

    }
}

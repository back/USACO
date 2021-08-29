import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;



public class Silver2 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();

        int[][] data = new int[n][2];

        for (int i = 0; i < n; i++) {
            data[i][0] = sc.nextInt();
            data[i][1] = sc.nextInt();
            sc.nextLine();
        }

        // Sorting by x
        Arrays.sort(data, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return a[0] - b[0];
            }
        });

        int total = 1 + n;

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++) {
                boolean b = data[i][1] < data[j][1];
                int y0 = b ? data[i][1] : data[j][1];
                int y1 = b ? data[j][1] : data[i][1];

                int upper = 1;
                int lower = 1;

                for (int k = i + 1; k < j; k++)
                    if (data[k][1] > y1) upper++;
                    else if (data[k][1] < y0) lower++;

                total += upper * lower;
            }


        System.out.println(total);
    }
}

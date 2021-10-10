import java.io.*;
import java.util.*;

public class Silver1 {

    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(reader.readLine());

        Object[] data = new Object[n + 1];

        for (int i = 0; i < n - 1; i++) {
            String[] rd = reader.readLine().split(" ");
            int a = Integer.parseInt(rd[0]);
            int b = Integer.parseInt(rd[1]);
            if (data[a] == null) {
                data[a] = new ArrayList<Integer>();
            }
            ((ArrayList<Integer>) data[a]).add(b);
            if (data[b] == null) {
                data[b] = new ArrayList<Integer>();
            }
            ((ArrayList<Integer>) data[b]).add(a);
        }


        int[] k_cache = {0, 2, 4, 5, 7, 8, 9, 10, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106};

        int cost = 0;
        ArrayList<Integer> process = new ArrayList<Integer>();
        process.add(1);
        ArrayList<Integer> processed = new ArrayList<Integer>();

        while (!process.isEmpty()) {
            int i = process.remove(0);
            ArrayList<Integer> children = new ArrayList<Integer>();
            for (int c : (ArrayList<Integer>) data[i]) {
                if (!processed.contains(c))
                    children.add(c);
            }
            processed.add(i);
            if (!children.isEmpty()) {
                process.addAll(children);
                int k = children.size();
                if (k < k_cache.length)
                    cost += k_cache[k];
                else {
                    cost += k;
                    while (k > 0) {
                        k /= 2;
                        cost++;
                    }
                }
            }
        }
        System.out.println(cost);
    }
}

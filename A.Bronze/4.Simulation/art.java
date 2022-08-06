import java.io.*;

public class art {
    static final int MAX_COLOR = 9;

    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("art.in"));
        int width = Integer.parseInt(read.readLine());

        /*
         * Bounding boxes of each of the colors.
         * The first element won't be used (colors go from 1-9)
         */
        int[] left = new int[MAX_COLOR + 1];
        int[] right = new int[MAX_COLOR + 1];
        int[] down = new int[MAX_COLOR + 1];
        int[] up = new int[MAX_COLOR + 1];
        for (int c = 1; c <= MAX_COLOR; c++) {
            left[c] = up[c] = Integer.MAX_VALUE;
            right[c] = down[c] = -1;
        }
        
        boolean[] validStart = new boolean[MAX_COLOR + 1];
        int[][] art = new int[width][width];
        for (int r = 0; r < width; r++) {
            String row = read.readLine();
            for (int c = 0; c < width; c++) {
                int curr = Character.getNumericValue(row.charAt(c));
                art[r][c] = curr;
                if (curr != 0) {
                    left[curr] = Math.min(left[curr], c);
                    right[curr] = Math.max(right[curr], c);
                    down[curr] = Math.max(down[curr], r);
                    up[curr] = Math.min(up[curr], r);
                    validStart[curr] = true;
                }
            }
        }

        for (int color = 1; color <= MAX_COLOR; color++) {
            for (int r = up[color]; r <= down[color]; r++) {
                for (int c = left[color]; c <= right[color]; c++) {
                    if (art[r][c] != color) {
                        validStart[art[r][c]] = false;
                    }
                }
            }
        }

        int totalStarts = 0;
        for (boolean c : validStart) {
            totalStarts += c ? 1 : 0;
        }

        PrintWriter written = new PrintWriter("art.out");
        written.print(totalStarts);
        written.close();
    }
}
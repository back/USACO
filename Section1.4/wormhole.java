/*
LANG: JAVA
TASK: wormhole
*/

import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;

public class wormhole {

    static int[] m_next;
    static int[] m_pair;

    static int n;
    static int answer = 0;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File("wormhole.in"));

        n = sc.nextInt();
        sc.nextLine();

        int[][] m = new int[n][2];
        for(int i=0; i<n; i++) {
            String[] ss = sc.nextLine().split(" ");
            m[i][0] = Integer.parseInt(ss[0]);
            m[i][1] = Integer.parseInt(ss[1]);
        }

        m_next = new int[m.length];
        Arrays.fill(m_next, -1);

        for(int i=0; i<m_next.length; i++)
            for (int j=0; j<m_next.length; j++)
                if (i!=j && m[i][1]==m[j][1] && m[i][0]<m[j][0])
                    if(m_next[i]<0 || m[m_next[i]][0]>m[j][0])
                        m_next[i] = j;

        // Initialize wormhole pairing list
        m_pair = new int[m.length];
        for(int i=0;i<m_pair.length;i++)m_pair[i]=i;

        search(0); // recursive DFS for all the combinations of wormhole pairs

        FileWriter fw = new FileWriter(new File("wormhole.out"));
        fw.write(answer + "\n");
        fw.close();
    }

    static void search(int start) {
        boolean changed = false;
        for (int i = start; i < m_pair.length; i++) {
            if(m_pair[i]==i) {
                for (int j = i + 1; j < m_pair.length; j++) {
                    if (m_pair[j] == j) {
                        changed = true;
                        m_pair[i] = j;
                        m_pair[j] = i;
                        search(i + 1);
                        m_pair[i] = i;
                        m_pair[j] = j;
                    }
                }
                break;
            }
        }
        if (!changed) checkLoop();
    }

    static void checkLoop() {
        for(int i = 0; i<n; i++) {
            int pos = i, steps=n;
            while(steps-- >= 0 && pos >= 0)
                pos = m_next[m_pair[pos]];
            if (pos > -1) {
                answer++;
                break;
            }
        }
    }
}

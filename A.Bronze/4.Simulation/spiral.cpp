#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<int> ui = {0, -1, 0, 1},
            uj = {1, 0, -1, 0},
            di = {0, -1, 0, 1},
            dj = {-1, 0, 1, 0};
int mat[50][50], cnt = 0, n, m, k, cur = 0;

void fn (int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return;
    cnt++;
    mat[y][x] = min(mat[y][x], cur);
}

int main () {
    cin >> n >> m >> k;
    int x, y, z;
    vector<int> ti, tj;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            mat[i][j] = 1e9;
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> x >> y >> z;
        x--; y--;
        swap(x, y);
        if (z == 0) {
            ti = di;
            tj = dj;
        } else {
            ti = ui;
            tj = uj;
        }
        int kk = 1;
        int di = 1;
        int c = 2;
        cur = 1;
        cnt = 0;
        fn(x, y);
        while (true) {
            if (cnt >= n * m) break;
            if (c == 0) {
                di++;
                c = 2;
            }
            for (int va = 0; va < di; va++) {
                x += tj[kk];
                y += ti[kk];
                cur++;
                fn(x, y);
            }
            c--;
            kk = (kk + 1) % 4;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << (j == m - 1 ? '\n' : ' ');
        }
    }
}
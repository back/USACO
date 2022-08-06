#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

const int MAX_COLOR = 9;

int main() {
    /*
     * Bounding boxes of each of the colors.
     * The first element won't be used (colors go from 1-9)
     */
    vector<int> left(MAX_COLOR + 1);
    vector<int> right(MAX_COLOR + 1);
    vector<int> up(MAX_COLOR + 1);
    vector<int> down(MAX_COLOR + 1);
    for (int c = 1; c <= MAX_COLOR; c++) {
        left[c] = up[c] = INT32_MAX;
        right[c] = down[c] = -1;
    }

    vector<bool> valid_start(MAX_COLOR + 1);
    std::ifstream read("art.in");
    int width;
    read >> width;
    vector<vector<int>> art(width, vector<int>(width));
    for (int r = 0; r < width; r++) {
        for (int c = 0; c < width; c++) {
            char curr_char;
            read >> curr_char;
            int curr = curr_char - '0';
            art[r][c] = curr;
            if (curr != 0) {
                left[curr] = std::min(left[curr], c);
                right[curr] = std::max(right[curr], c);
                down[curr] = std::max(down[curr], r);
                up[curr] = std::min(up[curr], r);
                valid_start[curr] = true;
            }
        }
    }

    for (int color = 1; color <= MAX_COLOR; color++) {
        for (int r = up[color]; r <= down[color]; r++) {
            for (int c = left[color]; c <= right[color]; c++) {
                if (art[r][c] != color) {
                    valid_start[art[r][c]] = false;
                }
            }
        }
    }

    int total_starts = 0;
    for (bool s : valid_start) {
        total_starts += s ? 1 : 0;
    }
    std::ofstream("art.out") << total_starts << endl;
}
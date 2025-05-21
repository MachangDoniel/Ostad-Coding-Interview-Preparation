// 🧊 Problem: Doomsday Escape
// 💫 Problem Statement

// You are trapped in the 616 universe, a strange alternate universe modeled as a 2D grid of size n × m. You start at cell (1,1) and must reach cell (n,m) to escape. The fate of your universe depends on it.

// Each cell (i,j) in the grid contains a non-negative integer doom_time[i][j], which represents the time (in seconds) it takes for Dr. Doom to teleport from his dimension to that cell.

// You can move to adjacent cells: up, down, left, or right. Moving from one cell to another takes 1 second of your time.

// You start at time = 0. If you arrive at a cell strictly before Dr. Doom arrives at that cell, you're safe in that cell. However, if Dr. Doom reaches a cell at the same time or before you, you're captured!

//     "Is there a path to reach (n, m) without getting caught by Dr. Doom?"

// Use your time stone, and answer this question.
// 🧮 Input

//     First line: Two integers n and m — number of rows and columns (1 ≤ n, m ≤ 1000)

//     Next n lines: Each line contains m integers doom_time[i][j] (0 ≤ doom_time[i][j] ≤ 10^⁹)

// 📤 Output

//     Print "YES" if it's possible to reach cell (n, m) without being caught.

//     Otherwise, print "NO"

// 🧪 Sample Input 1

// 3 3
// 2 3 4
// 3 4 5
// 4 5 6

// ✅ Output 1

// YES

// 🧪 Sample Input 2

// 2 2
// 0 1
// 1 1

// ❌ Output 2

// NO

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

string canEscape(vector<vector<int>>& doom_time) {
    int n = doom_time.size(), m = doom_time[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    if (doom_time[0][0] <= 0) return "NO";  // Doom is already there

    q.push({0, 0});
    visited[0][0] = true;
    int time = 0;

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [x, y] = q.front(); q.pop();
            if (x == n - 1 && y == m - 1) return "YES";

            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (isValid(nx, ny, n, m) && !visited[nx][ny]) {
                    if (time + 1 < doom_time[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        ++time;
    }
    return "NO";
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> doom_time(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> doom_time[i][j];

    cout << canEscape(doom_time) << endl;
    return 0;
}

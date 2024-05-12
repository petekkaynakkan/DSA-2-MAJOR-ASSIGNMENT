
/* PETEK KAYNAKKAN 211504030 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void findPaths(int row, int col, int N, vector<vector<int>>& maze, string path, vector<string>& paths) {
    
    if (row == N - 1 && col == N - 1) {
        paths.push_back(path);
        return;
    }

   
    if (row >= 0 && col >= 0 && row < N && col < N && maze[row][col] == 1) {
    
        maze[row][col] = 0;

        
        findPaths(row + 1, col, N, maze, path + 'D', paths);
        findPaths(row - 1, col, N, maze, path + 'U', paths);
        findPaths(row, col + 1, N, maze, path + 'R', paths);
        findPaths(row, col - 1, N, maze, path + 'L', paths);

      
        maze[row][col] = 1;
    }
}

vector<string> printPath(int N, vector<vector<int>> m) {
    vector<string> paths;
 
    if (m[0][0] == 0 || m[N - 1][N - 1] == 0) {
        return paths;
    }
    
    findPaths(0, 0, N, m, "", paths);
   
    sort(paths.begin(), paths.end());
    return paths;
}

int main() {
    int N = 4;
    vector<vector<int>> maze = { {1, 0, 0, 0},
                                 {1, 1, 0, 1},
                                 {1, 1, 0, 0},
                                 {0, 1, 1, 1} };
    vector<string> paths = printPath(N, maze);
    if (paths.empty()) {
        cout << "-1" << endl;
    }
    else {
        for (string path : paths) {
            cout << path << " ";
        }
        cout << endl;
    }
    return 0;
}


/* PETEK KAYNAKKAN 211504030 */


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm> 
using namespace std;

bool isValid(int i, int j, int R, int C) {
    return (i >= 0 && i < R && j >= 0 && j < C);
}

void findWordsUtil(vector<vector<char>>& board, int i, int j, string& str, unordered_set<string>& dict, unordered_set<string>& result, vector<vector<bool>>& visited, int R, int C) {
    visited[i][j] = true;
    str.push_back(board[i][j]);

    if (dict.find(str) != dict.end())
        result.insert(str);

    for (int row = i - 1; row <= i + 1; row++) {
        for (int col = j - 1; col <= j + 1; col++) {
            if (isValid(row, col, R, C) && !visited[row][col]) {
                findWordsUtil(board, row, col, str, dict, result, visited, R, C);
            }
        }
    }

    str.pop_back();
    visited[i][j] = false;
}

vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary, int R, int C) {
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    unordered_set<string> result;
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    string str = "";

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            findWordsUtil(board, i, j, str, dict, result, visited, R, C);
        }
    }

    vector<string> res(result.begin(), result.end());
    sort(res.begin(), res.end());

    return res;
}

int main() {
    vector<vector<char>> board = { {'G','I','Z'},{'U','E','K'},{'Q','S','E'} };
    vector<string> dictionary = { "GEEKS","FOR","QUIZ","GO" };
    int R = 3, C = 3;

    vector<string> result = wordBoggle(board, dictionary, R, C);

    for (auto word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}

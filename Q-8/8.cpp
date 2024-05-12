
/* PETEK KAYNAKKAN 211504030 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidPart(const string& part) {
    int num = stoi(part);
    if (part.length() > 1 && part[0] == '0') {
        return false; 
    }
    return num >= 0 && num <= 255;
}

void generateIPs(const string& s, int start, int parts, string current, vector<string>& result) {
    if (start == s.length() && parts == 4) {
        result.push_back(current);
        return;
    }

    if (parts > 4) {
        return;
    }

    for (int i = 1; i <= 3 && start + i <= s.length(); ++i) {
        string part = s.substr(start, i);
        if (isValidPart(part)) {
            if (!current.empty()) {
                part = '.' + part;
            }
            generateIPs(s, start + i, parts + 1, current + part, result);
        }
    }
}

vector<string> genIp(string S) {
    vector<string> result;
    if (S.length() < 4 || S.length() > 12) {
        return { "-1" };
    }
    generateIPs(S, 0, 0, "", result);
    return result;
}

int main() {
    string S = "1111";
    vector<string> ips = genIp(S);
    for (const string& ip : ips) {
        cout << ip << endl;
    }
    return 0;
}

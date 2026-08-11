#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    bool seen[26] = {};
    for (char c : s)
        seen[c - 'a'] = true;
    int distinct = count(seen, seen + 26, true);
    cout << (distinct % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!") << "\n";
    return 0;
}
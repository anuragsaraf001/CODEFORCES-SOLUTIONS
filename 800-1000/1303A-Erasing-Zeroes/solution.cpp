#include <iostream>
#include <string>
using namespace std;
void solve() {
    string s;
    cin >> s;
    int first_one = -1;
    int last_one = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '1') {
            if (first_one == -1) {
                first_one = i;
            }
            last_one = i;
        }
    }
    if (first_one == -1) {
        cout << 0 << endl;
        return;
    }
    int zeroes_to_erase = 0;
    for (int i = first_one; i <= last_one; ++i) {
        if (s[i] == '0') {
            zeroes_to_erase++;
        }
    }
    cout << zeroes_to_erase << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
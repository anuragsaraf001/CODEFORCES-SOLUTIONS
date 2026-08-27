#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int noGroups = 0;
    string prevMag = "";

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (a != prevMag) {
            noGroups += 1;
        }
        prevMag = a;
    }

    cout << noGroups;
    return 0;
}
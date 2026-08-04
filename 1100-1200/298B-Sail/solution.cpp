#include <iostream>
#include <string>

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    long long sx, sy, ex, ey;
    
    // Read the inputs properly
    cin >> t >> sx >> sy >> ex >> ey;
    
    string s;
    cin >> s;

    // Simulate the boat ride second by second
    for (int i = 0; i < t; i++) {
        // If the wind takes us closer to the destination on the X-axis
        if (sx < ex && s[i] == 'E') {
            sx++;
        } else if (sx > ex && s[i] == 'W') {
            sx--;
        } 
        // If the wind takes us closer to the destination on the Y-axis
        else if (sy < ey && s[i] == 'N') {
            sy++;
        } else if (sy > ey && s[i] == 'S') {
            sy--;
        }

        // Check if we have arrived at the destination
        if (sx == ex && sy == ey) {
            // Time is 1-indexed, so we print i + 1
            cout << i + 1 << "\n";
            return 0;
        }
    }

    // If the loop finishes and we haven't reached the destination
    cout << -1 << "\n";
    return 0;
}
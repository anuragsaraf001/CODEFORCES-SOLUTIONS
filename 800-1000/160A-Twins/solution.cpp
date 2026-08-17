#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    if (!(std::cin >> n)) return 0;
    std::vector<int> coins(n);
    int total_sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
        total_sum += coins[i];
    }
    std::sort(coins.rbegin(), coins.rend());
    int my_sum = 0;
    int coin_count = 0;
    for (int coin : coins) {
        my_sum += coin;
        coin_count++;
        if (my_sum > total_sum - my_sum) {
            break;
        }
    }
    std::cout << coin_count << "\n";
    return 0;
}
#include <bits/stdc++.h>

using std::cin, std::cout;

auto main() -> int {
    size_t orders, waterMax;
    std::string line;
    cin >> orders >> waterMax;
    size_t count = 0;
    size_t water = waterMax;
    while (orders--) {
        cin >> line;
        auto amt = line[0] - '0' + (line.size() == 2);
        if (amt > water) {
            water = waterMax;
            count++;
        }
        water -= amt;
    }

    cout << count;
}

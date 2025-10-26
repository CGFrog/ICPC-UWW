#include <bits/stdc++.h>

using std::cin, std::cout;

auto solve(std::string_view const time) -> std::string {
    uint8_t bits[4] = {};
    /// Recieve [8x1] [8x1] [8x1] [8x1]
    /// Turn to [1x8] [1x8] [1x8] [1x8]
    for (auto i = 0; i < 4; i++) {
        auto const v = time[i] - '0';
        for (auto bit = 0; bit < 4; bit++) {
            auto x = 1 << bit;
            if (v & x)
                bits[bit] |= (1 << i);
        }
    }

    std::string rv;
    for (auto bit = 3; bit >= 0; bit--) {
        for (auto digit = 0; digit < 4; digit++) {
            auto mask = 1 << digit;
            auto b = bits[bit];
            if (b & mask)
                rv += '*';
            else
                rv += '.';

            if (digit != 3)
                rv += ' ';
            if (digit == 1)
                rv += "  ";
        }
        rv += '\n';
    }
    return rv;
}

auto main() -> int {
    std::string time;
    cin >> time;
    auto const res = solve(time);
    cout << res;
}

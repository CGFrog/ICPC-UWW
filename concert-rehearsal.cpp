#include <bits/stdc++.h>

using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isize = ssize_t;



auto main() -> int {
    u32 n, p, k;
    cin >> n >> p >> k;
    vector<u32> s(n, 0);
    vector<u32> e(n, 0);
    vector<pair<u32, u32>> c(n, {0, k});

    u32 count = 0;

    for (auto temp = 0; temp < n; temp++) {
        cin >> s[temp];
        if (temp > 0)
            s[temp] += s[temp - 1];
    }

    auto const T = s[n - 1];
    auto const fpd = p / T;
    auto const remt = p % T;

    for (auto perf = 0; perf < n; perf++) { // O(n)
        auto const prevSum = perf ? s[perf - 1] : 0;
        auto const bound = remt + prevSum;
        auto ub = upper_bound(begin(s), end(s), bound);
        if (ub == end(s)) {
            auto const r = remt - (T - prevSum);
            ub = upper_bound(begin(s), end(s), r);
        }
        auto const ix = distance(begin(s), ub);
        e[perf] = ix;
    }

    cout << +count << '\n';
}

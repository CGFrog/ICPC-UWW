#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;

auto main() -> int {
	u32 n;
	cin >> n;
	map<u32, u32> rec;
	while (n--) {
		u32 k;
		cin >> k;
		rec[k]++;
	}

	u32 H = 0, T = 0;
	for (auto it = rec.rbegin(); it != rec.rend(); ++it) {
		auto const& K = it->first;
		auto const& V = it->second;

		if (K <= H)
			break;

		T += V;
		H = min(K, T);
	}

	cout << +H << endl;
}

#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    string mov, rat;
    cin >> mov >> rat;
    int integralPart = atoll(rat.c_str());
    string minCost = (mov.size() <= integralPart) ? to_string(mov.size()) : rat;
    cout << minCost << endl;
}

// Compile time is not included in performance metrics.
#include <algorithm>
#include<vector>
#include <map>
#include <iostream>
#include<math.h>
#include <iomanip>

using namespace std;
using ll = long long;
using db = double;
using pii = pair<int,int>;
using vi = vector<int>;

inline void fast_io()
{
    // Disables C and C++ stream sync
    ios ::sync_with_stdio(false);
    // cin will no longer flush cout .
    cin.tie(nullptr);
}

db price(int k, int p, int a, int b, int c, int d){
    return p*(sin(a*k+b)+cos(c*k+d)+2);    
}

int main(){
    int n=10;
    int p=42, a=1, b=23, c=4, d=8;
    db maxPriceSoFar = -1e9;
    db maxDrop = 0;

    for (int i = 1; i <= n; i++){
        db currentPrice = price(i, p, a, b, c, d);
        if (maxPriceSoFar < currentPrice) {
            maxPriceSoFar = currentPrice;
        }
        db drop = maxPriceSoFar - currentPrice;
        if (drop > maxDrop) {
            maxDrop = drop;
        }
    }

    cout << setprecision(6) << maxDrop << "\n";
    return 0;
}
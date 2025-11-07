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

using db = double;

struct point3 {
    db x;
    db y;
    db z;
};
struct point2 {
    db x;
    db y;
    auto operator==(point2 const& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    auto operator-(point2 const& rhs) const {
        return point2 { x - rhs.x, y - rhs.y };
    }
    auto operator+(point2 const& rhs) const {
        return point2 { x + rhs.x, y + rhs.y };
    }
    auto operator/(double const& div) const {
        return point2 { x/div, y/div };
    }
    auto operator*(double const& div) const {
        return point2 { x*div, y*div };
    }
    friend auto& operator<<(ostream& os, point2 const& p) {
        return os << "Point { " << p.x << ", " << p.y << " }";
    }
};


enum struct axis { X, Y, Z };

auto mag(point2 const a) -> db {
    return a.x*a.x + a.y*a.y;
}
auto distance(point2 const& a, point2 const& b) -> db {
    return sqrt(mag(a - b));
}
auto project(point3 const& p, axis const ax) -> point2 {
    switch (ax) {
        case axis::X: return {p.y,p.z};
        case axis::Y: return {p.x,p.z};
        case axis::Z: return {p.x,p.y};
    }
    assert(false);
    return {};
}
auto midpoint(point2 const& a, point2 const& b) -> point2 {
    return (a + b)/2.0;
}

auto rng = default_random_engine{};
auto welzl(vector<point2> pts, vector<point2> bd) -> pair<point2, db> {
    if (pts.size() == 0 || bd.size() == 3) {
        if (bd.size() == 2) {
            auto const& A = bd[0], B = bd[1];
            return {midpoint(A,B),distance(A,B)/2.0};
        } else if (bd.size() < 2) {
            return {}; // Trivial circle. The point. At the Origin.
        }
        auto const& Af = bd[0], Bf = bd[1], Cf = bd[2];
        auto const B = Bf - Af, C = Cf - Af; // we shift so that `A` is at (0,0)
        auto const D = 1.0/(2.0 * (B.x * C.y - B.y * C.x));
        auto const ux = D * (C.y * mag(B) - B.y * mag(C));
        auto const uy = D * (B.x * mag(C) - C.x * mag(B));
        point2 const U{ux, uy};
        auto const r = sqrt(mag(U));
        return {U + Af, r};
    }
    ranges::shuffle(pts,rng);
    auto const p = pts.back();
    pts.pop_back();
    auto const D = welzl(pts, bd);
    if (distance(D.first, p) < D.second)
        return D;
    bd.push_back(p);
    return welzl(pts, bd);
}

auto main() -> int {
    u16 n;
    cin >> n;

    db xt, xb, yt, yb, zt, zb;
    xt = yt = zt = -1000.0;
    xb = yb = zb = 1000.0;

    vector<point3> flaws(n);
    vector<point2> projected(n);

    for (auto& flaw: flaws) {
        cin >> flaw.x >> flaw.y >> flaw.z;

        xt = max(flaw.x, xt);
        xb = min(flaw.x, xb);
        yt = max(flaw.y, yt);
        yb = min(flaw.y, yb);
        zt = max(flaw.z, zt);
        zb = min(flaw.z, zb);
    }

    auto const dx = abs(xt - xb);
    auto const dy = abs(yt - yb);
    auto const dz = abs(zt - zb);

    auto const ignoreAxis = max({pair{dx,axis::X},{dy,axis::Y},{dz,axis::Z}}, [](pair<db, axis> const& a, pair<db, axis> const& b) {
        return a.first < b.first;
    }).second;

    for (auto i = 0; i < n; i++) {
        projected[i] = project(flaws[i], ignoreAxis);
    }

    auto prcp = projected;
    auto const U = welzl(prcp, vector<point2>());
    auto const diam = U.second * 2.0;
    cout << diam << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum Bound { UNDETERMINED, BOUNDARY, EMPTY };

struct vec {
    int x, y;
    Bound boundType;
    vec(int x_val = 0, int y_val = 0, Bound bound = UNDETERMINED) {
        x = x_val;
        y = y_val;
        boundType = bound;
    }
    bool operator==(const vec& other) const {
        return x == other.x && y == other.y;
    }
};

struct boundary_info {
    vec position;
    vector<bool> seen_in_wind;
    boundary_info(int x, int y, int k) : position(x, y, BOUNDARY), seen_in_wind(k, false) {}
};

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool valid_point(int nx, int ny, int d_x, int d_y) {
    return nx >= 1 && ny >= 1 && nx <= d_x && ny <= d_y;
}

int main() {
    fast_io();
    int d_x, d_y, k;
    cin >> d_x >> d_y >> k;

    vector<vec> winds;
    vector<boundary_info> all_boundaries;
    vec** grid = new vec*[d_x];
    for (int i = 0; i < d_x; ++i) grid[i] = new vec[d_y];

    for (int i = 0; i < k; ++i) {
        int w_x, w_y, n;
        cin >> w_x >> w_y >> n;
        winds.emplace_back(w_x, w_y, UNDETERMINED);

        for (int j = 0; j < n; ++j) {
            int x, y;
            cin >> x >> y;
            grid[x - 1][y - 1] = vec(x, y, BOUNDARY);

            auto it = find_if(all_boundaries.begin(), all_boundaries.end(), [&](const auto& b){ return b.position == vec(x, y); });
            if (it == all_boundaries.end()) all_boundaries.emplace_back(x, y, k);
            all_boundaries.back().seen_in_wind[i] = true;

            int nx = x - w_x;
            int ny = y - w_y;
            if (valid_point(nx, ny, d_x, d_y)) grid[nx - 1][ny - 1].boundType = EMPTY;
        }
    }

    for (auto& b : all_boundaries) {
        for (int i = 0; i < k; ++i) {
            if (!b.seen_in_wind[i]) {
            int nx = b.position.x - winds[i].x;
            int ny = b.position.y - winds[i].y;
            if (valid_point(nx, ny, d_x, d_y) && grid[nx-1][ny-1].boundType != EMPTY) {
                grid[nx-1][ny-1].boundType = BOUNDARY;
            }

            }
        }
    }

    bool changes = true;
    while (changes) {
        changes = false;
        for (int x = 1; x <= d_x; ++x) {
            for (int y = 1; y <= d_y; ++y) {
                vec& p = grid[x-1][y-1];
                if (p.boundType != UNDETERMINED) continue;

                for (auto& wind : winds) {
                    int nx = x - wind.x;
                    int ny = y - wind.y;
                    if (!valid_point(nx, ny, d_x, d_y) || grid[nx-1][ny-1].boundType == EMPTY) {
                        p.boundType = EMPTY;
                        changes = true;
                        break;
                    }
                }
            }
        }
    }


    for (int y = 0; y < d_y; ++y) {
        for (int x = 0; x < d_x; ++x) {
            char c = (grid[x][y].boundType == BOUNDARY) ? '#' : '.';
            cout << c;
        }
        cout << "\n";
    }


    for (int y = 0; y < d_y; ++y) {
        for (int x = 0; x < d_x; ++x) {
            char c = (grid[x][y].boundType == EMPTY) ? '.' : '#';
            cout << c;
        }
        cout << "\n";
    }


    for (int i = 0; i < d_x; ++i) delete[] grid[i];
    delete[] grid;

    return 0;
}

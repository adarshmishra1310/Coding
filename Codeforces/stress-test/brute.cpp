#include <bits/stdc++.h>
using namespace std;
#define int long long

void runCase(int &testcase)
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n), r(n);
    for (int &i : x) cin >> i;
    for (int &i : r) cin >> i;

    vector<pair<int, int>> circles;
    for (int i = 0; i < n; i++)
        circles.push_back({x[i], r[i]});
    
    sort(circles.begin(), circles.end());

    for (int i = 0; i < n; i++) {
        x[i] = circles[i].first;
        r[i] = circles[i].second;
    }

    set<pair<int, int>> points;

    for (int i = 0; i < n; i++) {
        for (int dx = -r[i]; dx <= r[i]; dx++) {
            int real_x = x[i] + dx;
            int max_y = sqrt(r[i] * r[i] - dx * dx);

            for (int dy = -max_y; dy <= max_y; dy++) {
                points.insert({real_x, dy});
            }
        }
    }

    cout << points.size() << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests--) {
        runCase(tests);
    }
    return 0;
}

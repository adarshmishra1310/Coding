#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, C;
    cin >> N >> C;
    string S;
    cin >> S;

    unordered_map<char, int> freq;
    for (char ch : S) freq[ch]++;

    vector<pair<int, char>> lang_list;
    for (auto &[ch, count] : freq) lang_list.push_back({count, ch});
    sort(lang_list.rbegin(), lang_list.rend());

    int min_cost = INT_MAX;

    for (int i = 0; i <= lang_list.size(); ++i) {
        int learning_cost = i * C;
        int translator_cost = 0, translator_usage = 1;

        unordered_set<char> learned;
        for (int j = 0; j < i; ++j) learned.insert(lang_list[j].second);

        for (char ch : S) {
            if (!learned.count(ch)) {
                translator_cost += translator_usage++;
            }
        }

        min_cost = min(min_cost, learning_cost + translator_cost);
    }

    cout << min_cost << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

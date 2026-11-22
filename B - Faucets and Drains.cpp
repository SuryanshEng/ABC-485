#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &x : s) cin >> x;
    for (int i = 0; i < n; i++)
        if (s[i].find('o') == string::npos) {
            cout << "Faucet " << i + 1 << "\n";
            return 0;
        }
    for (int j = 0; j < m; j++) {
        bool all = true;
        for (int i = 0; i < n; i++) if (s[i][j] == 'o') all = false;
        if (all) {
            cout << "Drain " << j + 1 << "\n";
            return 0;
        }
    }
}
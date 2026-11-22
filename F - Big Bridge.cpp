#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int L = M + 1;
    vector<vector<pair<int, ll>>> B(M + 2);
    ll F = 0;
    for (int i = 0; i < N; i++) {
        int c;
        ll v;
        cin >> c >> v;
        B[c].push_back({c, v});
        F += v;
    }
    vector<vector<ll>> G(N + 2, vector<ll>(L, -1));
    fill(G[0].begin(), G[0].end(), 0);
    vector<ll> ANS(M + 1);
    int cnt = 0;
    for (int j = M; j >= 0; j--) {
        if (j < M)
            for (int k = 1; k <= N; k++)
                for (int w = k * j; w < k * j + k; w++) G[k][w % L] = -1;
        if (j + 1 <= M)
            for (auto [c, v] : B[j + 1]) {
                F -= v;
                for (int k = cnt; k >= 0; k--) {
                    int lo = (k + 1) * j, lk = k * j;
                    for (int w = lo; w <= lo + M; w++) {
                        int s = w - c;
                        if (s < lk) continue;
                        ll x = G[k][s % L];
                        if (x < 0) continue;
                        ll &y = G[k + 1][w % L];
                        y = max(y, x + v);
                    }
                }
                cnt++;
            }
        ll best = 0;
        for (int k = 0; k <= cnt; k++) best = max(best, G[k][(k * j + M) % L]);
        ANS[j] = F + best;
    }
    for (int j = 0; j <= M; j++) cout << ANS[j] << "\n";
}
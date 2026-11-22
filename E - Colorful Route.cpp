#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> U(M), V(M), C(M), D(M, -1);
    vector<vector<int>> G(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> U[i] >> V[i] >> C[i];
        G[U[i]].push_back(i);
    }
    vector<int> F(N + 1, -1), S(N + 1, -1);
    queue<array<int, 3>> Q;
    Q.push({1, 0, 0});
    while (!Q.empty()) {
        auto [v, c, d] = Q.front();
        Q.pop();
        if (F[v] == c || S[v] == c) continue;
        if (F[v] == -1) F[v] = c;
        else if (S[v] == -1) S[v] = c;
        else continue;
        for (int e : G[v]) {
            if (C[e] == c || D[e] != -1) continue;
            D[e] = d + 1;
            if (V[e] == N) {
                cout << d + 1 << "\n";
                return 0;
            }
            Q.push({V[e], C[e], d + 1});
        }
    }
    cout << -1 << "\n";
}
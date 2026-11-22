#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    string S;
    cin >> N >> S;
    S = " " + S;
    auto ok = [](int *c) { return c[0] && c[1] && c[2]; };
    int c[3] = {0, 0, 0}, P = 0;
    for (int i = 1; i <= N; i++) {
        c[S[i] - 'A']++;
        if (ok(c)) { P = i; break; }
    }
    int d[3] = {0, 0, 0}, Q = 0;
    for (int i = N; i >= 1; i--) {
        d[S[i] - 'A']++;
        if (ok(d)) { Q = N - i + 1; break; }
    }
    if (!P || !Q) { cout << 0 << "\n"; return 0; }
    int W[3] = {0, 0, 0};
    int E = P;
    long long ANS = 0;
    for (int i = P; i <= N - Q; i++) {
        int s = i + 1;
        if (i > P) W[S[i] - 'A']--;
        if (E < i) E = i;
        while (E < N && !ok(W)) W[S[++E] - 'A']++;
        if (!ok(W)) break;
        ANS += max(0, N - Q - E + 1);
    }
    cout << ANS << "\n";
}
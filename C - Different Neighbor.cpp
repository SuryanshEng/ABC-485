#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> C(N + 2, 0), L(N + 2), R(N + 2);
    for (int i = 1; i <= N; i++) cin >> C[i];
    for (int i = 1; i <= N; i++) L[i] = (i > 1 && C[i] == C[i - 1]) ? L[i - 1] : i;
    for (int i = N; i >= 1; i--) R[i] = (i < N && C[i] == C[i + 1]) ? R[i + 1] : i;
    for (int i = 1; i <= N; i++) {
        int ANS = INT_MAX;
        if (L[i] > 1) ANS = min(ANS, i - L[i] + 1);
        if (R[i] < N) ANS = min(ANS, R[i] - i + 1);
        cout << ANS << " \n"[i == N];
    }
}
#include <bits/stdc++.h>
using namespace std;

const int MAXM = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(N);
    vector<pair<int, int>> events;

    // Read requests and create events
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
        // For each request (A[i], B[i]), invalid interval is [A[i] + 1, B[i] - k]
        // Starts at A[i] + 1, ends at B[i] - k
        events.emplace_back(A[i] + 1, 1); // Start of invalid interval
        events.emplace_back(B[i] + 1, -1); // Placeholder for end adjustment
    }

    vector<int> f(M + 1, 0);
    vector<int> diff(MAXM + 1, 0);

    // Process each k
    for (int k = 1; k <= M; ++k) {
        // Adjust difference array for this k
        for (int i = 0; i < N; ++i) {
            // Update end point: B[i] - k + 1
            if (B[i] - k + 1 >= 1 && B[i] - k + 1 <= M - k + 1) {
                diff[B[i] - k + 1]--;
            }
            // Start point remains A[i] + 1
            if (A[i] + 1 <= M - k + 1) {
                diff[A[i] + 1]++;
            }
        }

        // Compute invalid l using prefix sum
        int invalid = 0;
        int active = 0;
        for (int l = 1; l <= M - k + 1; ++l) {
            active += diff[l];
            if (active > 0) {
                invalid++;
            }
            diff[l] = 0; // Reset for next k
        }

        f[k] = (M - k + 1) - invalid;
    }

    // Output f(1) to f(M)
    for (int k = 1; k <= M; ++k) {
        cout << f[k] << " ";
    }
    cout << '\n';

    return 0;
}
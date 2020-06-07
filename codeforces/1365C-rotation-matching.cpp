#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

const int NMAX = 2e5 + 11;

int n, a[NMAX], b[NMAX];

int solve(void)
{
    vi desired(n, 0);
    vi moves(n, 0);

    for (int i = 0; i < n; ++i)
        desired[a[i]] = i;

    for (int i = 0; i < n; ++i)
    {
        int j = (desired[b[i]] - i + n) % n;
        ++moves[j];
    }

    return *max_element(moves.begin(), moves.end());
}
int main(void)
{
    int x;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        a[i] = x - 1;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        b[i] = x - 1;
    }

    cout << solve() << endl;

    return 0;
}

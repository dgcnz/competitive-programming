#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int NMAX = 3 * 1e5 + 11;

int n;
ll  sum, a[NMAX], b[NMAX];

// Key Idea:
// - Relax b, i can maximally damage i + 1, with as much health a + 1 has, so
// the net damage of i is b[i] = min(b[i], a[i + 1]).
// - What happens if you form a new graph, c[i] = a[i] - b[i]? It represents the
// remaining health of every enemy if they are hit by the chain reaction
// previous to them.
// - Now, what happens if I start with enemy i?
// - I need to kill i by hand and then it will start a chain reaction as long as
// c[j] = 0, j > i. And then kill k > i, c[k] > 0 (the first enemy that doesn't
// die by chain reaction, and so on. Which enemy should I pick to start then?
// Pick the one that if it were to have been hit by the chain reaction it would
// have felt the less damage

ll solve(void)
{
    ll suma, sumb, mn = LLONG_MAX;
    suma = sumb = 0;

    for (int i = 0; i < n; ++i)
    {
        suma += a[i];
        b[i] = min(b[i], a[(i + 1) % n]); // relax the b's -> net damage
        sumb += b[i];
        mn = min(mn, b[i]);
    }

    return suma - sumb + mn;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        sum = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];

        cout << solve() << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int const MOD = 1e9 + 7;

inline int add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }

inline int mult(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }

int solve(int x, string s)
{
    int n = s.size();
    for (int i = 1; i <= x; ++i)
    {
        int rep = s[i - 1] - '1'; // -1 because the first paste restores sright
        n       = add(n, mult(n - i + MOD, rep)); // n - i might be negative
        if ((int)s.size() <= x) // we only need the prefix of s up to x
        {
            string sright(s.begin() + i, s.end());
            while (rep--)
                s += sright;
        }
    }
    return n;
}

int main(void)
{
    int    t, x;
    string s;
    cin >> t;

    while (t--)
    {
        cin >> x >> s;
        cout << solve(x, s) << endl;
    }
    return 0;
}

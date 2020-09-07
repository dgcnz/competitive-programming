#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size();

using namespace std;
using ll = long long;
using vi = vector<int>;

bool solve(string s, int k)
{
    int    n = isz(s);
    string t(s.begin(), s.begin() + k);

    // reduce uncertainty of string t and check if there are any fails
    for (int i = k; i < n; i += k)
    {
        for (int j = 0; j < k and j + i < n; ++j)
        {
            int ix = i + j;
            if (s[ix] != '?' and t[j] == '?')
                t[j] = s[ix];
            else if (s[ix] != '?' and t[j] != '?' and s[ix] != t[j])
                return false;
        }
    }

    int zeros = count_if(all(t), [](char c) { return c == '0'; });
    int ones  = count_if(all(t), [](char c) { return c == '1'; });
    return ones <= k / 2 and zeros <= k / 2;
}
int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        int    n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        cout << (solve(s, k) ? "YES" : "NO") << endl;
    }
    return 0;
}

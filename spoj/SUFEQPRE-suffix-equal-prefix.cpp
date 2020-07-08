#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e6 + 11;

string s;
int    n, pi[NMAX];

void prefix_function(void)
{
    memset(pi, 0, sizeof(pi));
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
}

int main(void)
{
    int t, ans, j;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc)
    {
        cin >> s;
        n = s.size();
        prefix_function();
        ans = 0;
        j   = pi[n - 1];
        while (j != 0)
        {
            j = pi[j - 1];
            ans += 1;
        }

        cout << "Case " << tc << ": " << ans << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int solve(int n, string s)
{
    int start = 0;
    if (s[start] == s[(start - 1 + n) % n])
    {
        do
        {
            start = (start - 1 + n) % n;
        } while (start != 0 and s[start] == s[(start - 1 + n) % n]);

        if (start == 0) // all array is equal
            return (n + 3 - 1) / 3;
    }

    int  cnt = 0, ans = 0;
    char c = s[start];
    for (int i = 0; i <= n; ++i)
    {
        if (s[(start + i) % n] == c)
        {
            cnt++;
        }
        else
        {
            ans += cnt / 3;
            cnt = 1;
            c   = s[(start + i) % n];
        }
    }

    return ans;
}

int main(void)
{
    int    t, n;
    string s;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cin >> s;

        cout << solve(n, s) << endl;
    }

    return 0;
}

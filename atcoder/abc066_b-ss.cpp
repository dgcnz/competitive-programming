#include <bits/stdc++.h>

using namespace std;

bool equal(string const &s, int m)
{
    for (int i = 0; i < m / 2; ++i)
        if (s[i] != s[i + m / 2])
            return false;
    return true;
}

int solve(string const &s)
{
    int n = s.size();
    for (int i = n - 2; i > 0; i -= 2)
    {
        if (equal(s, i))
            return i;
    }
    return 0;
}

int main(void)
{
    string s;

    cin >> s;

    cout << solve(s) << endl;
    return 0;
}

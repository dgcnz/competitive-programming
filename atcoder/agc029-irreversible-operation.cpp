#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void)
{
    string s;
    int    wcnt = 0;
    ll     ans  = 0;
    cin >> s;

    for (int i = (int)s.size() - 1; i >= 0; --i)
    {
        if (s[i] == 'W')
            ++wcnt;
        else
            ans += wcnt;
    }

    cout << ans << endl;
    return 0;
}

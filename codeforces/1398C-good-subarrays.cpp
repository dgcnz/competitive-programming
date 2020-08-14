#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int           t, n, s;
    ll            ans;
    string        a;
    map<int, int> mp;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cin >> a;

        s = 0, ans = 0;
        mp.clear();

        mp[0]++;
        for (int i = 0; i < n; ++i)
        {
            s += a[i] - '0';
            ans += mp[s - (i + 1)];
            ++mp[s - (i + 1)];
        }
        cout << ans << endl;
    }
    return 0;
}

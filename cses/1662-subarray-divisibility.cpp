#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void)
{
    int          n, ai;
    ll           s = 0, ans = 0;
    map<ll, int> prefix_count;

    cin >> n;
    prefix_count[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> ai;
        s = ((s + ai) % n + n) % n;
        ans += prefix_count[s];
        ++prefix_count[s];
    }

    cout << ans << endl;
    return 0;
}

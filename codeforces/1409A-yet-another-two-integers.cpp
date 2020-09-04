#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        ll diff = abs(b - a);
        ll ans  = diff / 10 + ((diff % 10) > 0);
        cout << ans << endl;
    }
    return 0;
}

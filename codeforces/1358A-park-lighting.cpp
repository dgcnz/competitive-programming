#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void)
{
    int t, n, m;
    ll  ans;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        ans = n * (m / 2);

        if (m % 2 == 1)
        {
            if (n % 2 == 0)
                ans += n / 2;
            else
                ans += n / 2 + 1;
        }
        cout << ans << endl;
    }
    return 0;
}

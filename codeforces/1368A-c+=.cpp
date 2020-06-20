#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t, a, b, n, ans;
    cin >> t;

    while (t--)
    {
        cin >> a >> b >> n;
        if (a < b)
            swap(a, b);

        // a is max

        ans = 0;
        while (a <= n)
        {
            b += a;
            swap(a, b);
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}

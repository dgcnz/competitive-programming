#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size();

using namespace std;
using ll  = long long;
using vll = vector<ll>;

ll solve(vll &a)
{
    int n   = isz(a);
    ll  ans = 0;

    int l = 0, r = n - 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] > 0)
        {
            // a[i] positive, a[r] negative
            // consume rightmost if any
            while (r > i and a[i] > 0)
            {
                if (a[r] < 0)
                {
                    auto diff = min(a[i], abs(a[r]));
                    a[i] -= diff;
                    a[r] += diff;
                }
                if (a[r] == 0)
                    --r;
            }

            // consume leftmost

            while (l < i and a[i] > 0)
            {
                if (a[l] < 0)
                {
                    auto diff = min(a[i], abs(a[l]));
                    a[i] -= diff;
                    a[l] += diff;
                    ans += diff;
                }
                if (a[l] >= 0)
                    ++l;
            }
        }
    }

    return ans;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vll a(n);
        for (auto &ai : a)
            cin >> ai;
        cout << solve(a) << endl;
    }
    return 0;
}

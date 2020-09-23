
#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

// int const MOD = 1e9 + 7;

int main(void)
{
    int n;
    cin >> n;
    vi a(n);
    for (auto &ai : a)
        cin >> ai;

    sort(all(a), greater<int>());

    vi ans(n);
    ans[0] = a[0];

    for (int i = 1; i < n; i += 2)
    {
        ans[i] = a[i];
        if (i + 1 < n)
        {
            ans[i + 1] = a[i + 1];
            swap(ans[i], ans[i + 1]);
        }
    }

    cout << (n - 1) / 2 << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}

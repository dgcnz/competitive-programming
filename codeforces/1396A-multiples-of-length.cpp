#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    read(all(a));
    if (n == 1)
    {
        cout << 1 << " " << 1 << endl;
        cout << -a[0] << endl;
        a[0] = 0;
        cout << 1 << " " << 1 << endl;
        cout << -a[0] << endl;
        cout << 1 << " " << 1 << endl;
        cout << -a[0] << endl;
        return 0;
    }
    cout << 1 << " " << n - 1 << endl;
    for (int i = 0; i < n - 1; ++i)
    {
        ll delta = (n - 1) * (a[i] % n);
        a[i] += delta;
        cout << delta << " ";
    }
    cout << endl;
    cout << n << " " << n << endl;
    cout << -a[n - 1] << endl;
    a[n - 1] = 0;

    cout << 1 << " " << n << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << -a[i] << " ";
        a[i] = 0;
    }
    cout << endl;

    return 0;
}

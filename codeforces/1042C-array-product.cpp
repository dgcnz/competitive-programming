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

template <typename T>
vector<pair<int, T>> enumerate(vector<T> const &a)
{
    int                  n = a.size();
    vector<pair<int, T>> b(n);
    for (int i = 0; i < n; ++i)
        b[i] = {i, a[i]};
    return b;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    read(all(a));

    int ixneg = -1, ixzero = -1, negcnt = 0;

    for (int i = 0; i < n; ++i)
    {
        negcnt += a[i] < 0;
        if (a[i] < 0 and (ixneg == -1 or a[i] > a[ixneg]))
            ixneg = i;
        if (a[i] == 0 and ixzero == -1)
            ixzero = i;
    }
    vector<bool> valid(n, true);
    int          m = 0;
    if (ixzero != -1)
    {
        for (int i = 0; i < n; ++i)
        {
            if (i != ixzero and a[i] == 0)
            {
                ++m;
                valid[i] = false;
                cout << 1 << " " << i + 1 << " " << ixzero + 1 << endl;
            }
        }
        if (ixneg != -1 and negcnt & 1)
        {
            ++m;
            valid[ixneg] = false;
            cout << 1 << " " << ixneg + 1 << " " << ixzero + 1 << endl;
        }
        if (m < n - 1)
        {
            valid[ixzero] = false;
            cout << 2 << " " << ixzero + 1 << endl;
        }
    }
    else if (ixneg != -1 and negcnt & 1)
    {
        ++m;
        valid[ixneg] = false;
        cout << 2 << " " << ixneg + 1 << endl;
    }

    int src = -1;

    for (int i = 0; i < n; ++i)
        if (valid[i])
            src = i;

    for (int i = 0; i < n; ++i)
    {
        if (i != src and valid[i] and m < n - 1)
        {
            ++m;
            cout << 1 << " " << i + 1 << " " << src + 1 << endl;
        }
    }
    return 0;
}

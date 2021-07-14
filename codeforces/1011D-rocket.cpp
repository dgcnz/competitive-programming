#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/utils/io>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int ask(int x)
{
    cout << x << endl;
    cout.flush();
    int cmp;
    cin >> cmp;
    if (cmp == 0)
        exit(0);
    else if (cmp == -2)
        throw runtime_error("-2");

    return cmp;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int m, n;
    cin >> m >> n;

    vector<int> p(n);
    for (auto &pi : p)
    {
        int cmp = ask(1);
        pi      = cmp == 1;
    }

    int  k  = 0;
    auto ok = [&](int x) {
        int cmp = ask(x);
        if (p[k] == 0) // lying
            cmp *= -1;
        k += 1;
        k %= n;
        return cmp == -1;
    };

    int l = 1, r = m;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (ok(mid))
            r = mid;
        else
            l = mid + 1;
    }
    ok(l);
    return 0;
}

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

int query(int l, int r)
{
    cout << "? " << l + 1 << " " << r + 1 << endl;
    cout.flush();

    int ix;
    cin >> ix, ix--;
    return ix;
};

void guess(int ix)
{
    cout << "! " << ix + 1 << endl;
    cout.flush();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    int ix = query(0, n - 1);
    if (ix > 0 and query(0, ix) == ix)
    {
        // [0, ix - 1]
        int  l = 0, r = ix;
        auto ok  = [ix](int i) { return query(i, ix) == ix; };
        int  ans = *binary_search10(itint(l), itint(r), ok);
        guess(ans);
    }
    else
    {
        // [ix + 1, n - 1]
        int  l = ix + 1, r = n;
        auto ok  = [ix](int i) { return query(ix, i) == ix; };
        int  ans = *binary_search01(itint(l), itint(r), ok);
        guess(ans);
    }

    return 0;
}

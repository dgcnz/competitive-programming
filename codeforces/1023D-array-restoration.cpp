#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/segtree>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

using S = bool;
S op(S a, S b) { return a or b; }
S e() { return false; }

bool valid(vi a, int q)
{
    // assumes max is present
    a.erase(unique(all(a)), a.end());
    int               n = a.size();
    segtree<S, op, e> st(n);
    vector<int>       last(q + 1, -1);
    vector<ii>        b(n);
    for (int i = 0; i < n; ++i)
        b[i] = {a[i], i};
    sort(all(b));

    for (int i = 0; i < n; ++i)
    {
        auto [aj, j] = b[i];
        if (last[aj] != -1 and st.prod(last[aj] + 1, j + 1))
            return false;
        last[aj] = j;
        st.set(j, true);
    }
    return true;
}

vi solve(vi a, int q)
{
    int n = a.size();

    auto paint = [&](int i, int x)
    {
        int l = i, r = i;
        while (l >= 0 and (a[l] == 0 or a[l] == x))
            a[l--] = x;
        while (r < n and (a[r] == 0 or a[r] == x))
            a[r++] = x;
    };

    if (auto itmax = find(all(a), q); itmax != a.end())
        paint(distance(a.begin(), itmax), q);
    else if (auto it0 = find(all(a), 0); it0 != a.end())
        paint(distance(a.begin(), it0), q);
    else
        return {};

    for (int k = 0; k < 2; ++k)
    {
        int prv = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == 0)
                a[i] = prv;
            prv = a[i];
        }
        reverse(all(a));
    }
    return valid(a, q) ? a : vi{};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vi a(n);
    read(all(a));
    if (auto ans = solve(a, q); ans.size())
    {
        cout << "YES" << endl;
        write(all(ans), " "), cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}

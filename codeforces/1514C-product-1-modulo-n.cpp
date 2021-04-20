#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    using mint = modint;
    mint::set_mod(n);
    vector<mint> a;
    for (int i = 1; i < n; ++i)
        if (gcd(i, n) == 1)
            a.push_back(mint(i));

    mint prod = accumulate(all(a), mint(1), multiplies<mint>());
    if (prod == 1)
    {
        cout << a.size() << endl;
        for (auto ai : a)
            cout << ai.val() << " ";
    }
    else
    {
        auto x = prod.inv();
        cout << (int)a.size() - 1 << endl;
        for (auto ai : a)
            if (ai != x)
                cout << ai.val() << " ";
    }

    return 0;
}

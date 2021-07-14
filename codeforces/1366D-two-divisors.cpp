#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/sieve>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const NMAX = 1e7 + 1;

SmallestPrimeSieve<NMAX> sieve;

vector<vi> solve(vi a)
{
    int        n = a.size();
    vector<vi> ans(2, vi(n, -1));
    for (int i = 0; i < n; ++i)
    {
        int x = sieve.sp[a[i]];
        while (a[i] % x == 0)
            a[i] /= x;
        if (a[i] != 1)
            ans[0][i] = x, ans[1][i] = a[i];
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    read(all(a));

    auto ans = solve(a);
    for (auto row : ans)
        write(all(row), " "), cout << endl;
    return 0;
}

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

vi solve(vi a)
{
    int n = a.size();
    for (int i = 0; i < n; ++i)
        if (a[i] >= 0)
            a[i] = -a[i] - 1;

    if (n & 1)
    {
        auto it = min_element(all(a));
        *it     = -*it - 1;
    }
    return a;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    read(all(a));

    auto ans = solve(a);
    write(all(ans), " "), cout << endl;
    return 0;
}

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

    int        r = n * n, l = 1;
    vector<vi> ans(n);
    while (l < r)
    {
        for (int i = 0; i < n and l <= r; ++i, ++l)
            ans[i].push_back(l);
        for (int i = 0; i < n and l <= r; ++i, --r)
            ans[i].push_back(r);
    }
    for (auto row : ans)
        write(all(row), " "), cout << endl;
    return 0;
}

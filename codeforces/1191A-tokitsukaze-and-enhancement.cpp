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
    vector<pair<int, char>> ans = {{1, 'A'}, {0, 'A'}, {1, 'B'}, {2, 'A'}};
    int                     x;
    cin >> x;
    auto [delta, ch] = ans[x % 4];
    cout << delta << " " << ch << endl;
    return 0;
}

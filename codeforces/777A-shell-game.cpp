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
    int n, x;
    cin >> n >> x;
    vector<vector<int>> f = {
        {0, 1, 2, 2, 1, 0}, {1, 0, 0, 1, 2, 2}, {2, 2, 1, 0, 0, 1}};

    for (int i = 0; i < 3; ++i)
    {
        if (f[i][n % 6] == x)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}

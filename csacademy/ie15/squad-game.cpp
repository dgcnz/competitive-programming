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
using ll  = long long;
using ii  = pair<int, int>;
using iii = tuple<int, int, int>;
using vi  = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<vector<iii>> points(3, vector<iii>(n));
    for (int k = 0; k < 3; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> get<0>(points[k][i]) >> get<1>(points[k][i]);
            get<2>(points[k][i]) = i;
        }
        sort(all(points[k]));
    }

    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < 3; ++k)
        {
            cout << get<2>(points[k][i]) + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}

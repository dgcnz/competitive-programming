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
    int const  CMAX = 2e5;
    int        n;
    vector<vi> colors(CMAX);
    cin >> n;

    bool flag = true;
    for (int i = 0; i < n; ++i)
    {
        int a, c;
        cin >> a >> c;
        if (colors[c].size() and colors[c].back() > a)
            flag = false;
        colors[c].push_back(a);
    }
    cout << (flag ? "YES" : "NO") << endl;

    return 0;
}

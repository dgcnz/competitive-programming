#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
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
    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        int    px, py;
        cin >> x >> px >> y >> py;

        if (x.size() < y.size())
        {
            int delta = min(y.size(), x.size() + px) - x.size();
            x.resize(x.size() + delta, '0');
            px -= delta;
        }
        else if (x.size() > y.size())
        {
            int delta = min(x.size(), y.size() + py) - y.size();
            y.resize(y.size() + delta, '0');
            py -= delta;
        }

        int nx = x.size() + px, ny = y.size() + py;
        if (nx > ny or (nx == ny and x > y))
            cout << ">" << endl;
        else if (nx < ny or (nx == ny and x < y))
            cout << "<" << endl;
        else
            cout << "=" << endl;
    }
    return 0;
}

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

    int n, q;
    cin >> n >> q;

    vector<int> front(n, -1), rear(n, -1);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            cin >> x >> y, x--, y--;
            front[y] = x;
            rear[x]  = y;
        }
        else if (type == 2)
        {
            int x, y;
            cin >> x >> y, x--, y--;
            rear[x]  = -1;
            front[y] = -1;
        }
        else
        {
            int x;
            cin >> x, x--;
            while (front[x] != -1)
                x = front[x];

            vector<int> ans;
            do
            {
                ans.push_back(x + 1);
                x = rear[x];
            } while (x != -1);
            cout << ans.size() << " ";
            write(all(ans), " "), cout << endl;
        }
    }
    return 0;
}

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        set<int> once, more;
        for (int i = 0; i < n; ++i)
        {
            int ai;
            cin >> ai;
            if (once.find(ai) == once.end())
                once.insert(ai);
            else
                more.insert(ai);
        }

        int x = 0;
        while (more.find(x) != more.end())
            ++x;

        int y = x;
        while (once.find(y) != once.end())
            ++y;
        cout << x + y << endl;
    }
    return 0;
}

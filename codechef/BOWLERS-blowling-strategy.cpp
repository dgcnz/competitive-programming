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
        int slots, players, l;
        cin >> slots >> players >> l;

        bool ok = true;
        if (players == 1)
        {
            if (slots > 1)
                ok = false;
            else
                ok = true;
        }
        else // n > 1
        {
            ok = players * l >= slots;
        }

        if (ok)
        {
            for (int i = 0; i < slots; ++i)
            {
                cout << (i % players) + 1 << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}

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
    int n;
    cin >> n;

    vector<ii> d(n);

    for (auto &[f, s] : d)
        cin >> f >> s;

    int cnt = 0;
    for (auto [f, s] : d)
    {
        if (f == s)
        {
            cnt++;
        }
        else
        {
            if (cnt >= 3)
            {
                cout << "Yes" << endl;
                return 0;
            }
            cnt = 0;
        }
    }

    if (cnt >= 3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

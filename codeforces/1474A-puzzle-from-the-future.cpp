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
    int t;
    cin >> t;
    while (t--)
    {
        int    n;
        string b;
        cin >> n >> b;

        char prev = 0;
        for (auto c : b)
        {
            if (c + 1 != prev)
            {
                prev = c + 1;
                cout << '1';
            }
            else
            {
                prev = c;
                cout << '0';
            }
        }
        cout << endl;
    }
    return 0;
}

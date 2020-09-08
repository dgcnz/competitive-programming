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
        int ones = 0, zeros = 0;
        for (int i = 0; i < n; ++i)
        {
            char c;
            cin >> c;
            if (c == '0')
                zeros++;
            else
                ones++;
        }

        // dbg(zeros), dbg(ones);
        int m = n / 2;
        if (zeros >= ones)
        {
            cout << m << endl;
            for (int i = 0; i < m; ++i)
                cout << '0' << " ";
            cout << endl;
        }
        else // ones > zeros
        {
            if (m % 2 == 1)
                m++;

            cout << m << endl;
            for (int i = 0; i < m; ++i)
                cout << '1' << " ";
            cout << endl;
        }
    }
    return 0;
}

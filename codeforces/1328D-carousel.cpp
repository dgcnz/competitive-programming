#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size();

using namespace std;
using ll = long long;
using vi = vector<int>;

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vi t(n);
        for (auto &ti : t)
            cin >> ti;

        int changes = 0;
        for (int i = 0; i < n; ++i)
            if (t[i] != t[(i - 1 + n) % n])
                ++changes;
        int color;
        if (changes % 2 == 0)
        {
            cout << (changes == 0 ? 1 : 2) << endl;
            color = 0;
            for (int i = 0; i < n; ++i)
            {
                cout << color + 1 << " ";
                if (t[i] != t[(i + 1 + n) % n])
                    color = 1 - color;
            }
            cout << endl;
        }
        else
        {
            if (changes == n)
            {
                cout << 3 << endl;
                color = 0;
                for (int i = 0; i < n; ++i)
                {
                    cout << color + 1 << " ";
                    if (i == n - 2)
                        color = 2;
                    else if (t[i] != t[(i + 1 + n) % n])
                        color = 1 - color;
                }
                cout << endl;
            }
            else
            {
                int start = 0;
                while (t[(start + n) % n] != t[(start - 1 + n) % n])
                    start = (start + 1 + n) % n;
                while (t[(start + n) % n] == t[(start + 1 + n) % n])
                    start = (start + 1 + n) % n;

                vi ans(n);
                cout << 2 << endl;
                color = 0;
                for (int i = 0; i < n; ++i)
                {
                    ans[(start + i) % n] = color + 1;
                    if (t[(start + i) % n] != t[(start + i + 1 + n) % n])
                        color = 1 - color;
                }
                for (auto x : ans)
                    cout << x << " ";
                cout << endl;
            }
        }
    }
    return 0;
}

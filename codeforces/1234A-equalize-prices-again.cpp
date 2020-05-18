#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t, n, x, s;
    cin >> t;

    while (t--)
    {
        s = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            s += x;
        }

        cout << (int)ceil(s / (n * 1.0)) << endl;
    }
}

#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(void)
{
    int t, n, ai;
    vi  cnt;

    cin >> t;
    while (t--)
    {
        cin >> n;
        cnt.assign(n + 1, 0);

        n *= 2;
        while (n--)
        {
            cin >> ai;
            cnt[ai]++;
            if (cnt[ai] == 2)
                cout << ai << " ";
        }
        cout << endl;
    }
    return 0;
}

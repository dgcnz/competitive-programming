#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(void)
{
    int    t, n, q, c, ans;
    string s;

    cin >> t;
    while (t--)
    {
        vi occurrences(26, 0);

        cin >> n >> q >> s;
        for (auto ch : s)
            ++occurrences[ch - 'a'];

        while (q--)
        {
            ans = 0;
            cin >> c;
            for (int i = 0; i < 26; ++i)
                if (occurrences[i] > c)
                    ans += occurrences[i] - c;

            cout << ans << endl;
        }
    }
    return 0;
}

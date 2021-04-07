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
        string s;
        cin >> s;

        int          n = s.size();
        vector<int>  cnt(3, 0);
        vector<char> choices = {'a', 'A', '0'};
        auto         id      = [](char c) {
            if (islower(c))
                return 0;
            else if (isupper(c))
                return 1;
            else
                return 2;
        };
        cnt[id(s[0])]++;
        int pivot = 0;
        for (int i = 1; i < n; ++i)
        {
            cnt[id(s[i])]++;
            if (id(s[i]) == id(s[i - 1]))
                pivot = i - 1;
        }
        for (int i = 0; i < 3; ++i)
            if (cnt[i] == 0)
                s[pivot++] = choices[i];
        cout << s << endl;
    }
    return 0;
}

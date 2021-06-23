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

int h, m;

vector<int> rev = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

inline int num(char msd, char lsd) { return (msd - '0') * 10 + (lsd - '0'); }

int mirror(int x)
{
    int msd = rev[x % 10], lsd = rev[x / 10];
    if (msd == -1 or lsd == -1)
        return -1;
    return msd * 10 + lsd;
}

string clk(int x)
{
    int    mn = x % m, hr = (x / m) % h;
    string ans(5, '0');
    ans[2] = ':';

    ans[3] = (mn / 10) + '0';
    ans[4] = (mn % 10) + '0';

    ans[0] = (hr / 10) + '0';
    ans[1] = (hr % 10) + '0';
    return ans;
}

bool valid(int x)
{
    int mn = x % m, hr = (x / m) % h;

    mn = mirror(mn);
    hr = mirror(hr);
    swap(mn, hr);
    // dbg(clk(x), hr, mn);
    return 0 <= mn and mn < m and 0 <= hr and hr < h;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> h >> m;

        string s;
        cin >> s;
        int x = num(s[3], s[4]) + m * num(s[0], s[1]);
        while (!valid(x))
            x++;
        cout << clk(x) << endl;
    }
    return 0;
}

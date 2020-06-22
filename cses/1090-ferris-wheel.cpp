#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

int main(void)
{
    int n, x, l = 0, ans = 0;
    cin >> n >> x;

    vi p(n);
    for (auto &pi : p)
        cin >> pi;

    sort(p.begin(), p.end());
    for (int i = n - 1; i >= l; --i)
    {
        if (p[i] + p[l] <= x)
            ++l;
        ++ans;
    }
    cout << ans << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

string ans[6] = {"1/6", "1/3", "1/2", "2/3", "5/6", "1/1"};

int main(void)
{
    int y, w, x;
    cin >> y >> w;
    x = 6 - max(y, w) + 1;
    cout << ans[x - 1] << endl;

    return 0;
}

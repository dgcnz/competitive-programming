#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size();

using namespace std;
using ll = long long;
using vi = vector<int>;

int main(void)
{
    int a, b;
    cin >> a >> b;

    b--;
    a--;

    cout << (a + b - 1) / a << endl;

    return 0;
}

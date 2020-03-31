#include <iostream>
#include <map>

using namespace std;

const int NMAX = 1000 + 11;

int           ccolor;
int           colors[NMAX];
map<int, int> rankdiv;

int smallest_div(int x)
{
    if (x % 2 == 0)
        return 2;

    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return i;

    return x;
}

int main(void)
{
    int t, n, x, sd;

    cin >> t;
    while (t--)
    {
        rankdiv.clear();
        ccolor = 1;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            sd        = smallest_div(x);
            colors[i] = rankdiv[sd] = (rankdiv[sd] ? rankdiv[sd] : ccolor++);
        }

        cout << ccolor - 1 << endl;

        for (int i = 0; i < n; ++i)
            cout << colors[i] << " ";
        cout << endl;
    }
    return 0;
}

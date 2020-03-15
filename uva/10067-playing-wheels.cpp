#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;
using vi = vector<int>;

int      initial, target;
set<int> prohibited;

vi moves = {-1000, 1000, -100, 100, -10, 10, -1, 1};

int getn(int i, int n) { return (n / (int)pow(10, 3 - i)) % 10; }
int setn(int i, int n, int x)
{
    int l = 0, r = 0, ans = 0;

    ans = (x * (int)pow(10, 3 - i));

    if (i > 0)
        l = (n / (int)pow(10, 3 - (i - 1))) * (int)pow(10, 3 - (i - 1));
    if (i < 3)
        r = (n % (int)pow(10, 3 - i));

    return l + ans + r;
}

int concat(vi numbers)
{
    int ans = 0;

    setn(0, ans, numbers[0]);
    setn(1, ans, numbers[1]);
    setn(2, ans, numbers[2]);
    setn(3, ans, numbers[3]);

    return ans;
}

int mod(int a, int b) { return (b + (a % b)) % b; }

int add(int x, int y)
{
    for (int i = 0; i < 4; ++i)
        setn(i, x, mod(getn(x, i) + getn(y, i), 10));

    return x;
}

int compute(int x, int y)
{
    int ans = 0;

    for (int i = 0; i < 4; ++i)
        ans += abs(getn(i, x) - getn(i, y));

    return ans;
}

int bfs(int start)
{
    bool       visited[10000] = {false};
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (q.size())
    {
        int x = q.front();
        q.pop();

        for (auto move : moves)
        {
            int y = add(x, move);
            if (y == target)
            {
                return compute(target, initial);
            }
            if (not visited[y] and prohibited.find(y) == prohibited.end())
            {
                visited[y] = true;
                q.push(y);
            }
        }
    }

    return -1;
}

int main(void)
{
    int t, m;
    vi  temp(4);

    cin >> t;

    while (t--)
    {
        for (int i = 0; i < 4; ++i)
            cin >> temp[i];
        initial = concat(temp);

        for (int i = 0; i < 4; ++i)
            cin >> temp[i];

        target = concat(temp);

        cin >> m;
        while (m--)
        {
            for (int i = 0; i < 4; ++i)
                cin >> temp[i];
            prohibited.insert(concat(temp));
        }

        cout << bfs(initial) << endl;

        prohibited = set<int>();
    }

    return 0;
}

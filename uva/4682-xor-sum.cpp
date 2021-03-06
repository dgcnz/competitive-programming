#include <bits/stdc++.h>

using namespace std;

const int NMAX     = 1e5 + 11;
const int ALPHA_SZ = 2;

int n, a[NMAX];

struct tnode
{
    int    val;
    tnode *children[ALPHA_SZ];

    tnode()
    {
        this->val = -1;
        for (int i = 0; i < ALPHA_SZ; ++i)
            this->children[i] = nullptr;
    }
    ~tnode()
    {
        for (int i = 0; i < ALPHA_SZ; ++i)
        {
            if (this->children[i] != nullptr)
                delete (this->children[i]);

            this->children[i] = nullptr;
        }
        val = 0;
    }
};

void insert(tnode *root, int key)
{
    tnode *v = root;
    for (int i = 31; i >= 0; --i)
    {
        int ix = (key >> i) & 1;
        if (v->children[ix] == nullptr)
            v->children[ix] = new tnode();

        v = v->children[ix];
    }
    v->val = key;
}

// most different value
int query(tnode *root, int key)
{
    tnode *v = root;
    for (int i = 31; i >= 0; --i)
    {
        int ix = !((key >> i) & 1); // try opposite
        if (v->children[ix] != nullptr)
            v = v->children[ix];
        else
            v = v->children[1 - ix];
    }
    return v->val;
}

int main(void)
{
    int t, ans, acc;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        acc = ans   = 0;
        tnode *root = new tnode();
        insert(root, acc);
        for (int i = 0; i < n; ++i)
        {
            acc = acc ^ a[i];
            ans = max(ans, acc ^ query(root, acc));
            insert(root, acc);
        }
        cout << ans << endl;
        delete (root);
    }
    return 0;
}

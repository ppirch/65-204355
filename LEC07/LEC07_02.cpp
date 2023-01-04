#include <bits/stdc++.h>

using namespace std;

int getMid(int s, int e)
{
    return s + (e - s) / 2;
}

int MaxUtil(int *st, int ss, int se, int l,
            int r, int node)
{
    if (l <= ss && r >= se)
        return st[node];

    if (se < l || ss > r)
        return -1;

    int mid = getMid(ss, se);

    return max(MaxUtil(st, ss, mid, l, r,
                       2 * node + 1),
               MaxUtil(st, mid + 1, se, l,
                       r, 2 * node + 2));
}

void updateValue(int arr[], int *st, int ss, int se,
                 int index, int value, int node)
{
    if (index < ss || index > se)
    {
        cout << "Invalid Input" << endl;
        return;
    }

    if (ss == se)
    {
        arr[index] = value;
        st[node] = value;
    }
    else
    {
        int mid = getMid(ss, se);

        if (index >= ss && index <= mid)
            updateValue(arr, st,
                        ss, mid, index,
                        value, 2 * node + 1);
        else
            updateValue(arr,
                        st, mid + 1, se,
                        index,
                        value, 2 * node + 2);

        st[node] = max(st[2 * node + 1],
                       st[2 * node + 2]);
    }
    return;
}

int getMax(int *st, int n, int l, int r)
{
    if (l < 0 || r > n - 1 || l > r)
    {
        printf("Invalid Input");
        return -1;
    }

    return MaxUtil(st, 0, n - 1, l, r, 0);
}

int constructSTUtil(int arr[], int ss, int se,
                    int *st, int si)
{

    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    int mid = getMid(ss, se);

    st[si] = max(constructSTUtil(arr, ss, mid, st,
                                 si * 2 + 1),
                 constructSTUtil(arr, mid + 1, se,
                                 st, si * 2 + 2));

    return st[si];
}

int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));

    int max_size = 2 * (int)pow(2, x) - 1;

    int *st = new int[max_size];

    constructSTUtil(arr, 0, n - 1, st, 0);

    return st;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    int arr[n + 5];
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }

    int *st = constructST(arr, n);

    vector<int> arr2;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        arr2.push_back(x);
    }

    vector<int> dp2(n);
    dp2[0] = arr2[0];
    for (int i = 1; i < n; ++i)
    {
        dp2[i] = dp2[i - 1] + arr2[i];
    }

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        int val = -1;

        val = getMax(st, n, a, b);

        if (a == 0)
            cout
                << val << " " << dp2[b] << endl;

        else
            cout << val << " " << dp2[b] - dp2[a - 1] << endl;
    }

    return 0;
}
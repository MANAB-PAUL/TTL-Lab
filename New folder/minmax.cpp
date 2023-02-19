#include <bits/stdc++.h>
#define loop(i, n) for (int i = 0; i < n; ++i)
#define pii pair<int, pair<int, int>>
using namespace std;
const bool cmp(vector<int>&a, vector<int>&b)
{
    return a[0] < b[0];
}
int main()
{
    int m, t;
    // cout << "enter number of machines and tasks:- ";
    cin >> m >> t;
    vector<vector<int>> arr(m, vector<int>(t));
    vector<bool> visited(t, false);
    int curr_time = 0;
    loop(i, m) loop(j, t) cin >> arr[i][j];
    while (true)
    {
        vector<pii> arrge;
        for (int tsk = 0; tsk < t; ++tsk)
        {
            for (int mac = 0; mac < m; ++mac)
            {
                arrge.push_back({arr[mac][tsk], {mac, tsk}});
                // cout << arr[mac][tsk] << endl;
                // cout << mac << endl;
            }
        }
        sort(arrge.begin(), arrge.end());
        // for(int i=0;i<arrge.size();++i) cout << arrge[0].second.first << endl;
        cout << arrge[0].first << endl;
        int curr_task = arrge[0].second.second, curr_mac = arrge[0].second.first;
        visited[curr_task] = true;
        int val = arr[curr_mac][curr_task];
        // arr[curr_mac][curr_task] = INT_MAX;
        for (int i = 0; i < t; ++i)
        {
            if(i != curr_task) arr[curr_mac][i] += val;
        }
        for (int i = 0; i < m; ++i)
        {
            arr[i][curr_task] = INT_MAX;
        }
        cout << "current task performed is :- " << curr_task << " at time :- " << curr_time << " at machine " << curr_mac << endl;
        curr_time += val;
        bool comp = true;
        for (int i = 0; i < t; ++i)
            if (visited[i] == false)
                comp = false;
        if (comp)
            break;
    }
    return 0;
}
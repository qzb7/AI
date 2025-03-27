#include <iostream> 
#include <queue> 
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) 
    {
        int a, b;
        cin >> a >> b;
        g[a - 1].emplace_back(b - 1);
    }
    int dist[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = -1;
    }
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        if (a == n-1) break;
        for (int b : g[a]) 
        {
            if (dist[b] == -1) 
            {
                dist[b] = dist[a] + 1;
                q.push(b);
            }
        }
        
    }
    cout << dist[n-1] << endl;

}
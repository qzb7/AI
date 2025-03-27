#include <iostream> 
#include <vector>
#include <queue>
using namespace std;
#define max 1e9
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    for (int i = 0; i < m; i++) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].emplace_back(b - 1, c);
    }
    int dist[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = max;
    }
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        int x = q.top().second;
        int d = q.top().first;
        q.pop();
        if (d > dist[x]) continue;
        for (auto a : g[x])
        {
            if (dist[a.first] > dist[x] + a.second)
            {
                dist[a.first] = dist[x] + a.second;
                q.push({dist[a.first], a.first});
            }
        }
    }
    if (dist[n - 1] == max)
    {
        cout << -1;
    }
    else
    {
        cout << dist[n - 1];
    }
}
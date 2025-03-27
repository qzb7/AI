#include <iostream> 
#include <vector>
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
    int used[n];
    for (int i = 0; i < n; i++)
    {
        used[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int x = -1;
        for (int j = 0; j < n; j++)
        {
            if (used[j] == 0 && ( x == -1 || dist[j] < dist[x]))
            {
                x = j;
            }
        }
        if (dist[x] == max) break;
        used[x] = 1;
        for (auto a : g[x])
        {
            if (dist[a.first] > dist[x] + a.second)
            {
                dist[a.first] = dist[x] + a.second;
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
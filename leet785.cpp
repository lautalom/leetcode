#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//restrictions
// graph.length == n
// 1 <= n <= 100
// 0 <= graph[u].length < n
// 0 <= graph[u][i] <= n - 1
// graph[u] does not contain u.
// All the values of graph[u] are unique.
// If graph[u] contains v, then graph[v] contains u.

short colores[100]; // colores[i] = color de v_i

class Solution
{
public:
    void colorear(int v, int c)
    {
        if (!colores[v])
            colores[v] = c;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        bool ans = true;
        for (int i = 0; i < graph.size() && ans; i++)
        {
            colorear(i, i % 2 + 1);
            int current = colores[i];
            for (auto j = graph[i].begin(); ans && j != graph[i].end(); j++)
            {
                colorear(*j, (current)% 2 + 1);
                if (colores[*j] == current)
                    ans= !ans;
                //cout << "vector " << i << ", item: "<< *j << ", color:" <<colores[*j]<< endl;
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> q = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    Solution s;
    cout << s.isBipartite(q) << endl;
    return 0;
}
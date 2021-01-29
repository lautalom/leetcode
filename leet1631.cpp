class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int row = heights.size();
        if (row == 0)
            return 0;
        int col = heights[0].size();
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        priority_queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        while (!q.empty())
        {
            pair<int, pair<int, int>> xx = q.top();
            q.pop();
            int x = xx.second.first;
            int y = xx.second.second;
            if (x == row - 1 && y == col - 1)
                return -xx.first;
            int dis = -xx.first;
            for (int i = 0; i < 4; i++)
            {
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if (nx < 0 || nx >= row || ny < 0 || ny >= col)
                    continue;
                int ab = max(dis, abs(heights[x][y] - heights[nx][ny]));
                if (ab < dist[nx][ny])
                {

                    dist[nx][ny] = ab;
                    q.push({-ab, {nx, ny}});
                }
            }
        }

        return -1;
    }
};
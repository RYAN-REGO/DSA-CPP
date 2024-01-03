//every minute ---> BFS HAS TO USED


#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here.
    int vis[n][m];

    queue<pair<pair<int, int> , int>> q;
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < m; col++)
        {
            //if the orange is rotten
            if(grid[row][col] == 2)
            {
                q.push({{row, col}, 0});
                vis[row][col] = 1;
            }
            else
                vis[row][col] = 0;
        }
    }

    //we have got the rotten oranges
    int tm = 0;
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int row = it.first.first;
        int col = it.first.second;
        int time = it.second;

        tm = max(time, tm);
        for(int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            //if the orange is reachable and it is fresh
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1 && 
            !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, time + 1});
            }
        }

    }

    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < m; col++)
        {
            if(grid[row][col] == 1 && !vis[row][col])
            {
                //the orange is fresh and not visited
                return -1;
            }
        }
    }

    return tm;
}
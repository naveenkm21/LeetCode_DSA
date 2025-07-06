class Solution {
public:
    int bfs(vector<vector<char>>& maze, int n, int m, int x, int y)
    {
        queue<pair<int,int>> q;
        q.push({x,y});
        maze[x][y]='+';
        int steps=0;

        while(!q.empty())
        {
            int size=q.size();
            bool moved=false;
            while(size--)
            {
                int currx=q.front().first;
                int curry=q.front().second;
                q.pop();

                int thisx[]={-1,1,0,0};
                int thisy[]={0,0,-1,1};

                for(int i=0; i<4; i++)
                {
                    int row=thisx[i]+currx;
                    int col= thisy[i]+curry;

                    if(row>=0 and col>=0 and row<=n-1 and col<=m-1 and maze[row][col]=='.')
                    {
                        if(row==0 || col==0 || row==n-1 || col==m-1)return steps+1;

                        maze[row][col]='+';
                        q.push({row,col});
                        moved=true;
                    }
                }
            }
            if(moved)steps++;
        }
        return -1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int n=maze.size();
        int m=maze[0].size();
        int ans=bfs(maze,n,m,entrance[0],entrance[1]);
        return ans;
    }
};
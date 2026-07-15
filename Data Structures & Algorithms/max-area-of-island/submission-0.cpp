class Solution {
public:
    int dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int n,int m){
        vis[n][m]=1;
        int cnt =1;

        int row[4]={-1,0,1,0};
        int col[4]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=n+row[i];
            int ncol=m+col[i];

            if(0<=nrow&& nrow<grid.size() && 0<=ncol && ncol<grid[0].size() && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                cnt=cnt+dfs(grid,vis,nrow,ncol);
                
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int maxi=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int x= dfs(grid,vis,i,j);
                    maxi=max(x,maxi);
                }


            }
        }
        return maxi;
        
    }
};

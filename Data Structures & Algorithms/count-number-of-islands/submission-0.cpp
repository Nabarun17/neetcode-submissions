class Solution {
public:
    void dfs(int n ,int m , vector<vector<char>>&grid,vector<vector<int>>&visited){
        visited[n][m]=1;
        int col[4]={-1,0,1,0};
        int rol[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=n+rol[i];
            int ncol=m+col[i];
            if((0<=nrow&&nrow<grid.size()) && (0<=ncol && ncol<grid[0].size()) && !visited[nrow][ncol]&& grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,grid,visited);
            }
        }

        }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
    
        vector<vector<int>>visited(n,vector<int>(m,0));
        int cnt =0;

        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(i,j,grid,visited);
                    cnt++;
                }
            }
        }

        return cnt;



        

        
    }
};

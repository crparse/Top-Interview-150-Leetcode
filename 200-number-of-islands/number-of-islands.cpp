class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j, int row, int column){
        if(i<0 or j<0 or j==column or i==row or grid[i][j]=='0') return;
        grid[i][j]='0';
        dfs(grid,i+1,j,row,column);
        dfs(grid,i-1,j,row,column);
        dfs(grid,i,j+1,row,column);
        dfs(grid,i,j-1,row,column);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int column=grid[0].size();
        int totalIsLand=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(grid[i][j]=='1'){
                    totalIsLand++;
                    dfs(grid,i,j,row,column);
                }
            }
        }
        return totalIsLand;
    }
};
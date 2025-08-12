#include <iostream>
using namespace std;

void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        visited[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0]. size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //traverse it's neighbours:
            for(int delRow = -1; delRow<=1; delRow+=2){
                
                int nrow = row + delRow;
                int ncol = col;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                && grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                    cout<<nrow<<" "<<ncol<<" "<<endl;
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
                
            }
            for(int delCol = -1; delCol<=1; delCol+=2){
                
                int nrow = row ;
                int ncol = col+ delCol;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                && grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                    cout<<nrow<<" "<<ncol<<" "<<endl;
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
                
            }

        }
        

    }

    int numIslands(vector<vector<char>>& grid) {
        int totalRow = grid.size();
        int totalCol = grid[0]. size();
        vector<vector<bool>> visited(totalRow, vector<bool>(totalCol, false));

        int count =0;
        
        for(int row=0; row<totalRow; row++){
            for(int col=0; col<totalCol; col++){
                if(grid[row][col]=='1' && (!(visited[row][col]))){
                    count++;
                    cout<<"here"<<row<<" "<<col<<endl;
                    bfs(row, col, grid, visited);
                }
            }
        }
        return count;
    }

int main()
{
    vector<vector<char>> grid = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
    };
    int res = numIslands(grid);
    cout<<res<<endl;

    return 0;
}
 #include <iostream>
 using namespace std;

 bool helper(vector<vector<int>> &grid, int row, int col, int n,int expVal){

    if(row<0 || col<0 || row>=n || col>=n || grid[row][col]!=expVal){
        return false;
    }
    if(grid[row][col]==(n*n -1)){
        return true;
    }

    //8 moves
    bool ans1 = helper(grid, row+2, col-1, n, expVal+1);
    bool ans2 = helper(grid, row+2, col+1, n, expVal+1);
    bool ans3 = helper(grid, row-2, col+1, n, expVal+1);
    bool ans4 = helper(grid, row-2, col-1, n, expVal+1);
    bool ans5 = helper(grid, row-1, col+2, n, expVal+1);
    bool ans6 = helper(grid, row-1, col-2, n, expVal+1);
    bool ans7 = helper(grid, row+1, col+2, n, expVal+1);
    bool ans8 = helper(grid, row+1, col-2, n, expVal+1);

    return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;
 }

 bool knight(vector<vector<int>> &grid){
    int row = 0;
    int col = 0;
    int n = grid.size();
    int expVal = 0;

    bool res = helper(grid, row, col, n, expVal);

    return res;

 }

 int main()
 {
    vector<vector<int>> vec = {
        {0,11,16,5,20},
        {17,4,19,10,15},
        {12,1,8,21,6},
        {3,18,23,14,9},
        {24,13,2,7,22}
    };
    bool ans = knight(vec);
    cout<<ans<<endl;

     return 0;
 }
#include <iostream>
using namespace std;

int fun(int mat[][3]){ 
     //whenerver we pass 2-D matrix in a function we must specify the column.
     //(the compiler need this information to access the elemetn od 2d array correctly)
    return 0;
}

//returning par<int,int>
pair<int, int> search(int mat[][3], int row, int col, int target){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(mat[i][j] == target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

//Max Row Sum
int maxRow(int mat[][3], int row, int col){
    int maxx = INT_MIN;
    for(int i=0; i<row; i++){
        int rowSum = 0;
        for(int j=0; j<col; j++){
            rowSum += mat[i][j];
        }
        maxx = max(maxx, rowSum);
    }
    return maxx;
}
//Max Column Sum
int maxCol(int mat[][3], int row, int col){
    int maxx = INT_MIN;
    for(int i=0; i<row; i++){
        int colSum = 0;
        for(int j=0; j<col; j++){
            colSum += mat[j][i];
        }
        maxx = max(maxx, colSum);
    }
    return maxx;
}

//Diagonal SUm
int diaSum(int mat[][3], int n){
    int dSum = 0;
    for(int i=0; i<n; i++){
        dSum += mat[i][i];
        if(i != n-1-i){ // to tackle common element
            dSum += mat[i][n-1-i];
        }
    }
    return dSum;
}

int main()
{
    //2D array

    int mat[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int row = 3;
    int col = 3;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<mat[i][j]<<endl;
        }
    }
    int* ptr = &mat[0][0];
    for(int i=0; i<9; i++){
        cout<<ptr+i<<endl; //how MATRIX STORED INTERNALLY
    }
    int target = 7;
    pair<int, int> p = search(mat, row, col, target);
    cout<<p.first<<" "<<p.second<<endl;

    cout<<maxRow(mat, row, col)<<endl;
    cout<<maxCol(mat, row, col)<<endl;

    cout<<diaSum(mat, row)<<endl;

    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    matrix[2][3] = 27; // dynamic

    
    return 0;
}
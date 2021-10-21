#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> res;

bool isSafe( int i ,int j , vector<vector<int>>& board){
    
    for( int row = i-1, col = j ; row >= 0 ; row--){
        
        if( board[row][col]) return false;
    }
    
    for( int row = i-1, col = j-1 ; row >= 0 && col >= 0 ; row-- , col--){
        
        if( board[row][col]) return false;
    }    
    for( int row = i-1, col = j+1 ; row >= 0 && col < board.size() ; row-- , col++){
        
        if( board[row][col]) return false;
    }
    
    return true;
}

void isQueenUtil( vector<vector<int>>& board , int n , int i){
    
    if( i == n){
        vector<int> temp;
        for( int row = 0; row < n; row++){
            for( int col = 0 ; col < n; col++){
                
                if( board[row][col]) temp.push_back(col+1);
            }
        }
        
        res.push_back(temp);
        
        return ;
    }
    
    for( int j = 0; j < n ; j++){
        
        if( isSafe( i,j,board)){
            
            board[i][j] = 1;
            isQueenUtil( board , n , i+1);
            board[i][j] = 0;
        }
    }
}

vector<vector<int>> isQueen( int n){
    
    res.clear();
    vector<vector<int>> board(  n , vector<int>(  n , 0));
    
    isQueenUtil( board , n , 0);
    
    return res;
}



int main(){
    
    int n;
    cin>>n;
    
    vector<vector<int>> res = isQueen(n);
    
    for( int i = 0; i < res.size() ; i++){
        
        cout<<"[ ";
        for( auto j : res[i]){
            cout<< j<<" ";
        }
        cout<<" ]\n";
    }
}

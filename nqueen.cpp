#include<iostream>
using namespace std;
//hardcoding the value of the size of the array.
const int N = 6;

bool IsSafe(int arr[N][N] , int r , int c){
    int i,j;
    //checking if attacking in row 
    for(i=0;i<c;i++){
        if(arr[r][i]==1){
            return false;
        }
    }
    //checking for upper left diagnol
    for(i=r , j=c ; j>=0 && i >=0 ; i-- ,j-- ){
        if(arr[i][j]==1){
            return false;
        }
    }
    //checking for upper top diagnol
    for(i=r , j=c ; j<N && i>=0 ; i-- , j++){
        if(arr[i][j] == 1){
            return false;
        }
    }
    //if non of the loop condition matches it means that the theres is no queen in the row, column, diagnol.
    return true;
}

bool nQueen(int arr[N][N] , int c){
    //base condition
    //this means we will terminate the function once all queen have been placed.
   if(c >= N){
    return true;
   }
    for(int i=0;i<N;i++){
        if(IsSafe(arr,i,c)){
            arr[i][c] = 1;
            if(nQueen(arr,c+1)){
                return true;
            }
            arr[i][c]=0;
        }
    }
    return false;
}

void printNqueen(int arr[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(arr[i][j]==1){
                cout<<"Q";
            }
            else{
                cout<<"X";
            }
        }
        cout<<endl;
    }
} 

bool checksol(){
    int arr[N][N] = {{0,0,0,0},
                     {0,0,0,0},
                     {0,0,0,0},
                     {0,0,0,0}};
    if(nQueen(arr,0) == false){
        cout<<"The Solution donot exsists."<<endl;
        return false;
    }
    else{
        printNqueen(arr);
        return true;
    }
}

int main(){
    checksol();
}
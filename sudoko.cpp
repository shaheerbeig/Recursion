#include<iostream>
using namespace std;
bool IsSafe(int **arr,int r , int c , int N , int val){
    for(int i=0;i<N;i++){
        //checking rows.
        if(arr[r][i]==val){
            return false;
        }
    }
    for(int i=0;i<N;i++){
        //checking columns
        if(arr[i][c]==val){
            return false;
        }
    }
    int rowmatrix = r - r % 3;
    int columnmatrix = c - c % 3;
    for(int i=0;i<N/3;i++){
        for(int j=0;j<N/3;j++){
            if(arr[i+rowmatrix][j+columnmatrix]==val){
                return false;
            }
        }
    }
    //if non of the condition returns true means we can place the val at the position 
    return true;
}

bool sudoko(int **arr, int r , int c , int N){
    int i,j,val;
    if(r == 8 && c ==8){
        return true;
    }
    if(c>=N){
        c=0;
        r++;
    }
     if (arr[r][c] > 0)
    {
        return (sudoko(arr,r,c+1,N));
    }
    for(val=1;val<=9;val++){
        if(IsSafe(arr,r,c,N,val)){
            arr[r][c] = val;
            if(sudoko(arr,r,c+1,N)==true){
                return true;
            }
            else{
                arr[r][c] = 0;
            }
        }
    }
    return false;
}
void print(int **arr , int N){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
   int N=9;
   int rougharray[9][9] ={{5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    int **arr;
    arr = new int*[N];
    for(int i=0;i<N;i++){
        arr[i] = new int[N];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            arr[i][j] = rougharray[i][j];
        }
    }
    if(sudoko(arr,0,0,N)==true){
        print(arr,N);
    }
    else{
        cout<<"No solution exsists."<<endl;
    }
}
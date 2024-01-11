#include<iostream>
using namespace std;

bool IsSafe(int **arr , int r , int c , int N){
    if(r>=0 && c>=0 && c<N && r<N && arr[r][c]==0){
        return true;
    }
    else{
        return false;
    }
}

bool knight(int **arr , int r , int c ,int N , int ctr){
    int value = N*N;
    //this means that the value has been placed at every index of the board.
    if(value == ctr){
        return true;
    }
    if(IsSafe(arr,r,c,N)==true){
        arr[r][c] = ctr;
        if(knight(arr,r+2,c+1,N,ctr+1)==true){
            return true;
        }
        if(knight(arr,r+2,c-1,N,ctr+1)==true){
            return true;
        }
        if(knight(arr,r+1,c+2,N,ctr+1)==true){
            return true;
        }
        if(knight(arr,r-1,c+2,N,ctr+1)==true){
            return true;
        }
        if(knight(arr,r+1,c-2,N,ctr+1)==true){
            return true;
        }
        if(knight(arr,r-1,c-2,N,ctr+1)==true){
            return true;
        }
        if(knight(arr,r-2,c+1,N,ctr+1)==true){
            return true;
        }
        if(knight(arr,r-2,c-1,N,ctr+1)==true){
            return true;
        }
        arr[r][c]=0;
    }
    return false;
}
bool bolcheck(){
    int N,i,j;
    cout<<"Enter the value of the Matrix:";
    cin>>N;
    int **arr;
    arr = new int*[N];
    for(i=0;i<N;i++){
        arr[i] = new int[N];
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            arr[i][j] = 0;
        }
    }
    int ctr=0;
    if(knight(arr,0,0,N,ctr)==true){
        int i,j;
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                cout<<arr[i][j]<<"  ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"Solution donot exsists.";
        return false;
    }
}

int main(){
    bolcheck();
}
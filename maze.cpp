#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//this function will check whether can the rat move in the direction.
bool IsSafe(int **arr , int x , int y , int N){
    if(x>=0 && y>=0 && x<N && y<N && arr[x][y]==0){
        return true;
    }
    else{
        return false;
    }
}

//this function will make the directions in the maze.
bool maze(int **arr , int x , int y , int N, int **arrsol){
    //base condition
    //we are checking if the maze has reached to the specified output and if the block at the output is open or not.
    if(y==0 && x== N-2 && arr[x][y] == 0){
        arrsol[x][y] = 0;
        return true;
    }

    if(IsSafe(arr,x,y,N)==true){
        //if the issafe function return the value true means we can move further the path and current index will be considered an open path.
        if(arrsol[x][y] !=0 ){

            arrsol[x][y] = 0;
            
            //moving in the down direction
            if(maze(arr,x+1,y,N,arrsol)){
                return true;
            }
            //moving in the up direction
            if(maze(arr,x-1,y,N,arrsol)){
                return true;
            }
            //moving in the right direction
            if(maze(arr,x,y+1,N,arrsol)){
                return true;
            }
            //moving in the left direction
            if(maze(arr,x,y-1,N,arrsol)){
                return true;
            }
            arrsol[x][y] = 1;
            return false;
        }
    }
    return false;
}

int main(){
    srand(time(0));
    int **arr;
    int **solarr;
    int j,N,i;
    cout<<"Enter the value of N Matrix:";
    cin>>N;

    arr = new int *[N];
    solarr = new int *[N];

    for(i=0;i<N;i++){
        arr[i] = new int[N];
        solarr[i] = new int[N];
        for(j=0;j<N;j++){
            if(rand()%5 < 3){
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = 1;
            }
            //assigning values to the other array.
            solarr[i][j] = 1;
        }
    }
    //manually assuring that the opening and ending cells are always open
    arr[1][N-1]=0;
    arr[N-2][0]=0;

     for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    if(maze(arr,1,N-1,N,solarr)==true){
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                cout<<solarr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                cout<<solarr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"Solution Donot Exsists."<<endl;

    }
}
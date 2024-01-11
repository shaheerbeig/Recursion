#include<iostream>
using namespace std;
int ctr=0;
//this function will check whether L shaped condition is matched or not.We will check the values are not going out of bound and that whether a night is place in the particular position.
bool IsSafe(int **arr, int r, int c, int N)
{
    if (r < N && c < N && r >= 0 && c >= 0 && arr[r][c] == 0)
    {

        if (r - 2 >= 0 && c + 1 < N && arr[r - 2][c + 1] == 1)
        {
            return false;
        }
        if (r - 2 >= 0 && c - 1 >= 0 && arr[r - 2][c - 1] == 1)
        {
            return false;
        }
        if (r - 1 >= 0 && c + 2 < N && arr[r - 1][c + 2] == 1)
        {
            return false;
        }
        if (r - 1 >= 0 && c - 2 >= 0 && arr[r - 1][c - 2] == 1)
        {
            return false;
        }
        if (r + 1 < N && c + 2 < N && arr[r + 1][c + 2] == 1)
        {
            return false;
        }
        if (r + 2 < N && c + 1 < N && arr[r + 2][c + 1] == 1)
        {
            return false;
        }
        if (r + 1 < N && c - 2 >= 0 && arr[r + 1][c - 2] == 1)
        {
            return false;
        }
        if (r + 2 < N && c - 1 >= 0 && arr[r + 2][c - 1] == 1)
        {
            return false;
        }
        // if non of the condition matches it means that we can place the knight there.
        return true;
    }
    return false;
}

bool knight(int **arr , int c , int N , int ctr){
    //base condition all knights have been placed.
    int value = (N*N)/2;
    //we are checking whether all the knights have been placed.
    if( ctr == value ){
        return true;
    }
    //making the columns equal to zero 
    if(c>=N){
        c=0;
    }
    for(int i=0;i<N;i++){
        if(IsSafe(arr,i,c,N)){
            arr[i][c]=1;
            if(knight(arr,c+1,N,ctr+1)==true){
                return true;
            }
            arr[i][c] = 0;
        }
    }
    return false;
}

void printsol(int **arr,int N){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(arr[i][j]==1){
                cout<<" K ";
            }
            else{
                cout<<" . ";
            }
        }
        cout<<endl;
    }
}

bool solcheck(){
    int N;
    cout<<"Enter The value of the matrix:";
    cin>>N;
    int **arr;
    arr = new int*[N];
    for(int i=0;i<N;i++){
        arr[i] = new int[N];
    }
    //initializing the array with 0.
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            arr[i][j] = 0;
        }
    }
    if(knight(arr,0,N,0)==true){
        printsol(arr,N);
        
    }
    else{
        cout<<"Cannot Place all Knights:"<<endl;
        
    }
}

int main(){
    solcheck();

}
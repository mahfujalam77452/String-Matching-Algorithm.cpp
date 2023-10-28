#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int bit[N];
int GetSum(int i){
    //Here the loop will run till the number of set bit.
    //And the number of set bit of number can be (log(n)).
    //Here the time complexity is O(log(n)).
    int sum=0;
    for(;i>0;i-=(i&-i)){
        sum+=bit[i];
    }
    return sum;
}
//The sum between the range of l-r will GetSum(r)-GetSum(l-1);
void Update(int i,int value)
{
    for(;i<=N;i+=(i&(-i))){
        bit[i]+=value;
    }
}
/*
if we want to replace a data then {
    Update(i,value-arr[i],bit,N);
    arr[i]=value;
}
*/
int main(){
    int n,q;
    cin>>n>>q;
    int arr[n+10];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        Update(i,arr[i]);
    }
    //There are two type of queries.
    //1.Replace a number from i th index.
    //2.Get the sum between the range l-r.
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int i,value;
            cin>>i>>value;
            Update(i,value-arr[i]);
            arr[i]=value;
            
        }
        else {
            int l,r;
            cin>>l>>r;
            cout<<GetSum(r)-GetSum(l-1)<<endl;
        }
    }
    
    return 0;
}

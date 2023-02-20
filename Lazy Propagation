/*1) If current segment tree node has any pending
   update, then first add that pending update to
   current node.
2) If current node's range lies completely in
   update query range.
....a) Update current node
....b) Postpone updates to children by setting
       lazy value for children nodes.
3) If current node's range overlaps with update
   range, follow the same approach as above simple
   update.
...a) Recur for left and right children.
...b) Update current node using results of left
      and right calls.*/
      // Here the code for collecting sum for speacific range.

#include<bits/stdc++.h>
using namespace std;
void buildtree(int *arr,int *tree,int index,int s,int e)
{
    //base case
    if(s>e)return;
    //base case
    if(s==e){
        tree[index]=arr[s];
        return;
    }
    int mid=(s+e)/2;
    //Recursive call
    buildtree(arr,tree,2*index,s,mid);
    buildtree(arr,tree,2*index+1,mid+1,e);
    int lefttree=tree[2*index];
    int righttree=tree[2*index+1];
    tree[index]=lefttree+righttree;
    return;

}



void updaterangelazy(int *tree,int lazy[],int index,int s,int e,int rs,int re,int value)
{
    if(lazy[index]!=0){
        tree[index]+=(e-s+1)*lazy[index];
        if(s!=e){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
        
    }
    if(s>e||e<rs||s>re)return;
    if(s>=rs&&e<=re){
        tree[index]+=(e-s+1)*value;
        if(s!=e){
            lazy[index*2]+=value;
            lazy[index*2+1]+=value;
        }
        return;
    }
    int mid=(s+e)/2;
    updaterangelazy(tree,lazy,2*index,s,mid,rs,re,value);
    updaterangelazy(tree,lazy,2*index+1,mid+1,e,rs,re,value);
    tree[index]=tree[index*2]+tree[index*2+1];
}
int  getsum(int *tree,int lazy[],int index,int s,int e,int rs,int re)
{
    if(lazy[index]!=0){
        tree[index]+=(e-s+1)*lazy[index];
        if(s!=e){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
        
    }
    if(s>e||e<rs||s>re)return 0;
    if(s>=rs&&e<=re){

        return tree[index];
    }
    int mid=(s+e)/2;
    return getsum(tree,lazy,2*index,s,mid,rs,re)+
    getsum(tree,lazy,2*index+1,mid+1,e,rs,re);

}
int main()
{
    int arr[]={1,3,2,-2,4,5};
    int n=sizeof(arr)/sizeof(int);
    int *tree=new int [4*n+1];
    int lazy[4*n+1]={0};
    int index=1;
    int s=0;
    int e=n-1;
    buildtree(arr,tree,index,s, e);
    cout<<getsum(tree, lazy,index,s,e,0,5)<<endl;
    updaterangelazy(tree,lazy,index,s,e,2,4,2);
    cout<<getsum(tree, lazy,index,s,e,2,4)<<endl;
    updaterangelazy(tree,lazy,index,s,e,0,1,2);
    cout<<getsum(tree, lazy,index,s,e,2,4)<<endl;
    cout<<getsum(tree, lazy,index,s,e,0,5)<<endl;



    return 0;
}


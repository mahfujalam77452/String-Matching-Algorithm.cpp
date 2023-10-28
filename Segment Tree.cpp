#include<bits/stdc++.h>
using namespace std;
void build_tree(int *arr,int *tree,int index,int s,int e)
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
    build_tree(arr,tree,2*index,s,mid);
    build_tree(arr,tree,2*index+1,mid+1,e);
    int left_tree=tree[2*index];
    int right_tree=tree[2*index+1];
    tree[index]=min(left_tree,right_tree);

}
int query(int *tree,int index,int s,int e,int qs,int qe)
{
    //3 case
    //1.No any overlap.
    if(qs>e||qe<s)return INT_MAX;
    //2.complete overlap.
    if(s>=qs&&e<=qe)return tree[index];
    //3.partially overlap.
    int mid=(s+e)/2;
    int left_ans=query(tree,index*2,s,mid,qs,qe);
    int right_ans=query(tree,index*2+1,mid+1,e,qs,qe);
    return min(left_ans,right_ans);

}
void update_node(int *tree,int index,int s,int e,int i,int value)
{
    //1.no overlap
    if(i<s||i>e)return;
    //2.reach to the leaf node.
    if(s==e){
            tree[index]=value;
            return;
    }
    //Recursive call to reach the leaf node.
    int mid=(s+e)/2;
    update_node(tree,index*2,s,mid,i,value);
    update_node(tree,index*2+1,mid+1,e,i,value);
    tree[index]=min(tree[index*2],tree[index*2+1]);
    return;
}
void range_update(int *tree,int index,int s,int e,int  rs,int re,int increment)
{
    //1.no overlap.
    if(re<s||rs>e)return;
    //2.leaf node between range;
    if(s==e){
            tree[index]+=increment;
            return;
    }
     int mid=(s+e)/2;
   range_update(tree,index*2,s,mid,rs,re,increment);
   range_update(tree,index*2+1,mid+1,e,rs,re,increment);
    tree[index]=min(tree[index*2],tree[index*2+1]);
    return;

}
int main()
{
    int arr[]={1,3,2,-2,4,5};
    int n=sizeof(arr)/sizeof(int);
    int *tree=new int [4*n+1];
    int index=1;
    int s=0;
    int e=n-1;
    build_tree(arr,tree,index,s, e);
   cout<< query(tree, index, s, e, 0, 5)<<endl;
    update_node(tree, index, s, e, 0, 3);
    cout<< query(tree, index, s, e, 0, 2)<<endl;
    update_node(tree, index, s, e, 3, 10);
    cout<< query(tree, index, s, e, 3, 5)<<endl;
     range_update(tree,index,s,e,0,5,2);
    cout<< query(tree, index, s, e, 0, 5)<<endl;
     //rangeupdate(tree,index,s,e,rs,re,increment);
    //cout<< query(tree, index, s, e, qs, qe)<<endl;

    return 0;
}

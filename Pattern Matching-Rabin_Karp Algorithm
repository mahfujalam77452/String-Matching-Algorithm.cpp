#include<bits/stdc++.h>
using namespace std;
void search(char pat[],char txt[]){
    int n=strlen(txt);
    int m=strlen(pat);
    const int q=INT_MAX;//As a prime number
    int i,j;
    int d=256;//the number of diff. character for input.
    int p=0;//for calculating the hash value of pattern.
    int t=0;//for calculating the hash value of text;
    int h=1;//for calculating pow(d,m-1);
    for(int i=0;i<m-1;i++)h=(h*d)%q;
    for(int i=0;i<m;i++){
        p=(p*d+pat[i])%q;
        t=(t*d+txt[i])%q;//Thing we calculating the hash value with reverse order.
    }
    for(int i=0;i<=(n-m);i++){
        if(p==t){
            for(j=0;j<m;j++){
                if(txt[i+j]!=pat[j])break;
            }
            if(j==m)cout<<"We found at :"<<i+1<<endl;
        }
        if(i<n-m){
            t=((t-h*txt[i])*d+txt[i+m])%q;
            if(t<0)t+=q;//we can some how get negative value;
        }
    }
}

int main()
{
    char txt[] = "GEEKS FOR GEEKS";
	char pat[] = "GEEK";
	search(pat, txt);
	return 0;
}
  

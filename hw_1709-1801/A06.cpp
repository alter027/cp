#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(void){
    int T,n,flo,pa,num[10050],ans,i,j,k;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&n);
        pa=0;ans=0;
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);
        sort(num,num+n);
        for(i=0;i<n;i++){
            if(num[i]-pa<2);
            else{
                ans++;
                pa=num[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

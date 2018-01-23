#include<bits/stdc++.h>
using namespace std;
const int maxn=50001;
struct node{
    double  x,y;
}st[maxn],num[maxn];
int n,k,e;
double multi(node p1,node p2,node p3){
    return (p1.x-p3.x)*(p2.y-p3.y)-(p2.x-p3.x)*(p1.y-p3.y);
 }
void rotating_calipers(void){
    e=n;
    int q=1;
    double ans=0;
    st[e]=st[0];
    for(int i=0; i<e; i++){
        q=1;
        for(int p=i+1; p<e; p++){
            while(multi(st[i],st[q+1],st[p])>multi(st[i],st[q],st[p]))
                q=(q+1)%e;
            ans=max(ans,multi(st[i],st[q],st[p]));
        }
    }
    ans/=2;
    printf("%.15lf\n",ans);
 }
int main(void){
    int T;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%lf %lf",&st[i].x,&st[i].y);
        rotating_calipers();
    }
    return 0;
 }
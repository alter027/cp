#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
char map[123][123];
char v[123];
int num;
void DFS(int now){
    int i;
    for(i=1;i<=n;++i){
        if(!v[i] && map[now][i]){
            ++num;
            v[i] = 1;
            DFS(i);
        }
    }
}
int main(){
    int i,j;
    while(scanf("%d",&n)!=EOF && n){
        memset(map,0,sizeof(map));
        while(scanf("%d",&i)!=EOF && i){
            while(scanf("%d",&j)!=EOF &&j){
                map[i][j] = 1;
            }
        }
        scanf("%d",&j);
        while(j--){
            memset(v,0,sizeof(v));
            num =  0;
            scanf("%d",&i);
            DFS(i);
            printf("%d",n-num);
            for(i=1;i<=n;++i){
                if(!v[i])printf(" %d",i);
            }
            puts("");
        }
    }

    return 0;
}
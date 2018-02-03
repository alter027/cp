#include<bits/stdc++.h>
using namespace std;

double ans;
int N;
double A[100];

void init(void){
	scanf("%d",&N);
	double input;
	for(int i=0;i<N*2;i++)
		scanf("%lf",&A[i]);
	ans=1;
 }
void tri(void){
	int i;
	sort(A,A+N*2);
	for(i=0;i<N;i++){
//		printf("%lf %lf ",A[i],A[N*2-1-i]);
		ans*=(1-(A[i]*A[N*2-1-i]));
//		printf("%lf\n",ans);
	}
 }
int main(void){
	int T,Case=1;
	int N;
	scanf("%d",&T);
	while(T-->0){
		init();
		tri();
		printf("Case #%d: %lf\n",Case++,ans);
	}
	return 0;
}
#include<bits/stdc++.h>
void do_matrix(unsigned long long p,int length);
void lin_fib(char* n,int length);
struct matrix12 cross(struct matrix12 ans,struct matrix22 A);
struct matrix22 cross_22(struct matrix22 a,struct matrix22 b);
unsigned long long bignum(unsigned long long a,unsigned long long b);
using namespace std;
struct matrix22{
	unsigned long long r11,r12,r22;
}fib[110][4];
struct matrix12{
	unsigned long long num1,num2;
}num;
unsigned long long p;
int main(void){
	int ncase,length;char n[150];
	cin>>ncase;
	while(ncase-->0){
		num.num1=0;num.num2=1;
		cin>>n>>p;
		length=strlen(n);
		do_matrix(p,length);
		lin_fib(n,length);
		printf("%llu\n",num.num1%p);
	}
	return 0;
}
void do_matrix(unsigned long long p,int length){
	int i=0,j;
	fib[i][0].r11=0;
	fib[i][0].r12=1;
	fib[i][0].r22=1;
//	printf("i=0\n");
	for(j=1;j<4;j++){
		fib[i][j]=cross_22(fib[i][j-1],fib[i][j-1]);
	}
/*	for(j=0;j<4;j++){
		printf("j=%d %llu %llu %llu\n",j,fib[i][j].r11,fib[i][j].r12,fib[i][j].r22);
	}
*/	for(i=1;i<length;i++){
//		printf("i=%d\n",i);
		fib[i][0]=cross_22(fib[i-1][1],fib[i-1][3]);
		for(j=1;j<4;j++){
			fib[i][j]=cross_22(fib[i][j-1],fib[i][j-1]);
		}
/*		for(j=0;j<4;j++){
			printf("j=%d %llu %llu %llu\n",j,fib[i][j].r11,fib[i][j].r12,fib[i][j].r22);
		}
*/	}
}
void lin_fib(char* n,int length){
	int i;
	for(i=0;i<length;i++){
		if(n[i]=='1'){
			num=cross(num,fib[length-1-i][0]);
		}
		else if(n[i]=='2'){
			num=cross(num,fib[length-1-i][1]);
		}
		else if(n[i]=='3'){
			num=cross(num,fib[length-1-i][0]);
			num=cross(num,fib[length-1-i][1]);
		}
		else if(n[i]=='4'){
			num=cross(num,fib[length-1-i][2]);
		}
		else if(n[i]=='5'){
			num=cross(num,fib[length-1-i][0]);
			num=cross(num,fib[length-1-i][2]);
		}
		else if(n[i]=='6'){
			num=cross(num,fib[length-1-i][1]);
			num=cross(num,fib[length-1-i][2]);
		}
		else if(n[i]=='7'){
			num=cross(num,fib[length-1-i][0]);
			num=cross(num,fib[length-1-i][1]);
			num=cross(num,fib[length-1-i][2]);
		}
		else if(n[i]=='8'){
			num=cross(num,fib[length-1-i][3]);
		}
		else if(n[i]=='9'){
			num=cross(num,fib[length-1-i][0]);
			num=cross(num,fib[length-1-i][3]);
		}
	}
}
struct matrix12 cross(struct matrix12 ans,struct matrix22 A){
	unsigned long long a,b;
	a=ans.num1;b=ans.num2;
	ans.num1=bignum(A.r11,a)+bignum(A.r12,b);
	ans.num2=bignum(A.r12,a)+bignum(A.r22,b);
	ans.num1%=p;
	ans.num2%=p;
	return ans;
}
struct matrix22 cross_22(struct matrix22 a,struct matrix22 b){
	struct matrix22 ans;
	ans.r11=bignum(a.r11,b.r11)+bignum(a.r12,b.r12);
	if(ans.r11>=p)
		ans.r11-=p;
	ans.r12=bignum(a.r11,b.r12)+bignum(a.r12,b.r22);
	if(ans.r12>=p)
		ans.r12-=p;
	ans.r22=bignum(a.r12,b.r12)+bignum(a.r22,b.r22);
	if(ans.r22>=p)
		ans.r22-=p;
	return ans;
}
unsigned long long bignum(unsigned long long a,unsigned long long b){
	__int128 k;
	k=((__int128)a*(__int128)b)%p;
	return k;
	
/*	if(a<=1000000000L&&b<=1000000000L){
		return a*b%p;
	}
	else{
		if(b<=2)
			return a*b;
		if((b&1)==0){
			unsigned long long ret=bignum(a,b>>1);
			ret+=ret;
			if(ret>p)
				return ret-p;
			else
				return ret;
		}
		else{
			unsigned long long ret=bignum(a,b>>1);
			ret+=ret;
			ret+=a;
			if(ret>p){
				ret-=p;
				if(ret>p)
					return ret-p;
				else
					return ret;
			}
			else
				return ret;
		}
	}*/
}

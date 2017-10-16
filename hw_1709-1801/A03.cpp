#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
int T,n;
long double c,l[20],lg,pi;
long double HL(long double a,long double b,long double c){
	long double s=(a+b+c)/2;
	a=s-a;b=s-b;c=s-c;
	long double ans=sqrt(s*a*b*c);
	return ans;
}
long double f1(long double r){
	int i;
	long double ans=0;
	for(i=0;i<n;i++){
		ans+=2*asin(l[i]/(2*r));
	}
	return ans-2*pi;
}
long double findf1(){
	long double ans=1024,pick=512,tri;
	while(pick>10e-15){
		tri=ans-pick;
		tri=f1(tri);
		if(tri<0)
			ans=ans-pick;
		pick/=2;
	}
	return ans;
}
long double f2(long double r){
	int i;
	long double ans=0;
	for(i=0;i<n;i++){
		ans+=2*asin(l[i]/(2*r));
	}
	ans-=4*asin(lg/(2*r));
	return ans;
}
long double findf2(){
	long double ans=1024,pick=512,tri;
	while(pick>10e-15){
		tri=ans-pick;
		if(tri<lg/2){
			pick/=2;
			continue;
		}
		tri=f2(tri);
		if(tri>0)
			ans=ans-pick;
		pick/=2;
	}
	return ans;
}
int main(void){
	int i,j,k;
	scanf("%d",&T);
	pi=asin(1)*2;
	while(T-->0){
		lg=0;
		cin>>c>>n;
		for(i=0;i<n;i++){
			cin>>l[i];
			if(l[i]>lg)
				lg=l[i];
		}
		long double radius;
		long double k=f1(lg/2);
		long double ans=0;
		if(fabs(k)<10e-15){
			radius=lg/2;
			ans=c/(2*pi);ans=ans*ans*pi;
			for(i=0;i<n;i++){
				if(l[i]!=lg){
					ans-=HL(l[i],radius,radius);
				}
			}
		}
		else if(k>0){
			radius=findf1();
			ans=c/(2*pi);ans=ans*ans*pi;
			for(i=0;i<n;i++)
				ans-=HL(l[i],radius,radius);
		}
		else{
			radius=findf2();
			ans=c/(2*pi);ans=ans*ans*pi;
			for(i=0;i<n;i++)
				ans-=HL(l[i],radius,radius);
			ans+=2*HL(lg,radius,radius);
		}
		cout<<std::setprecision(20)<<ans<<endl;
	}
	return 0;
}

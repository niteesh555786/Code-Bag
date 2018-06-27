#include <iostream>
using namespace std;

void egyptian_frac(int n,int d){
	if(d==0 || n==0)
		return;
	if(n%d==0){
		cout<<n/d;
		return;
	}
	if(d%n==0){
		cout<<"1/"<<d/n;
		return;
	}
	if(n>d){
		cout<<n/d<<"+";
		egyptian_frac(n%d,d);
		return;
	}

	//if d>n
	int nr=d/n +1;
	cout<<"1/"<<n<<"+";
	egyptian_frac(n*nr-d,d*nr);
}

int main(){
	int n=6, d=14;

	egyptian_frac(n,d);

	return 0;
}
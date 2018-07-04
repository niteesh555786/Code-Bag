#include <bits/stdc++.h>
using namespace std;

struct Box
{
	int l,b,h;
};

int compare(const void *a,const void *b){
	return ( (*(Box *)a).l * (*(Box *)a).b)-( (*(Box *)b).l * (*(Box *)b).b );
}

int boxStack(Box arr[],int n){
	Box rot[3*n];
	int idx=0;
	for(int i=0;i<n;i++){
		//rot1
		rot[idx].l=max(arr[i].l,arr[i].b);
		rot[idx].b=min(arr[i].l,arr[i].b);
		rot[idx].h=arr[i].h;
		idx++;
		
		//rot2
		rot[idx].l=max(arr[i].h,arr[i].b);
		rot[idx].b=min(arr[i].h,arr[i].b);
		rot[idx].h=arr[i].l;
		idx++;

		//rot3
		rot[idx].l=max(arr[i].l,arr[i].h);
		rot[idx].b=min(arr[i].l,arr[i].h);
		rot[idx].h=arr[i].b;
		idx++;
	}
	n=3*n;
	qsort(rot,n,sizeof(rot[0]),compare);

	int msh[n];
	for(int i=0;i<n;i++)
		msh[i]=rot[i].h;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(rot[i].l <rot[j].l && rot[i].b < rot[j].b && msh[i]<msh[j]+rot[i].h)
				msh[i]=msh[j]+rot[i].h;
		}
	}

	int maxVal=-1;
	for(int i=0;i<n;i++)
		maxVal=max(maxVal,msh[i]);

	return maxVal;
}

int main(){
	Box arr[]={ {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
	int n=sizeof(arr)/sizeof(arr[0]);

	cout<< boxStack(arr,n);

	return 0;
}
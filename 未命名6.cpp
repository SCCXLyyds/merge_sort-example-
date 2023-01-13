#include <iostream>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int a[N],tem[N],n;
int merge_sort( int a[],int x,int y)
{
	if(x>=y) return 0;
	int mid=x+y>>1;
	LL res=merge_sort(a,x,mid) + merge_sort(a,mid+1,y);
	int l=x,j=mid+1,p=0;
	while(l<=mid && j<=y)
	{
		if(a[l]<=a[j])  tem[p++]=a[l++];
		else {
			res+=mid-l+1;
			tem[p++]=a[j++];
		}
	}
	while(l<=mid)
	{
		tem[p++]=a[l++];
	}
	while(j<=y){
	    tem[p++]=a[j++];
	}
	return res;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<merge_sort(a,0,n-1)<<endl;
}

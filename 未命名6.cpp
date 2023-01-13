逆序对的数量
给定一个长度为 n 的整数数列，请你计算数列中的逆序对的数量。

逆序对的定义如下：对于数列的第 i 个和第 j 个元素，如果满足 i<j 且 a[i]>a[j]，则其为一个逆序对；否则不是。

输入格式
第一行包含整数 n，表示数列的长度。

第二行包含 n 个整数，表示整个数列。

输出格式
输出一个整数，表示逆序对的个数。

数据范围
1≤n≤100000，
数列中的元素的取值范围 [1,109]。
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

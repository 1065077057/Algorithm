/*
归并排序，简单地讲就是利用了分治的思想，利用递归将整个数组疯狂分成两部分
直到分成1个数是一个数组，然后在回溯的时候拼到一个数组中，从而完成排序。
关于时间复杂度，是O(nlongn)。我对n个元素进行排序的时候是：
    T(n) = 2*T(n/2) + a*n
    	 = 2*(2*T(n/4) + a*n/2) + a*n
    	 ...
    	 = 2^k * T(n/2^k) + k*a*n
    可知时间复杂度为O(nlongn)
具体的解析在注释中。
归并排序也是用时间换空间的算法典型，多开了一倍的空间，但是显著降低了时间
复杂度。

归并排序的复杂度问题，可以把归并排序分成2个部分：
    1.疯狂利用mid将数组分隔成2部分
    2.单独的2个部分最终利用2个指针线性对比添加到新的数组中
那么可以知道，第一部分类似于二分，最终的时间复杂度为O(logn)，而第二部分时间复杂度是O(n)，因为是线性比较。
*/

#include<iostream>
#define MAX 10

using namespace std;

// 测试用例如下，没有写随机数，b就是
int a[MAX] = {13,27,19,2,8,12,2,8,30,89};
int b[MAX];

/*
利用temp数组合并之前分开的2部分数组，这两部分已经排好序了，假设是：
	p1: 1 8 9 10 11
	p2: 2 4 6 7 233
利用新的数组就是对p1与p2分别设置指针，看谁大，谁就进入新的数组，同
时指针前移，一直循环。
*/
void merge(int a[],int s,int m,int e,int temp[]){
	int pb = 0;
	int p1 = s;
	int p2 = m+1;
	// 第一部分循环，直到p1或p2有一个全部放在数组中
	while(p1 <= m && p2 <= e){
		if(a[p1] < a[p2]){
			temp[pb++] = a[p1++];
		}else{
			temp[pb++] = a[p2++];
		}
	}
	// 第二部分循环，怕有多的数据没有放在数组，那么一定是最大的几个了，直接放
	while(p1 <= m){
		temp[pb++] = a[p1++];
	}
	while(p2 <= e){
		temp[pb++] = a[p2++];
	}
	for(int i = 0;i < e-s+1;i++){
		a[s+i] = temp[i];
	}

}

// 分治的思想，a是原数组，s与e表示排序的范围，即a[s]-a[e]
void mergeSort(int a[],int s,int e,int temp[]){
	if(s < e){
		int m = s + (e-s)/2; // 找出中值
		// 分成2部分进入递归
		mergeSort(a,s,m,temp);
		mergeSort(a,m+1,e,temp);
		// 回溯的时候将已经排序完成的2部分进行合并
		merge(a,s,m,e,temp);
	}
}

int main(){
	int size = MAX;
	mergeSort(a,0,size-1,b);
	for(int i = 0;i < size;i++){
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

/*************************************************************************
 > File Name: mergeSort.cpp
 > Author: Leafxu
 > Created Time: 2019年11月14日 18:01:44
 ************************************************************************/

#include<iostream>
using namespace std;

int min(int a, int b) { return a<b?a:b;}
template<typename T> void displayArray(T arr[], int len);

template <typename T>
T* mergeSort(T arr[], int len) 
{
	int i=0, start1=0, start2=0, end1=0, end2=0, pos=0, step=1;
	T* a = arr;
	T* b = new T[len]();
	if (len<=0 || arr==NULL) return NULL;
	
	for (step; step<len; step += step) 
	{
		pos = 0;
		for (i=0; i<len; i+=step*2) 
		{
			start1 = i;
			start2 = end1 = min(len, i+step);
			end2 = min(len, i+step*2);

			while (start1<end1 && start2<end2)
				b[pos++] = a[start1]>a[start2] ? a[start1++] : a[start2++];
			while (start1<end1)
				b[pos++] = a[start1++];
			while (start2<end2)
				b[pos++] = a[start2++];
		}
		displayArray(b, len);
		// iteration
		T* temp = a;
		a = b;
		b = temp;
	}
	return a;
}
/*
template <typename T>
T* mergeSort(T arr[], T reg[], int start, int end)
{
	int mid, len, pos=start;
	if (start > end) return NULL; // 结束条件
	len = end - start + 1;
	mid = (start+end)/2;
	mergeSort(arr, reg, start, mid);	// 左半区	[start, mid]
	mergeSort(arr, reg, mid+1, end);	// 右半区	[mid+1, end)
	// 处理当前
	while (start<len && mid<len) 
		reg[pos++] = arr[start]<arr[mid] ? arr[start++] : arr[mid++];
	while (start<len)
		reg[pos++] = arr[start++];
	while (mid<len)
		reg[pos++] = arr[mid++];
}*/
/*
template <typename T>
void mergeSort(T arr[], T reg[], int start, int end)
{
	int len, mid, pos;
	if (start>=end) return;
	len = end - start;
	mid = (start + end)/2;
	std::cout<<start<<" "<<mid<<" "<<end<<endl;
	mergeSort(arr, reg, start, mid);
	mergeSort(arr, reg, mid, end);
	pos = start;
	while (start<len && mid<len)
		reg[pos++] = arr[start]<arr[mid] ? arr[start++] : arr[mid++];
	while (start<len)
		reg[pos++] = arr[start++];
	while (mid<len)
		reg[pos++] = arr[mid++];
	displayArray(reg, 9);
}*/


template <typename T>
void displayArray(T arr[], int len) {
	int i = 0;
	for (i=0; i<len; i++) {
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

int main(int argc, char** agrv) 
{
	int i = 0;
	int arr[] = {5,7,3,4,1, 10, 12, 9, 0};
	int *result = NULL;
	int *result1 = new int[9]();
	displayArray(arr, 9);
	//result = mergeSort(arr, 9);
	mergeSort(arr, result1, 0 , 9);
	displayArray(result1, 9);
	return 0;
}

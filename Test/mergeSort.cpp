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
	
	for (step; step<len; step += step) // 迭代的步长
	{
		pos = 0;
		for (i=0; i<len; i+=step*2)  // 层次比较
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
		// iteration  比较主体的迭代
		T* temp = a;
		a = b;
		b = temp;
	}
	displayArray(a, len);
	return a;
}

template <typename T>
void mergeSort(T arr[], T reg[], int begin, int len)
{
	int start1, start2, end1, end2, pos, step;
	if (begin+1>=len) return;
	start1 = begin;
	//start2 = end1 = min(len, (begin+len) / 2);
	start2 = end1 = (begin+len) / 2;
	end2 = len;
	// 处理区间保持一致 [x, y)
	mergeSort(arr, reg, start1, end1); // [start1, end1)
	mergeSort(arr, reg, start2, end2); // [start2, end2)
	pos = start1;
	while (start1<end1 && start2<end2)
		reg[pos++] = arr[start1]<arr[start2] ? arr[start1++] : arr[start2++];
	while (start1 < end1)
		reg[pos++] = arr[start1++];
	while (start2 < end2)
		reg[pos++] = arr[start2++];

	while(begin<len) {	// 递归主体的同步
		arr[begin] = reg[begin];
		begin++;
	}
}

template <typename T>
void displayArray(T arr[], int len) {
	int i = 0;
	for (i=0; i<len; i++) {
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

void testMergeSort()
{
	int arr[] = {5,7,3,4,1, 10, 12, 9, 2};
	mergeSort(arr, 9);
}

void testMergeSort1()
{
	int arr[] = {5,7,3,4,1, 10, 12, 9};
	int *result = new int[8]();
	mergeSort(arr, result, 0 , 8);
	displayArray(result, 8);
}
int main(int argc, char** agrv) 
{
	testMergeSort();
	testMergeSort1();
	return 0;
}

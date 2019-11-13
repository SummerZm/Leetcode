/*************************************************************************
 > File Name: initArrayDemo.cpp
 > Author: Leafxu
 > Created Time: 2019年11月13日 11:24:14
 ************************************************************************/
 
#include <iostream>
#include <string>
#include <vector>

void vectorArray()
{
	std::string s = "xwhzm";
	int n = s.length();
	int i=0, j=0;

	// create 2 dimensional array.
	std::vector<std::vector<int>> arr(n, std::vector<int>(n));

	// Set all -1
	for (i=0; i<n; i++) 
		for (j=0; j<n; j++)
			arr[i][j] = 1;

	// Set diagonal line
	for (i=0; i<n; i++)
		arr[i][i] = 0;

	// Set up triangle
	for (i=0; i<n; i++) 
		for (j=i+1; j<n; j++)
			arr[i][j] = 2;

	// Print
	for (i=0; i<n; i++)  {
		for (j=0; j<n; j++) {
			std::cout<<arr[i][j]<<'\t';
		}
		std::cout<<std::endl;
	}

	//std::cout<<s.length()<<std::endl;
}

void heapArrayConstN() 
{
	std::string s = "xwhzm";
	int n = s.length();
	int i=0, j=0;
	int (*arr)[5] = new int[5][5];	

	// Set all -1
	for (i=0; i<n; i++) 
		for (j=0; j<n; j++)
			arr[i][j] = 1;

	// Set diagonal line
	for (i=0; i<n; i++)
		arr[i][i] = 0;

	// Set up triangle
	for (i=0; i<n; i++) 
		for (j=i+1; j<n; j++)
			arr[i][j] = 2;

	// Print
	for (i=0; i<n; i++)  {
		for (j=0; j<n; j++) {
			std::cout<<arr[i][j]<<'\t';
		}
		std::cout<<std::endl;
	}
}

void heapArray()
{
	std::string s = "xwhzm";
	int i=0, j=0;
	int n = s.length();
	int **arr = new int*[n]();
	for (i=0; i<n; i++) 
		arr[i] = new int[n]();
	
	// Set all -1
	for (i=0; i<n; i++) 
		for (j=0; j<n; j++)
			arr[i][j] = 1;

	// Set diagonal line
	for (i=0; i<n; i++)
		arr[i][i] = 0;

	// Set up triangle
	for (i=0; i<n; i++) 
		for (j=i+1; j<n; j++)
			arr[i][j] = 2;

	// Print
	for (i=0; i<n; i++)  {
		for (j=0; j<n; j++) {
			std::cout<<arr[i][j]<<'\t';
		}
		std::cout<<std::endl;
	}
}


int main(int argc, char** argv)
{
	//vectorArray();
	heapArray();
	return 0;
}


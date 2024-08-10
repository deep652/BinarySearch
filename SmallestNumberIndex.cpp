#include<iostream>

using namespace std;
//smallest number in the list
int findSmallestNumberIndexInRotatedArrayBS(int *arr, int left, int right)
{
	if(arr[left] <= arr[right])
		return -1;
	while(left<right)
	{
		int mid = left + (right - mid) / 2;

		if(arr[mid] > arr[right])
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}
int binarySearch(int *arr, int left, int right, int ele)
{
	while(left <= right)
	{
		int mid = left + (right - left)/2;
		if(arr[mid] == ele)
		{
			return mid;
		}
		if(ele < arr[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}

	}	

	return -1;
}

int main()
{
	int arr[] = { 5, 6, 7, 9, 1, 2, 3 };
	int arrS[] = {11, 14, 23, 26, 31, 39, 45};

	cout<< "smallest number index is " << findSmallestNumberIndexInRotatedArrayBS(arr, 0, 6)<<endl;
	cout<< "index of the number found in the array is "<< binarySearch(arrS , 0, 6, 23);
	return 0;

}

/*
Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. 
( Expected: Single pass-O(N) and constant space)
*/


#include <bits/stdc++.h>
using namespace std;

// Approach 1 :

class Solution{
	public:
	void sort012(int arr[],int n){
		int count_0,count_1,count_2 = 0;
		for(int i=0;i<n;i++){
			if(arr[i] == 0){
				count_0++;
			}else if(arr[i] == 1){
				count_1++;
			}else{
				count_2++;
			}
		}
		
		for(int i=0;i<n;i++){
			if(count_0 != 0){
				arr[i] = 0;
				count_0--;
			}else if(count_1 != 0){
				arr[i] = 1;
				count_1--;
			}else{
				arr[i] = 2;
				count_2--;
			}
		}
		
		for(int i=0;i<n;i++){
			cout << arr[i];
		}
	}
};

int main(){
	Solution obj;
	int arr[] = {0,2,1,2,0,0,1,2,1,0,1,0,0,0};
	obj.sort012(arr,14);
	return 0;
}

/*
Time Complexity - O(N) + O(N) = O(N)
	Two loops are being used
Space Complexity - O(1)
	No extra space is being used
*/

// Sorting approach :

class Solution{
	public:
	void sort012(int arr[],int n){
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i-1;j++){
				if(arr[j] > arr[j+1]){
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		
		for(int i=0;i<n;i++){
			cout << arr[i];
		}
	}
};

int main(){
	Solution obj;
	int arr[] = {0,2,1,2,0,0,1,2,1,0,1,0,0,0};
	obj.sort012(arr,14);
	return 0;
}

/*
Time Complexity - O(N^2)
	Nested loops are being used
Space Complexity - O(1)
	No extra space is being used
*/

// Dutch National Flag algo :

class Solution{
	public:
	void sort012(int arr[],int n){
		int low = 0,mid = 0,high = n-1;
		
		while(mid <= high){
			if(arr[mid] == 0){
				swap(arr[mid],arr[low]);
				low++;
				mid++;
			}else if(arr[mid] == 1){
				mid++;
			}else{
				swap(arr[mid],arr[high]);
				high--;
			}
		}
		
		for(int i=0;i<n;i++){
			cout << arr[i];
		}
	}
};

int main(){
	Solution obj;
	int arr[] = {0,2,1,2,0,0,1,2,1,0,1,0,0,0};
	obj.sort012(arr,14);
	return 0;
}

/*
Time Complexity - O(N)
	While loop is being used
Space Complexity - O(1)
	No extra space is being used
*/


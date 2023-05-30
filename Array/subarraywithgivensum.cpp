/*
Problem Statement : Given an array and a sum k, generate the subarray whose elements sum to k.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force

class Solution{
	public:
		void subarraySum(int arr[],int n,int k){
			
			for(int i=0;i<n;i++){
				int sum = 0;
				for(int j=i;j<n;j++){
					sum+=arr[j];
					if(sum == k){
						for(int p=i;p<=j;p++){
							cout << arr[p];
						}
					}
				}
			}
		}
};


int main(){
	Solution obj;
	int arr[] = {1,7,3,5};
	int size = sizeof(arr)/sizeof(int);
	int k = 10;
	obj.subarraySum(arr,size,k);
	return 0;
}

/*
Time Complexity - O(N^2) + O(N)
	Two nested loops are being used + one more loop for printing the elements
Space Complexity - O(1)
	No extra space is being used
*/

// Better Approach :

/*
* Take two pointers and place it in the starting index
* Iterate "end" pointer till it crosses the target sum
* Once it does, increment the start pointer and make the end pointer point to the same index as start
*/


class Solution{
	public:
		void subarraySum(int arr[],int n,int k){
			int start,end = 0;
			int sum = 0;
			while(start < n && end < n){
				sum+=arr[end];
				if(sum > k){
					start++;
					end = start;
					sum = 0;
					sum+=arr[end];
				}
				end++;
				if(sum == k){
					break;
				}
			}
			for(int i=start;i<end;i++){
				cout << arr[i];
			}
		}
};


int main(){
	Solution obj;
	int arr[] = {2,1,3,4,5,6};
	int size = sizeof(arr)/sizeof(int);
	int k = 10;
	obj.subarraySum(arr,size,k);
	return 0;
}

/*
Time Complexity - O(N)
	While loop for finding the subarray,For loop to print the elements;
Space Complexity - O(1)
	No extra space is being used 
*/

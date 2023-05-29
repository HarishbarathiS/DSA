/*
Problem Statement : Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and returns its sum and print the subarray.
*/


#include <bits/stdc++.h>
#include <climits>
using namespace std;

// Approach 1:

class Solution{
	public:
		tuple<int,int,int> maxSum(int arr[],int n){
			int sum = 0;
			int fmax = INT_MIN;
			int start,end = 0;

			for(int i=0;i<n;i++){
				for(int j=i;j<n;j++){
					sum+=arr[j];
					if(sum > fmax){
						fmax = sum;
						start = i;
						end = j;
					}
				}
				sum = 0;
			}
			return make_tuple(fmax,start,end);
		}
};
	

int main(){
	Solution obj;
	int arr[] = {-1,-2,-3,-4};
	int size = sizeof(arr)/sizeof(int);
	tuple<int,int,int> res = obj.maxSum(arr,size);
	int target = get<0>(res);
	cout << "sum : " << target << endl;
	int i = get<1>(res);
	int j = get<2>(res);
	for(int k=i;k<=j;k++){
		cout << arr[k] << endl;
	}
	return 0;
}

/*
Time Complexity - O(N^2)
	Two nested loops are being used
Space Complexity - O(1)
	No extra space is being used
*/

// Kadane's algorithm : 

/*
Sub array with sum less than 0 intends to reduce our answer hence try to skip it, (i.e) whenever the
subarray sum goes less than 0, make the sum as 0 and move to the next iteration
*/

class Solution{
	public:
		tuple<int,int,int> maxSum(int arr[],int n){
			int sum = 0;
			int fmax = INT_MIN;
			int start,end = 0;
			int temp;
			for(int i=0;i<n;i++){
				
				if(sum == 0){
					temp = i;
				}
				sum+=arr[i];
				if(sum > fmax){
					fmax = sum;
					start = temp;
					end = i;
				}
				if(sum < 0){
					sum = 0;
				}
			}
			return make_tuple(fmax,start,end);
		}
};
	

int main(){
	Solution obj;
	int arr[] = {-1,-2,-3,-4};
	int size = sizeof(arr)/sizeof(int);
	tuple<int,int,int> res = obj.maxSum(arr,size);
	int target = get<0>(res);
	cout << "sum : " << target << endl;
	int i = get<1>(res);
	int j = get<2>(res);
	for(int k=i;k<=j;k++){
		cout << arr[k] << endl;
	}
	return 0;
}

/*
Time Complexity - O(N)
	One loop is being used
Space Complexity - O(1)
	No extra space is being used
*/

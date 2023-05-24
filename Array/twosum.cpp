/*
Problem Statement: Given an array of integers arr[] and an integer target.
1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force : 

class Solution{
	public:
	void twoSum(int arr[],int n,int k,int* ptr){
		*ptr = 0;
		*(ptr+1) = -1;
		*(ptr+2)= -1;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if((arr[i] + arr[j]) == k){
					*ptr = 1;
					*(ptr+1) = i;
					*(ptr+2) = j;
					break;
				}
			}
		}
	}
};

int main(){
	Solution obj;
	int arr[] = {2,6,5,8,11};
	int* ptr = new int[3];
	int size = sizeof(arr)/sizeof(int);
	obj.twoSum(arr,size,15,ptr);
	if(*ptr){
		cout << "Yes" << endl;
		cout << "Index 1 : " << *(ptr+1) << endl;
		cout << "Index 2 : " << *(ptr+2) << endl;
 	}else{
 		cout << "No" << endl;
 		cout << "Index 1 : " << *(ptr+1) << endl;
 		cout << "Index 2 : " << *(ptr+2);
	 }
	return 0;
}

/* 
Time Complexity - O(N^2)
	Two nested loops are being used
Space Complexity - O(1)
	No extra space is used
*/

// Better Approach (Hash map) : 

class Solution{
	public:
		void twoSum(int arr[],int n,int k,int* ptr){
			map<int,int> mpp;
			*ptr = 0;
			*(ptr+1) = -1;
			*(ptr+2)= -1;
			for(int i=0;i<n;i++){
				int num = arr[i];
				int rem = k - num;
				if(mpp.find(rem) != mpp.end()){
					*ptr = 1;
					*(ptr+1) = mpp[rem];
					*(ptr+2) = i;
				}
				mpp[num] = i;
			}
		}
};

int main(){
	Solution obj;
	int arr[] = {2,6,5,8,11};
	int* ptr = new int[3];
	int size = sizeof(arr)/sizeof(int);
	obj.twoSum(arr,size,14,ptr);
	if(*ptr){
		cout << "Yes" << endl;
		cout << "Index 1 : " << *(ptr+1) << endl;
		cout << "Index 2 : " << *(ptr+2) << endl;
 	}else{
 		cout << "No" << endl;
 		cout << "Index 1 : " << *(ptr+1) << endl;
 		cout << "Index 2 : " << *(ptr+2);
	 }
	return 0;
}

/*
Time Complexity - O(N)
	Loop runs N times and search an element usually takes O(1) to search for an element
	Worst case -> * unordered_map takes O(N) to search for an element(hash table),hence running 
				  for O(N^2) times.
				  * map takes log N to search for an element (binary search), hence running till
				  O(N*logN)
Space Complexity - O(N)
	map data structure
*/

// Not an Optimised Approach :|

class Solution{
	public:
		vector<int> twoSum(int arr[],int n,int k){
			int temp[n];
			
			for(int i=0;i<n;i++){
				temp[i] = arr[i];
			}
			
			sort(arr,arr+n);
			int flag = 0;
			int i = 0; // left index
			int j = n-1; // right index
			
			while(i < j){
				int sum = arr[i] + arr[j];
				if(sum > k){
					j--;
				}else if(sum < k){
					i++;
				}else{
					flag = 1;
					break;
				}
			}
			int idx1,idx2 = -1;
			for(int k=0;k<n;k++){
				if(temp[k] == arr[i]){
					idx1 = k;
				}
				if(temp[k] == arr[j]){
					idx2 = k;
				}
			}
			return {flag,idx1,idx2};
		}
};

int main(){
	Solution obj;
	int arr[] = {2,6,5,8,11};
	int size = sizeof(arr)/sizeof(int);
	vector<int> res = obj.twoSum(arr,size,16);
	if(res[0]){
		cout << "Yes" << endl;
		cout << "Index 1 : " << res[1] << endl;
		cout << "Index 2 : " << res[2] << endl;
 	}else{
 		cout << "No" << endl;
 		cout << "Index 1 : " << res[1] << endl;
 		cout << "Index 2 : " << res[2];
	 }
	return 0;
}

/*
Time Complexity - O(N*logN)
	Two for loops + while -> N+N+N = O(N)
	For sorting -> O(N*logN)
	hence, O(N) + O(N*logN)

Space Complexity - O(N)
	temp array is being used 
*/

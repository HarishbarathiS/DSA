#include <bits/stdc++.h>
using namespace std;

//Naive Approach:

class Solution{
	public:
		int LongestSubArray(int arr[],int n,int k){
			int sum = 0;
			int count = 0;
			for(int i=0;i<n;i++){
				sum = 0;
				for(int j=i;j<n;j++){
					sum+=arr[j];
					if(sum == k){
						count = max(count,j-i+1);
					}
				}
			return count;
		}
	}
};


int main(){
	Solution obj;
	int arr[] = {1,2,3,1,3,2,4,3,2};
	int size = sizeof(arr)/sizeof(int);
	int k = 19;
	int res = obj.LongestSubArray(arr,size,k);
	cout << res;
	return 0;
}

Time complexity : O(N^2)
	Two nested loops are being used,each running N times
Space complexity : O(1)
   	No extra space is being used


//Better Approach (Using Hashing):

class Solution{
	public:
		int LongestSubArray(int arr[],int n,int k){
			map<int,int> mpp;
			int sum = 0;
			int max_len = 0;
			for(int i=0;i<n;i++){
				sum+=arr[i];
				
				if(sum == k){
					max_len = max(max_len,i+1);
				}
				int rem = sum - k;
				
				if(mpp.find(rem) != mpp.end()){
					int count = i - mpp[rem];
					max_len = max(max_len,count);
				}
				
				if(mpp.find(sum) == mpp.end()){
					mpp[sum] = i; 
				}
			}
			return max_len;
		}
};


int main(){
	Solution obj;
	int arr[] = {1,2,3,1,3,2,4,3,2};
	int size = sizeof(arr)/sizeof(int);
	int k = 19;
	int res = obj.LongestSubArray(arr,size,k);
	cout << res;
	return 0;
}

Time Complexity :
	Ordered map - O(N*logN)
	Searching an element - logN (Binary search)
	For loop - O(N)
	
	Unordered map 
	O(N^2) (Worst case)
	Searching an element - O(N) (Uses hash map, take N times in case of collisions)
	O(N) (Best case)
	Searching an element - O(1)
	Hence O(N*logN) - Best case and O(N^2) - Worst case
	For loop - O(N)
	
Space Complexity - O(N)
	As map data structure is being used


//Optimal Approach : 
 
class Solution{
	public:
		int LongestSubArray(int arr[],int n,int k){
			int i,j = 0; // i -> left pointer , j-> right pointer
			int sum,max_len = 0;
			while(j<n){
				sum+=arr[j];
				while(i <= j && sum > k){
					sum-=arr[i];
					i++;
				}
				if(sum == k){
					max_len = max(max_len,j-i+1);
				}
				j++;
			}
			return max_len;
		}
};

int main(){
	Solution obj;
	int arr[] = {3,2,1};
	int size = sizeof(arr)/sizeof(int);
	int k = 5;
	int res = obj.LongestSubArray(arr,size,k);
	cout << res;
	return 0;
}

Time Complexity - O(N+N) or O(2N)
	Outer loop can run for n times and in the inner loop i can go up to j hence every time it doesn't
	run till n but can run n times in total
	
Space Complexity - O(1)
	No extra space is used


//O(N) Approach : 

class Solution{
	public:
		int LongestSubArray(int arr[],int n,int k){
			int i,j = 0;
			int sum = 0;
			int max_len = 0;
			while(j < n && i <= j){
				sum+=arr[j];
				if(sum < k){
					j++;
				}else if(sum == k){
					max_len = max(max_len,j-i+1);
					j++;
				}else{
					i++;
					j = i;
					sum = 0;
				}
			}
			return max_len;
		}
};


int main(){
	Solution obj;
	int arr[] = {1,4,3,3,5,5};
	int size = sizeof(arr)/sizeof(int);
	int k = 16;
	int res = obj.LongestSubArray(arr,size,k);
	cout << res;
	return 0;
}

Time Complexity - O(N);
	For loop is being used
Space Complexity - O(1)
	No extra space is used


/*
Problem Statement: Given an array, print all the elements which are leaders. 
A Leader is an element that is greater than all of the elements on its right side in the array.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
		void leader(int arr[],int n){
        vector<int> vec;
        int i = n-1;
        int j = n-2;
        while(j>=0){
            if(arr[j] >= arr[i]){
                vec.push_back(arr[j]);
                i = j;
                j--;
            }else{
                j--;
            }
        }
        reverse(vec.begin(),vec.end());
        vec.push_back(arr[n-1]);
        
        for(int i=0;i<vec.size();i++){
        	cout << vec[i] << " ";
		}
		}
};

int main(){
	Solution obj;
	int arr[] = {1,4,52,6,0};
	int n = sizeof(arr)/sizeof(int);
	obj.leader(arr,n);
	return 0;
}

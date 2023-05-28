/*
Problem Statement: Given an array of N integers, write a program to return an element that occurs 
more than N/2 times in the given array.You may consider that such an element always exists in the
array.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute force :

class Solution{
	public:
	int MajorityElement(vector<int> vec){
		int size = vec.size();
		for(int i=0;i<size;i++){
			int count  = 0;
			for(int j=0;j<size;j++){
				if(vec[i] == vec[j]){
					count++;
				}
			}
			if(count > size/2){
				return vec[i];
			}
		}	
	}
};


int main(){
	Solution obj;
	vector<int> nums;
	int value;
	for(int i=0;i<5;i++){
		cin >> value;
		nums.push_back(value);
	}
	int res = obj.MajorityElement(nums);
	cout << "Majority element : " <<  res;
	return 0;
}

/*
Time Complexity - O(N^2)
	Two nested loops are being used 
Space Complexity - O(1)
	No extra space is being used
*/

// Better Solution (Hashing)

class Solution{
	public:
	int MajorityElement(vector<int> vec){
		map <int,int> mpp;
		int size = vec.size();
		for(int i=0;i<size;i++){
			mpp[vec[i]]++;
		}
		for(auto i : mpp){
			if(i.second > size/2){
				return i.first;
			}
		}
	}
};


int main(){
	Solution obj;
	vector<int> nums;
	int value;
	for(int i=0;i<5;i++){
		cin >> value;
		nums.push_back(value);
	}
	int res = obj.MajorityElement(nums);
	cout << "Majority element : " <<  res;
	return 0;
}

/*
Time Complexity - O(N*logN)
	Insertion in map takes log N times, as we are dng it for N elements -> O(N*logN) 
Space Complexity  - O(N)
	Map data structure is being used
*/

//Optimal Approach :

class Solution{
	public:
	int MajorityElement(vector<int> vec){
		int count = 1;
		int element = vec[0];
		int size = vec.size();
		for(int i=0;i<size-1;i++){
			if(element == vec[i+1]){
				count++;
			}else{
				count--;
			}
			if(count == 0){
				element = vec[i+1];
				count = 1;
			}
		}
		return element;	
	}
};


int main(){
	Solution obj;
	vector<int> nums;
	int value;
	for(int i=0;i<16;i++){
		cin >> value;
		nums.push_back(value);
	}
	int res = obj.MajorityElement(nums);
	cout << "Majority element : " <<  res;
	return 0;
}

/*
Time Complexity  - O(N)
	One loop is being used
Space Complexity - O(1)
	No extra space is being used
*/

// Own approach :)

class Solution{
	public:
	int MajorityElement(vector<int> vec){
		int size = vec.size();
        sort(vec.begin(),vec.end());
        int max = 1; // to store previous element's count
        int fmax = 1; // to store current element's count
        int target = vec[0];
        for(int i=0;i<size-1;i++){
            if(vec[i] == vec[i+1]){
                fmax++;
            }else{
                if(fmax >= max){
                    target = vec[i];
                    max = fmax;
                }
                fmax = 1;
            }
        }
        if(fmax > max){
            target = vec[size-1];
        }
        return target;
}
};


int main(){
	Solution obj;
	vector<int> nums;
	int value;
	for(int i=0;i<5;i++){
		cin >> value;
		nums.push_back(value);
	}
	int res = obj.MajorityElement(nums);
	cout << "Majority element : " <<  res;
	return 0;
}

/*
Time Complexity - O(N*logN) + O(N) 
	Sort function takes O(N*logN) + For loop O(N)
Space Complexity - O(1)
	No extra space is being used
*/

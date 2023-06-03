/*
Problem statement : There’s an array ‘A’ of size ‘N’ with positive and negative elements 
(not necessarily equal). Without altering the relative order of positive and negative elements, 
you must return an array of alternately positive and negative values. The leftover elements 
should be placed at the very end in the same order as in array A.
*/

#include <bits/stdc++.h>
using namespace std;

// Own Approach :

class Solution{
	public:
		void rearrange(int arr[], int n) {
	    int * temp = new int[n];
	    int pos = 0;
	    int neg = 0;
	    
	    // count of positive and negative elements
	    
	    for(int i=0;i<n;i++){
	        if(arr[i] >= 0){
	            pos++;
	        }
			else if(arr[i] < 0){
	            neg++;
	        }
	    }
	      
		int start = neg; // number of negative values is stored as we are gonna change "neg"
	    int meh = 0; //  to store negative values from the starting index
	    int fos = neg; // to store positive values after all negative values are stored
	    for(int i=0;i<n;i++){
	        if(arr[i] < 0){
	            temp[meh] = arr[i];
	            meh++;
	        }
	        if(arr[i] >= 0){
	            temp[fos] = arr[i];
	            fos++;
	        }
	    }
	    
	    /* to store positive and negative elements alternatively, if any of them gets over, break the loop 
	       and store the left overs
	    */
	    
	    int neg_start = 0;
	    int pos_start = meh;
	    int i=0;
	    while(i < n){
	    		if(i%2 == 0){
	    			if(pos > 0){
	    			arr[i] = temp[pos_start];
	    			pos_start++;
	    			pos--;
				}else{
					break;
				}
			}
	    	if(i%2 == 1){
	    		if(neg > 0){
	    			arr[i] = temp[neg_start];
	    			neg_start++;
	    			neg--;
				}else{
					break;
				}
			}
			i++;	
		}
		
		// to store left overs
		
		if(neg != 0){
			while(neg > 0){
				arr[i] = temp[neg_start];
				neg--;
				neg_start++;
				i++;
			}
		}else if(pos != 0){
			while(pos > 0){
				arr[i] = temp[i];
				pos--;
				i++;
			}
		}
	    
	
		for(int i=0;i<n;i++){
			cout << arr[i] << " ";
		}
	}
};


int main(){
	Solution obj;
	int arr[] = {93,85,-59,45,-89,-41,-4,-98,79,-12};
	int size = sizeof(arr)/sizeof(int);
	obj.rearrange(arr,size);
	return 0;
}

/*
Time Complexity - O(N+N+N+N) - O(N)
	Multiples loops have been used 
Space Complexity - O(N)
	Temp array is being used to duplicate the elements in the original array 
*/

// Brute Force :

class Solution{
	public:
		void rearrange(int arr[],int n){
			vector<int> pos;
			vector<int> neg;
			int pos_idx,neg_idx = 0;
			for(int i=0;i<n;i++){
				if(arr[i] >= 0){
					pos.push_back(arr[i]);
				}else{
					neg.push_back(arr[i]);
				}
			}
				
			if(pos.size() > neg.size()){
				for(int i=0;i<neg.size();i++){
					arr[2*i] = pos[i];
					arr[2*i + 1] = neg[i]; 
				}
				int idx = neg.size()*2;
				for(int i=neg.size();i<pos.size();i++){
					arr[idx] = pos[i];
					idx++;
				}
			}
			else{
				for(int i=0;i<pos.size();i++){
					arr[2*i] = pos[i];
					arr[2*i + 1] = neg[i]; 
				}
				int idx = pos.size()*2;
				for(int i=pos.size();i<neg.size();i++){
					arr[idx] = neg[i];
					idx++;
				}
			}
			for(int i=0;i<n;i++){
				cout << arr[i] << " ";
			}
		}
};


int main(){
	Solution obj;
	int arr[] = {93,85,-59,45,-89,-41,-4,-98,79,-12};
	int size = sizeof(arr)/sizeof(int);
	obj.rearrange(arr,size);
	return 0;
}

/*
Time Complexity - O(2*N)
	O(N) for segregating positive and negative elements + O(N) for arranging it in the original array
Space Complexity - O(N/2) + O(N/2) -> O(N)
	Two vectors for storing positive and negative elements and each occupies N/2 size if equal 
	number of positive and negative elements are present. Worst case could be O(N) if only positive or 
	negative elements are present
*/

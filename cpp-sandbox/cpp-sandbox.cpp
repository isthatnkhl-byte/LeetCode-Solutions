#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;
//step 1 : traverse through the array 
//step 2 : add current element into the value of sum (initially 0)
//step 2 : if current value of sum is greater than max ( max = INT_MIN ) replace max with sum
//step 3 : if sum value currently is negative set it back to 0
//step 4 : if sum value currently is positive add the next array value into it
int kadanealgo(int arr[], int& n) {
    int maxi = INT_MIN;
    int sum = 0;
      for (int i = 0; i < n; i++) {
             sum+=arr[i];
             maxi = max(maxi,sum);
             if (sum < 0 ) {
                  sum = 0;
                 }
          }
       return maxi;
}
    
int main() {
    int arr[] = {-10, -2, 100, -101, 102, 103, -3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "max subarray sum = " << kadanealgo(arr,n);
    return 0;
    }
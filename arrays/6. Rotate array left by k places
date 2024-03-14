Problem statement
Given an array 'arr' with 'n' elements, the task is to rotate the array to the left by 'k' steps, where 'k' is non-negative.



Example:
'arr '= [1,2,3,4,5]
'k' = 1  rotated array = [2,3,4,5,1]
'k' = 2  rotated array = [3,4,5,1,2]
'k' = 3  rotated array = [4,5,1,2,3] and so on.


vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.

    // approach 1.
    // Time Complexity -> O(n+k)
    // Space Complexity -> O(k)


     /*int n=arr.size();
    if(n==0) return arr;
    k=k%n;
    if(k>n) return arr;
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i]=arr[i];
    }
    for(int i=0;i<n-k;i++){
        arr[i]=arr[i+k];
    }
    for(int i=n-k;i<n;i++){
        arr[i]=temp[i-n+k];
    }
    return arr;*/

    // approach 2
    // Time complexity - O(N)
    // Space Complexity -O(1)

    reverse(arr.begin(),arr.begin()+k);

    reverse(arr.begin()+k,arr.end());

    reverse(arr.begin(),arr.end());
    return arr;
}

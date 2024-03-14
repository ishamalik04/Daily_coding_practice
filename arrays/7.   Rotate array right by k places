vector<int> rotateArray(vector<int>arr, int k) {
//   approach 1 
//   time complexity - O(N+K)
//   space complexity -O(K)

    /*int n=arr.size();
    if(n==0) return arr;
    k=k%n;
    if (k>n) return arr;
    int temp[k];
    
    for(int i=n-k;i<n;i++){
        temp[i-n+k]=arr[i];
    }
    for(int i=n-k-1;i>=0;i--){
        arr[i+k]=arr[i];
    }
    for(int i=0;i<k;i++){
        arr[i]=temp[i];
    }
    return arr;*/
    
    
    // approach 2
    // time complexity-O(N)
    // space complexity-O(1)
    
    reverse(arr.begin(),arr.end()-k-1);
    reverse(arr.end()-k,arr.end()+n-1);
    reverse(arr.begin(),arr.end());
    
    return arr;
}

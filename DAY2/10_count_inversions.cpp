/*
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j 
Example: 

Input: arr[] = {8, 4, 2, 1}
Output: 6

Explanation: Given array has six inversions:
(8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).


Input: arr[] = {3, 1, 2}
Output: 2

Explanation: Given array has two inversions:
(3, 1), (3, 2) 
*/
long long merging(int A[], int left, int mid, int right){
   
    int i=left, j=mid, k=0;
    int temp[right-left+1];
    long long count=0;
    while(i<mid && j<=right){
        if(A[i]<=A[j]){
            temp[k++] = A[i++];
            
        }
        else{
            temp[k++]=A[j++];
            count+=mid-i;
        }
    }
    while(i<mid){
        temp[k++] = A[i++];
    }
    while(j<=right){
        temp[k++] = A[j++];
    }
    for(int i=left, k=0; i<=right; i++,k++)
        A[i] = temp[k];
    
    return count;
}

long long merge_sort(int A[], int left, int right){
    long long count=0;
    if(right>left){
        int mid = left + (right-left)/2;
        
        long long left_count = merge_sort(A, left, mid);
        long long right_count = merge_sort(A, mid+1, right);
        long long merge_count = merging(A, left, mid+1, right);
        return left_count + right_count + merge_count;
        
    }
    return count;
}
long long solve(int A[], int n)
{
	// Write your code here.
    int left =0;
    int right = n-1;
    long long ans = merge_sort(A, left, right);
    return ans;
}

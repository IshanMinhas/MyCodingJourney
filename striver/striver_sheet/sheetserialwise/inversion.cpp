//BRUTEFORCE
/* 
    Time Complexity : O(N ^ 2)
    Space Complexity : O(1)

    Where 'N' is the total number of elements in the array/list.
*/

long long getInversions(long long *arr, int n){
    // Variable to store the total inversions in the array.
    long long totalInversions = 0;

    // Check for each element whether any smaller element is present on right side.
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            if (arr[i] > arr[j]){
                ++totalInversions;
            }
        }
    }
    return totalInversions;
}

















// FENWICK TREE

/*
    Time Complexity : O(N*log(N))
    Space Complexity : O(N)

    Where, N is the size of the array.
*/

#include <vector>
#include <algorithm>
void fenwickUpdate(int index, int siz, vector<long long> &fenwick)
{
    while (index <= siz)
    {
        // Update the current element in the fenwick vector.
        fenwick[index] += 1;

        // Increase the index to the child index in the fenwick tree.
        index = index + (index & (-index));
    }
}
long long fenwickSum(int index, vector<long long> &fenwick)
{
    long long sum = 0;
    while (index > 0)
    {

        // Add the value of current node in sum.
        sum += fenwick[index];

        // Move to the parent node of the current node.
        index = index - (index & (-index));
    }
    return sum;
}

long long getInversions(long long *arr, int n) {

    // Take a 2D vector to store the sorted array and their initial index.
    vector<vector<int>> mapping(n, vector<int>(2));

    vector<long long> fenwick(n + 1, 0), mask(n);

    for (int i = 0; i < n; i++) {
        mapping[i][0] = arr[i];
        mapping[i][1] = i;
    }

    // Sort the mapping array and update all the permutations to mask vector.
    sort(mapping.begin(), mapping.end());
    for (int i = 0; i < n; i++) {
        mask[mapping[i][1]] = i + 1;
    }

    long long answer = 0;
    for (int i = n - 1; i >= 0; i--) {

        // Calculate the number of elements greater than the current element.
        answer += fenwickSum(mask[i] - 1, fenwick);

        // Update the element that has been visited.
        fenwickUpdate(mask[i], n, fenwick);
    }
    return answer;
}



// MERGE SORT












/*
    Time complexity : O(N * log(N))
    Space complexity : O(N)

    Where 'N' is the total number of elements in the array/list.
*/

// Function to merge the two subarrays.
long long merge(long long arr[], int left, int mid, int right){
    int i = left, j = mid, k = 0;
    long long invCount = 0;
    int temp[(right - left + 1)];

    while ((i < mid) && (j <= right)){
        if (arr[i] <= arr[j]){
            temp[k] = arr[i];
            ++k;
            ++i;
        }
        else{
            temp[k] = arr[j];
            invCount += (mid - i);
            ++k;
            ++j;
        }
    }

    while (i < mid){
        temp[k] = arr[i];
        ++k;
        ++i;
    }

    while (j <= right){
        temp[k] = arr[j];
        ++k;
        ++j;
    }

    for (i = left, k = 0; i <= right; i++, k++){
        arr[i] = temp[k];
    }

    return invCount;
}

// Function to split two subarrays and then merge them and count inversions.
long long mergeSort(long long arr[], int left, int right){
    long long invCount = 0;

    if (right > left){
        int mid = (right + left) / 2;

        /* 
            Divide the array into two parts
            total inversion count will be the
            sum of 'INVCOUNT' of left part +
            'INVCOUNT' of right part + 'INVCOUNT' of
            their combined part.
        */
        invCount = mergeSort(arr, left, mid);
        invCount += mergeSort(arr, mid + 1, right);

        // Merge both parts and count their combined inversions.
        invCount += merge(arr, left, mid + 1, right);
    }
    return invCount;
}

long long getInversions(long long arr[], int n){
    return mergeSort(arr, 0, n - 1);
}
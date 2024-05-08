class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while (j >= 0) nums1[k--] = nums2[j--];
    }
};

// class Solution {
//     private:
//     void swapIfGreater(long long & arr1, long long & arr2, int ind1, int ind2){
//         if(arr1[ind1] > arr2[ind2]) swap(arr1[ind1], arr2[ind2]);
//     }
// public:

//     void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
//         int len=(n+m);
//         int gap=(len /2) + (len%2);
//         while(gap>0){
//             int left=0;
//             int right=0;
//             int right<left+gap;
//             while(right <len){
//                 if(left<n && right>=n)  swapIfGreater(arr1, arr2, left, right-n);
//                 else if(left >=n) swapIfGreater(arr2, arr2, left-n, right-n);
//                 else   swapIfGreater(arr1, arr1, left, right)
                   
//             }
//         }
//     }
// };

// #include <vector>
// using namespace std;

// class Solution {
// private:
//     void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int ind1, int ind2) {
//         if (arr1[ind1] > arr2[ind2]) {
//             swap(arr1[ind1], arr2[ind2]);
//         }
//     }

// public:
//     void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
//         int len = m + n;
//         int gap = len / 2;
        
//         while (gap > 0) {
//             for (int i = 0; i + gap < m; i++) {
//                 swapIfGreater(arr1, arr1, i, i + gap);
//             }
            
//             for (int j = max(0, gap - m); j < n && j + gap - m < m; j++) {
//                 swapIfGreater(arr1, arr2, j + gap - m, j);
//             }
            
//             gap = gap == 1 ? 0 : (gap + 1) / 2;
//         }
//     }
// };

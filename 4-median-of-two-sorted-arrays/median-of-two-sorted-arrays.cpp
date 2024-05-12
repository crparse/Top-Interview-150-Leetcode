class Solution {
    double solve(vector<int>& nums1,int n,vector<int>& nums2,int m){
        if(n>m) return solve(nums2,m,nums1,n);//To make time=O(min(logN,logM))
        
        int low=0,high=n;
        while(low<=high){
            int partitionX=(low+high)/2;
            int partitionY=(m+n+1)/2-partitionX;
            
            int maxLeftX = partitionX==0?INT_MIN:nums1[partitionX-1];
            int minRightX = partitionX==n?INT_MAX:nums1[partitionX];
            
            int maxLeftY = partitionY==0?INT_MIN:nums2[partitionY-1];
            int minRightY = partitionY==m?INT_MAX:nums2[partitionY];
            
            //Case-1: Median found
            if(maxLeftX<=minRightY and maxLeftY<=minRightX){
                if((m+n)%2==0) return (double(max(maxLeftX,maxLeftY)+double(min(minRightX,minRightY)))/2);
                else return double(max(maxLeftX,maxLeftY));
            } 
            else if(maxLeftX>minRightY)    high=partitionX-1; //Move left
            else   low=partitionX+1;  //Move right
                
        }
        return double(0);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1,nums1.size(),nums2,nums2.size());
    }
};
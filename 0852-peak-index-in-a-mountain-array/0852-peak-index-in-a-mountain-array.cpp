class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0, r = arr.size()-1;
        while(l<=r){
            int mid = r - (r - l)/2;
            if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid])
                return mid;
            else if(arr[mid-1]<arr[mid] && arr[mid+1]>arr[mid])
                l = mid+1;
            else if(arr[mid-1]>arr[mid] && arr[mid+1]<arr[mid])
                r = mid-1;
        }
        return 0;
    }
};
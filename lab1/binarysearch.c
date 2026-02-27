int search(int* nums, int numsSize, int target) {
    int low=0,high=numsSize,mid;
    mid=(high+low)/2;
    for(int i=low;i<high;i++){
        if(nums[i]==target){
            return i;
        }
        else if(nums[i]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }return -1;
}

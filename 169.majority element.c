int majorityElement(int* nums, int numsSize) {
    int num = 0;
    int count = 0;

    // Find the number
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            num = nums[i];
        }
        count += (nums[i] == num) ? 1 : -1;
    }

    return num;
}
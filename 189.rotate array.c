void rotate(int nums[], int numsSize, int k) {
    // If k is 0 or if numsSize is 0, no rotation needed
    if (k == 0 || numsSize == 0) {
        return;
    }
    
    k = k % numsSize;  // Handle cases where k is larger than numsSize
    
    // Create a temporary array
    int *temp = (int *)malloc(numsSize * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    // Copy elements to the temporary array in rotated order
    for (int i = 0; i < numsSize; i++) {
        temp[(i + k) % numsSize] = nums[i];
    }
    
    // Copy elements back to the original array
    for (int i = 0; i < numsSize; i++) {
        nums[i] = temp[i];
    }
    
    // Free the temporary array
    free(temp);
}
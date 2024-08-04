

int removeElement(int nums[], int numsSize, int val) {
    int write_index = 0;

    for (int read_index = 0; read_index < numsSize; read_index++) {
        if (nums[read_index] != val) {
            nums[write_index] = nums[read_index];
            write_index++;
        }
    }

    return write_index;
}


/*Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 *
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.*/
void moveZeroes(int* nums, int numsSize) {
    int *nz = nums, *p = nums;
    for(;p < nums + numsSize;++p)
        if (*p!=0)
            *nz++ = *p;
    for(;nz< nums + numsSize; ++nz)
        *nz = 0;
}

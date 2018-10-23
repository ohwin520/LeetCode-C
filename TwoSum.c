#include <stdio.h>
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *n = malloc(2 * sizeof(int));
    for(int i = 0; i < numsSize - 1; i++) {
        for(int j = i + 1; j< numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                n[0] = i;
                n[1] = j;
                break;
            }
        }

    }
    return n;
}


int main () {

	int nums[4] = {2, 7, 11, 15};
	int *n = twoSum(nums, 4, 9); 
	printf("%d %d\n", n[0], n[1]);
	return 0;
}
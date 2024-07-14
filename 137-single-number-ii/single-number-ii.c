int singleNumber(int* nums, int numsSize) {
     int ones = 0;
    int twos = 0;

    for (int num=0 ; num< numsSize ; num++) {
      ones ^= (nums[num] & ~twos);
      twos ^= (nums[num] & ~ones);
    }

    return ones;
}
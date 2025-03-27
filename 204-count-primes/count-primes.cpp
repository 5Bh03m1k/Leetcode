vector<bool> arr(5000000, true);
void prime(vector<bool>& arr) {
    arr[0] = arr[1] = false;
    arr[2] = true;
    for (int i = 2; i * i < 4999999; i++) {
        if (arr[i]) {
            for (int j = 2 * i; j <= 4999999; j += i) {
                if (arr[j])
                    arr[j] = false;
            }
        }
    }
}
class Solution {
public:
    int countPrimes(int n) {
        if(arr[0])  prime(arr);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i])
                count++;
        }
        return count;
    }
};
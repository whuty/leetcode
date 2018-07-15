
#include <iostream>
#include <random>
#include <vector>
void QuickSort(std::vector<int>& nums, int lo, int hi) {
    if (nums.empty() || lo < 0 || hi >= nums.size())
        throw new std::exception();

    if (lo <= hi)
        return;

    int p = lo + std::rand() % (hi - lo + 1);
    std::swap(nums[lo], nums[p]);
    int pivot = lo;
    int v = nums[lo];
    for (int i = lo + 1; i <= hi; i++) {
        if (nums[i] < v) {
            pivot++;
            std::swap(nums[i], nums[pivot]);
        }
    }
    std::swap(nums[pivot], nums[lo]);
    QuickSort(nums, lo, pivot - 1);
    QuickSort(nums, pivot + 1, hi);
}

void QuickSort3Way(std::vector<int>& nums, int lo, int hi) {
    if (nums.empty() || lo < 0 || hi >= nums.size())
        throw new std::exception();

    if (hi <= lo)
        return;

    int p = lo + std::rand() % (hi - lo + 1);
    std::swap(nums[lo], nums[p]);
    int v = nums[lo];
    int lt = lo, index = lo + 1, gt = hi;
    while (index <= gt) {
        if (nums[index] < v)
            std::swap(nums[index++], nums[lt++]);
        else if (nums[index] > v)
            std::swap(nums[index], nums[gt--]);
        else
            index++;
    }
    QuickSort3Way(nums, lo, lt - 1);
    QuickSort3Way(nums, gt + 1, hi);
}

int main() {
    std::vector<int> nums = {0, 2, 2, 3, 1, 4, 8, 5};
    QuickSort3Way(nums, 0, nums.size() - 1);
    for (int i : nums) {
        std::cout << i << " " << std::endl;
    }
}
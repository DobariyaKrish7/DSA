#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void mgr(vector<int>& nums, int l, int m, int h) {
        vector<int> v;
        int le = l;
        int r = m + 1;

        // Merge the two sorted halves
        while (le <= m && r <= h) {
            if (nums[le] <= nums[r]) {
                v.push_back(nums[le]);
                le++;
            } else {
                v.push_back(nums[r]);
                r++;
            }
        }

        // Copy remaining elements from left half
        while (le <= m) {
            v.push_back(nums[le]);
            le++;
        }

        // Copy remaining elements from right half
        while (r <= h) {
            v.push_back(nums[r]);
            r++;
        }

        // Copy merged array back into original array
        for (int i = 0; i < v.size(); i++) {
            nums[l + i] = v[i];
        }
    }

    void mergeSortUtil(vector<int>& nums, int l, int h) {
        if (l >= h) return;
        int m = (l + h) / 2;
        mergeSortUtil(nums, l, m);
        mergeSortUtil(nums, m + 1, h);
        mgr(nums, l, m, h);
    }

    vector<int> mergeSort(vector<int>& nums) {
        mergeSortUtil(nums, 0, nums.size() - 1);
        return nums;
    }
};
void ins(vector<int>& nums, int n) {
    if(n == nums.size()) return;
    int i = n;
    while (i > 0 && nums[i - 1] > nums[i]) {
        swap(nums[i - 1], nums[i]);
        i--;
    }
    ins(nums, n+1);
}
// Quick Sort function
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // Place smaller element at correct position
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot at its correct position
    return i + 1;
}

// Recursive Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Example usage
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Solution sol;
    // vector<int> sorted = sol.mergeSort(nums);
    //ins(nums, 0);
    quickSort(nums, 0, n - 1);


    cout << "Sorted array:\n";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

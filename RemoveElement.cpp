#include "iostream"
#include <stdio.h>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val) {
  int res = 0;
  int end = nums.size() - 1;
  int lastEnd = nums.size();
  int start = 0;
  int lastStart = -1;
  while (start < end) {
    if (nums[start] != val && lastStart != start) {
      res++;
      lastStart = start;
    }
    if (nums[end] != val && lastEnd != end) {
      res++;
      lastEnd = end;
    }
    if (nums[start] == val && nums[end] != val) {
      nums[start] = nums[end];
      start++;
      end--;
    } else {
      if (nums[end] == val) {
        end--;
      }
      if (nums[start] != val) {
        start++;
      }
    }
  }
  if (start == end && nums[start] != val && lastEnd != end &&
      lastStart != start) {
    res++;
  }

  return res;
}

void printVector(vector<int> &nums1) {
  for (int c : nums1) {
    cout << c << endl;
  }
}

int main() {
  int myints[] = {0, 1, 2, 2, 3, 0, 4, 2};
  std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
  int res = removeElement(fifth, 2);
  printVector(fifth);
  cout << "res: " << res << endl;
  cout << "length: " << fifth.size() << endl;
  return 0;
}

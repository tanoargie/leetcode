#include "iostream"
#include "queue"
#include "vector"
#include <algorithm>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
  int f = 0;
  int s = 0;
  queue<int> rest;
  if (n == 0) {
  } else if (m == 0) {
    nums1 = nums2;
  } else {
    while (f < n + m) {
      if (f >= m) {
        // desencolo de la pila o mando nums2 (lo que sea menor)
        if (rest.size() > 0 && ((s < n && rest.front() < nums2[s]) || s >= n)) {
          nums1[f] = rest.front();
          rest.pop();
        } else {
          nums1[f] = nums2[s];
          s++;
        }
      } else {
        if (rest.size() > 0 && s < n && nums2[s] < rest.front()) {
          // hay pila y nums2 es menor al tope
          int pivot = nums1[f];
          rest.push(pivot);
          nums1[f] = nums2[s];
          s++;
        } else if (rest.size() > 0) {
          // hay pila y tope es menor que nums2 o ya no hay mas nums2
          int pivot = nums1[f];
          rest.push(pivot);
          nums1[f] = rest.front();
          rest.pop();
        } else if (nums2[s] < nums1[f]) {
          // no hay pila y nums2 es menor a nums1
          int pivot = nums1[f];
          nums1[f] = nums2[s];
          rest.push(pivot);
          s++;
        }
      }
      f++;
    }
  }
}

void printVector(vector<int> &nums1) {
  for (int c : nums1) {
    cout << c << endl;
  }
}

int main() {
  int myints[] = {-12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  std::vector<int> nums1(myints, myints + sizeof(myints) / sizeof(int));
  int myints2[] = {
      -49, -45, -42, -41, -40, -39, -39, -39, -38, -36, -34, -34, -33, -33, -32,
      -31, -29, -28, -26, -26, -24, -21, -20, -20, -18, -16, -16, -14, -11, -7,
      -6,  -5,  -4,  -4,  -3,  -3,  -2,  -2,  -1,  0,   0,   0,   2,   2,   6,
      7,   7,   8,   10,  10,  13,  13,  15,  15,  16,  17,  17,  19,  19,  20,
      20,  20,  21,  21,  22,  22,  24,  24,  25,  26,  27,  29,  30,  30,  30,
      35,  36,  36,  36,  37,  39,  40,  41,  42,  45,  46,  46,  46,  47,  48};
  std::vector<int> nums2(myints2, myints2 + sizeof(myints2) / sizeof(int));
  // cout << "fasdf" << endl;
  merge(nums1, 1, nums2, 90);
  printVector(nums1);
  return 0;
}

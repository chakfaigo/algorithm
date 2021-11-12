//
// Created by chakfai on 2021/11/7.
//
#include<iostream>
#include<string>
#include<vector>

using namespace std;

/**
 * 4. 寻找两个正序数组的中位数 https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 22min
 * Q1:如何处理0和null的情况
 */
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int length = nums1.size() + nums2.size();
//    int m = length / 2, n = length / 2 - 1, k = 0;
    //循环判断增加上去，例如0位置谁小，小就占一个位置，
    int m = 0, n = 0, m1, m2;
    bool mark1 = false, mark2 = false;
    for (int i = 0; i < length; ++i) {//i只是统计计数个数而已，没有参与取值坐标
        if (nums1[m] > nums2[n] || mark1) {//0,0进来
            if (i == length / 2) {
                m2 = nums2[n];
                break;
            } else if (i == length / 2 - 1) {
                m1 = nums2[n];
            }
            if (nums2.size() > n + 1) {
                n++;
                continue;
            } else {
                mark2 = true;
            }
        }
        if (nums1[m] < nums2[n] || mark2) {
            if (i == length / 2) {
                m2 = nums1[m];
                break;
            } else if (i == length / 2 - 1) {
                m1 = nums1[m];
            }
            if (nums1.size() > m + 1)
                m++;
            else
                mark1 = true;
        }
    }
    if (length % 2 == 0) {
        cout << "m1 = " << m1 << " m2 = " << m2;
    } else
        cout << "中 = " << m2;
}

int main() {
//    vector<int> nums1 = {1, 2, 6};
//    vector<int> nums2 = {3, 4, 5};

//    vector<int> nums1 = {1, 3};
//    vector<int> nums2 = {2};

//    vector<int> nums1 = {1, 2};//
//    vector<int> nums2 = {3, 4};

//    vector<int> nums1 = {0, 0};//没通过
//    vector<int> nums2 = {0, 0};

    vector<int> nums1 = {};//没通过
    vector<int> nums2 = {1};

//    vector<int> nums1 = {2};//没通过
//    vector<int> nums2 = {};
    findMedianSortedArrays(nums1, nums2);
}



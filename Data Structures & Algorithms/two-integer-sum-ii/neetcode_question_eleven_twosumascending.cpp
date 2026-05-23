#include <iostream>

using namespace std;

// array is sorted in ascending order, return one indexed positions of the two numbers such that they add up to target
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        while(i<j){
            if(numbers[i]+numbers[j]==target){
                return {i+1, j+1};  
                }

            if(numbers[i]+numbers[j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return {};
    }
};

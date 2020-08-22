#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Solution {
public:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

    bool judgePoint24(vector<int> &nums) {
        vector<double> l;
        for (const int &num : nums) {
            l.emplace_back(static_cast<double>(num));
        }
        return solve(l);
    }

    bool solve(vector<double> &l) {
        if (l.size() == 1) {
            return fabs(l[0] - TARGET) < EPSILON;
        }
        int size = l.size();
        for (int i = 0; i < size; i++) {
            for (int j = i+1; j < size; j++) {
                    vector<double> list2 = vector<double>();
                    vector<double> list3 = vector<double>();
                    for (int k = 0; k < size; k++) {
                        if (k != i && k != j) {
                            list2.emplace_back(l[k]);
                            list3.emplace_back(l[k]);
                        }
                    }
                    for (int k = 0; k < 4; k++) {
                        if (k == ADD) {
                            list2.emplace_back(l[i] + l[j]);
                        } else if (k == MULTIPLY) {
                            list2.emplace_back(l[i] * l[j]);
                        } else if (k == SUBTRACT) {
                            list2.emplace_back(l[i] - l[j]);
                            list3.emplace_back(l[i] + l[j]);
                        } else if (k == DIVIDE) {
                            if (fabs(l[j]) < EPSILON&&fabs(l[i]) < EPSILON) {
                                continue;
                            }
                            if(fabs(l[j]) < EPSILON){
                                list2.emplace_back(l[j] / l[i]);
                            } else{
                                list2.emplace_back(l[i] / l[j]);
                            }
                            if(fabs(l[i]) < EPSILON){
                                list3.emplace_back(l[i] / l[j]);
                            }else{
                                list3.emplace_back(l[j] / l[i]);
                            } 
                        }
                        if (solve(list2)||solve(list3)) {
                            return true;
                        }
                        list2.pop_back();
                        list3.pop_back();
                        
                    }
            }
        }
        return false;
    }
};

int main(){

    vector<int> nums = {4,1,8,7};
    Solution t;
    t.judgePoint24(nums);
    system("psuse");
    return 0;
}
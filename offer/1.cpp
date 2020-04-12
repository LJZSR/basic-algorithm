class Solution {
public:
    int bSearchR(int target, vector<vector<int> > &array) {
        int left = -1;
        int right = array[0].size();
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (array[0][mid] >= target) {
                right = mid;
            } 
            else {
                left = mid;
            }
        }
        return right;
    }
    int bSearchC(int target, int index, vector<vector<int> > &array) {
        int left = -1;
        int right = array.size();
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (array[mid][index] >= target) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return right;
    }
    bool Find(int target, vector<vector<int> > array) {
        int index = bSearchR(target, array);
        if (index == array[0].size() || array[0][index] != target) --index;
        for (int i = 0; i <= index; ++i) {
            int result = bSearchC(target, i, array);
            if (result != array.size() && array[result][i] == target) return true;
        }
        return false;
    }
};
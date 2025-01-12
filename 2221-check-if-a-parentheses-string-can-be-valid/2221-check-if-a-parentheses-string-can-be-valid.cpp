class Nexify07 {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1, n2 = right - mid;
        vector<int> L(n1), R(n2);
        int i = 0, j = 0;
        while(i < n1) L[i] = arr[left + i], i++;
        while(j < n2) R[j] = arr[mid + 1 + j], j++;
        
        i = 0, j = 0;
        int k = left;
        while(i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        while(i < n1) arr[k++] = L[i++];
        while(j < n2) arr[k++] = R[j++];
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if(left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
};

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int len = s.size(), idx = 0;
        while(idx < len) {
            if(locked[idx] == '0') s[idx] = '*';
            idx++;
        }
        
        stack<int> openBrackets, stars;
        idx = 0;
        while(idx < len) {
            if(s[idx] == '(') openBrackets.push(idx);
            else if(s[idx] == '*') stars.push(idx);
            else {
                if(!openBrackets.empty()) openBrackets.pop();
                else if(!stars.empty()) stars.pop();
                else return false;
            }
            idx++;
        }
        
        while(!openBrackets.empty() && !stars.empty() && openBrackets.top() < stars.top()) {
            openBrackets.pop();
            stars.pop();
        }
        
        return !(stars.size() % 2) && openBrackets.empty();
    }
};

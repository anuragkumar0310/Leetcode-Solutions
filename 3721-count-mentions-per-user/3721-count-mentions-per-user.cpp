#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <sstream>
using namespace std;

class Nexify07 {
public:
    static void mergeSort(vector<int>& arr) {
        if (arr.size() <= 1) return;
        mergeSortHelper(arr, 0, arr.size() - 1);
    }

    static void heapSort(vector<int>& arr) {
        int n = arr.size();
        
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

private:
    static void mergeSortHelper(vector<int>& arr, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    static void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> leftArr(n1);
        vector<int> rightArr(n2);
        
        for (int i = 0; i < n1; i++) {
            leftArr[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightArr[j] = arr[mid + 1 + j];
        }
        
        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
            }
        }
        
        while (i < n1) {
            arr[k++] = leftArr[i++];
        }
        
        while (j < n2) {
            arr[k++] = rightArr[j++];
        }
    }

    static void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
};

struct OnlineEvent {
    int timestamp;
    int user_id;
};

struct CompareOnlineEvent {
    bool operator()(const OnlineEvent& a, const OnlineEvent& b) const {
        return a.timestamp > b.timestamp;
    }
};

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [&](const vector<string>& a, const vector<string>& b) -> bool {
            return stoi(a[1]) < stoi(b[1]);
        });
        
        vector<int> mentions(numberOfUsers, 0);
        vector<int> online(numberOfUsers, 1);
        priority_queue<OnlineEvent, vector<OnlineEvent>, CompareOnlineEvent> online_heap;
        
        int n = events.size();
        int i = 0;
        
        while (i < n) {
            int current_t = stoi(events[i][1]);
            
            while (!online_heap.empty() && online_heap.top().timestamp <= current_t) {
                int user_to_online = online_heap.top().user_id;
                online[user_to_online] = user_to_online >= 0 && user_to_online < numberOfUsers ? 1 : 0;
                online_heap.pop();
            }
            
            int j = i;
            while (j < n && stoi(events[j][1]) == current_t) {
                j++;
            }
            
            for (int k = i; k < j; k++) {
                if (events[k][0] == "OFFLINE") {
                    int user_id = stoi(events[k][2]);
                    online[user_id] = user_id >= 0 && user_id < numberOfUsers && online[user_id] ? 0 : 1;
                    
                    OnlineEvent oe;
                    oe.timestamp = current_t + 60;
                    oe.user_id = user_id;
                    online_heap.push(oe);
                }
            }
            
            for (int k = i; k < j; k++) {
                if (events[k][0] == "MESSAGE") {
                    string mentions_string = events[k][2];
                    
                    if (mentions_string == "ALL") {
                        for (int u = 0; u < numberOfUsers; u++) {
                            mentions[u]++;
                        }
                    } else if (mentions_string == "HERE") {
                        for (int u = 0; u < numberOfUsers; u++) {
                            mentions[u] += online[u] ? 1 : 0;
                        }
                    } else {
                        stringstream ss(mentions_string);
                        string token;
                        while (ss >> token) {
                            if (token.size() >= 3 && token.substr(0,2) == "id") {
                                string id_str = token.substr(2);
                                int valid = 1;
                                for (char c : id_str) {
                                    valid = isdigit(c) ? valid : 0;
                                }
                                
                                if (valid) {
                                    int user_id = stoi(id_str);
                                    mentions[user_id] += user_id >= 0 && user_id < numberOfUsers ? 1 : 0;
                                }
                            }
                        }
                    }
                }
            }
            
            i = j;
        }
        
        return mentions;
    }
};


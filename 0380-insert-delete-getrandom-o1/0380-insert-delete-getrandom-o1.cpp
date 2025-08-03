class RandomizedSet {
    vector<int> arr;
    unordered_map<int, int> pos;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (pos.find(val) != pos.end())
            return false;
        arr.push_back(val);
        pos[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (pos.find(val) == pos.end())
            return false;
        int idx = pos[val];
        int last = arr.back();
        arr[idx] = last;
        pos[last] = idx;
        arr.pop_back();
        pos.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};
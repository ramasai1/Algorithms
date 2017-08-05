vector<int> two_sum(vector<int> &nums, int target) {
    vector<int> res ;
    int index1, index2;
    map<int, int> hashmap;
    for(int i = 0; i < nums.size(); i++) {
        if(hashmap.find(nums[i]) != hashmap.end()) {
            index1 = hashmap[nums[i]];
            index2 = i;
            res.push_back(index1);
            res.push_back(index2);
        }
        else {
            hashmap[target - nums[i]] = i;
        }
    }
    return res;
}

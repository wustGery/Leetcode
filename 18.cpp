class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(),nums.end());
        for(vector<int>::iterator iter = nums.begin();iter!=nums.end();iter++) cout<<*iter<<" ";
        cout<<endl;
        set<vector<int> >res;
        int liner_size = nums.size();
        //if(liner_size<4) return NULL;
        for(int i=0;i<liner_size-3;i++)
            for(int j=i+1;j<liner_size-2;j++)
            {
                int target_left = target-nums[i]-nums[j];
                int l = j+1;
                int r = liner_size-1;
                while(l<r)
                {
                    if(nums[l]+nums[r]<target_left) l++;
                    else if(nums[l]+nums[r]>target_left) r--;
                    else
                    {
                        initializer_list<int>lst{nums[i],nums[j],nums[l],nums[r]};
                        vector<int>temp(lst);
                        res.insert(temp);
                        l++;
                    }
                }
            }
        return vector<vector<int> >(res.begin(),res.end());
    }
};

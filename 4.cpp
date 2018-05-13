class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {   
        priority_queue<int>q1;//大根堆
        priority_queue<int,vector<int>,greater<int> >q2;//小根堆
        int cnt = 0;
        double ans;
        vector<int>vec;
        for(int i=0;i<nums1.size();i++)  vec.push_back(nums1[i]);
        for(int i=0;i<nums2.size();i++)  vec.push_back(nums2[i]);
        for(int i=0;i<vec.size();i++) 
        {
            ++cnt;
            if(cnt%2)
            {
                q2.push(vec[i]);
                int top_val = q2.top();
                q2.pop();
                q1.push(top_val);
            }
            else
            {
                q1.push(vec[i]);
                int top_val = q1.top();
                q1.pop();
                q2.push(top_val);
            }
        }
        int size = vec.size();
        if(size%2)  ans = q1.top()*1.0;
        else  ans = (q1.top()+q2.top())*1.0/2;
        return ans;
    }
};

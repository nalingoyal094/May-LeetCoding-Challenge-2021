class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        int mx=0;
        int max_index=0;
        long long int sum=0;
        for (int i=0;i<target.size();i++)
        {
            sum+=target[i];
            if (target[i]>mx)
            {
                mx=target[i];
                max_index=i;
            }
        }
        
        long long int diff=sum-mx;
        
        if (mx==1 || diff==1 ) return true;
        
        if (target.size()==1 || target[max_index]%diff==0 ||  diff>target[max_index]) return false;
        
        
        target[max_index]%=diff;
        
        return isPossible(target);
        
        
        
        
        
    }
};

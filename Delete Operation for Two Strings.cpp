class Solution {
public:
    
    int lcs(string word1, string word2)
    {
        int mx=0;
        
        int r=word1.size()+1;
        int c=word2.size()+1;
        int a[505][505]={0};
        
        for (int i=0;i<word1.size();i++)
        {
            for (int j=0;j<word2.size();j++)
            {
                a[i+1][j+1]= max(a[i][j+1],max(a[i+1][j],a[i][j]));
                if (word1[i]!=word2[j])
                {
                    a[i+1][j+1]=max(a[i][j+1],a[i+1][j]);
                    
                }
                else
                {
                    a[i+1][j+1]=a[i][j]+1;
                    
                    mx=max(mx,a[i+1][j+1]);
                }
                
                
            }
        }
        return mx;
        
        
    }
    
    
    int minDistance(string word1, string word2) {
        
        int size=word1.size()+word2.size();
       cout<<lcs(word1,word2)<<endl;
        return size-2*lcs(word1,word2);
        
        
        
    }
};







// II approach - without using LCS

class Solution {
public:
    
    int ok(string word1, string word2)
    {
        int mx=0;
        
        int r=word1.size()+1;
        int c=word2.size()+1;
        int a[505][505]={0};
        
        for (int i=0;i<=word1.size();i++)
        {
            for (int j=0;j<=word2.size();j++)
            {
                if (i==0)
                {
                    a[i][j]=j;
                    continue;
                }
                
                if (j==0)
                {
                    a[i][j]=i;
                    continue;
                }
                
                if (word1[i-1]!=word2[j-1])
                {
                    a[i][j]=min(a[i-1][j],a[i][j-1])+1;
                    
                }
                else
                {
                    a[i][j]=a[i-1][j-1];
                    
                  //  mx=max(mx,a[i][j]);
                }
                
                
            }
        }
        return a[word1.size()][word2.size()];
        
        
    }
    
    
    int minDistance(string word1, string word2) {
        
        int size=word1.size()+word2.size();
       //cout<<ok(word1,word2)<<endl;
        return ok(word1,word2);
        
        
        
    }
};



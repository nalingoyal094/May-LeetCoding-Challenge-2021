class Solution {
public:
    vector<vector<string>>ans;
    
    bool isValid(vector<string>a,int row , int col,int n){
        int total=0;
        // row wise check
        for(int i=0;i<n;i++){
            if(a[row][i]=='Q')
                total++;
        }
        if(total>0)
            return false;
        //column wise check
        total=0;
        for(int i=0;i<n;i++){
            if(a[i][col]=='Q')
                total++;
        }
        if(total>0)
            return false;
        // top left to bottom right diagonal
        total=0;
        for(int i=0;i<n;i++){
            if(row+i<n && col+i<n){
                if(a[row+i][col+i]=='Q')
                    total++;
            }
            else
                break;
        }
        if(total>0)
            return false;
        total=0;
        for(int i=0;i<n;i++){
            if(row-i>=0 && col-i>=0){
                if(a[row-i][col-i]=='Q')
                    total++;
            }
            else
                break;
        }
        if(total>0)
            return false;
        // from top right to bottom left
         total=0;
        for(int i=0;i<n;i++){
            if(row+i<n && col-i>=0){
                if(a[row+i][col-i]=='Q')
                    total++;
            }
            else
                break;
        }
        if(total>0)
            return false;
         total=0;
        for(int i=0;i<n;i++){
            if(row-i>=0 && col+i<n){
                if(a[row-i][col+i]=='Q')
                    total++;
            }
            else
                break;
        }
        if(total>0)
            return false;
        return true;
    }
    
    
    void ok(vector<string>a,int row,int n)
    {
        if (row==n)
        {
            ans.push_back(a);
            return;
        }
        
        for (int i=0;i<n;i++)
        {
            if (isValid(a,row,i,n))
            {
                a[row][i]='Q';
                ok(a,row+1,n);
                a[row][i]='.';
            }
        }
        
    }
    
    
    
    
    int totalNQueens(int n) {
        string start="";
        for (int i=0;i<n;i++)
        {
            start+=".";
        }
        
        vector<string>a(n,start);
        
        ok(a,0,n);
        
        return ans.size();
        
        
        
    }
};

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        vector<int> prefixcommonarray(n,-1);

        for(int curridx = 0; curridx < n; curridx++){

            int cmncnt = 0;

            for(int aidx =0; aidx <= curridx; aidx++){
               for (int bidx = 0; bidx <= curridx; bidx++){
                if(A[aidx]==B[bidx]){
                 cmncnt+=1;
                 break;

               }
            
            }
        }
      prefixcommonarray[curridx] = cmncnt;
    } 
    return  prefixcommonarray;
    }
};
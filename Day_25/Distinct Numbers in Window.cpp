vector<int> Solution::dNums(vector<int> &A, int B) {
    int n=A.size();
    vector<int>result;
    if(B>n) return result;
    map<int,int>mp;
    int i=0;
    int j=0;
    while(j<n){
        mp[A[j]]++;
        if(j>=(B-1)){
            if(j==(B-1)){
                result.push_back(mp.size());
            }else{
                mp[A[i]]--;
                if(mp[A[i]]==0){
                    mp.erase(A[i]);
                }
                i++;
                result.push_back(mp.size());
            }            
        }
        j++;
    }
    return result;

}

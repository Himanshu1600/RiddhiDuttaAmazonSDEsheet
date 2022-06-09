int maxLen(int arr[], int N)
{
    int sum=0;
    int res=0;
    map<int,int>mp;
    mp[0]=-1;
    for(int i=0;i<N;i++){
        if(arr[i]==0){
            sum-=1;
        }else{
            sum+=1;
        }
        if(mp.count(sum)){
            res=max(res,i-mp[sum]);
        }else{
            mp[sum]=i;
        }
    }
    return res;
}

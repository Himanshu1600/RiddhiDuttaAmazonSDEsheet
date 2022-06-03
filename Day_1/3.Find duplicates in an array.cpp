vector<int> duplicates(int arr[], int n) {
    vector<int>result;
    for(int i=0;i<n;i++){
        arr[arr[i]%n]+=n;
    }
    for(int i=0;i<n;i++){
        if((arr[i]/n)>1){
            result.push_back(i);
        }
    }
    if(result.size()==0) return {-1};
    return result;
}

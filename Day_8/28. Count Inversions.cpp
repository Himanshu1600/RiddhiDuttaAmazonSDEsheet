long long int result=0;
long long int inversionCount(long long arr[], long long N)
{
    result=0;
    mergesort(arr,0,N-1);
    return result;
}
void mergesort(long long arr[],long long low,long long high){
    if(low<high){
        long long int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        mergearr(arr,low,mid,high);
    }
}
void mergearr(long long arr[],long long low,long long mid,long long high){
    long long n1=mid-low+1,n2=high-mid;
    long long arr1[n1],arr2[n2];
    for(long long i=0;i<n1;i++) arr1[i]=arr[low+i];
    for(long long i=0;i<n2;i++) arr2[i]=arr[mid+i+1];
    long long i=0,j=0,k=low;
    while(i<n1&&j<n2){
        if(arr1[i]<=arr2[j]){
            arr[k++]=arr1[i++];
        }else{
            result+= (n1-i);
            arr[k++]=arr2[j++];
        }
    }
    while(i<n1) arr[k++]=arr1[i++];
    while(j<n2) arr[k++]=arr2[j++];
}

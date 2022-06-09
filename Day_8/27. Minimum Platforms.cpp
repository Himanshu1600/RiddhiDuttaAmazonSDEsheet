int findPlatform(int arr[], int dep[], int n)
{
  sort(arr,arr+n);
  sort(dep,dep+n);
  int d=0;
  int cnt=1;
  for(int i=1;i<n;i++){
      if(dep[d]>=arr[i]){
          cnt++;
      }else{
          d++;
      }
  }
  return cnt;
}

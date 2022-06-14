int matSearch (int N, int M, int matrix[][M], int x)
{
    for(int i=0;i<N;i++){
        if(x>=matrix[i][0]&&x<=matrix[i][M-1]){
            int left=0;
            int right=M-1;
            while(left<=right){
                int mid=(left+right)/2;
                if(matrix[i][mid]==x) return 1;
                if(matrix[i][mid]>x){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
        }
    }
    return 0;
}

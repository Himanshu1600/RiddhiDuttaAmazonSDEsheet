int canReach(int A[], int N) {
    int steps=0;
    for(int i=0;i<N;i++){
        if(i>steps) return 0;
        steps=max(steps,i+A[i]);
    }
    return 1;
}

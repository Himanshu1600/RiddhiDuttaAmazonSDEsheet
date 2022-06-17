listnode* swapPairs(listnode* A) {
    if(A==NULL || A->next==NULL){
        return A;
    }
    listnode* z=  A->next->next;
    A->next->next =A;
    A = A->next;
    A->next->next = swapPairs(z);
    return A;
}

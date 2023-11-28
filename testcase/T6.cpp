typedef struct NNode{
    struct NNode * nxtact;
}INSDS;

int __VERIFIER_nondet_ind();

INSDS * initLink(int n){
    INSDS* head=(INSDS*)malloc(sizeof(INSDS));
    head->nxtact=head;
    INSDS* cyclic=head;

    int i;
    for (i=2; i<=n; i++) {
        INSDS * body=(INSDS*)malloc(sizeof(INSDS));
        body->nxtact=body;
        cyclic->nxtact=body;
        cyclic=cyclic->nxtact;
    }
    cyclic->nxtact=cyclic;
    return head;
}

int main()
{
    int num = __VERIFIER_nondet_int();
    if( num <= 0 || num > 65534 )
        return 0;
    INSDS* list = initLink( num );
    INSDS* ip = list;
    while( ip != 0 )
    {
        INSDS *nxt = ip->nxtact;
        ip = nxt;
    }
    return 0;
}
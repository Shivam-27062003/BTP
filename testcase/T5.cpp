int __VERIFIER_nondet_int();
void* malloc(signed x);
typedef struct NNode{
    struct NNode * nxtact;
}INSDS;
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
    int o_num = num;
    INSDS* o_list = list;
    INSDS* o_ip = ip;
    while( ip != 0 )
    {
        INSDS *nxt = ip->nxtact;
        ip = nxt;
__CPROVER_assume(!(num==4));

__CPROVER_assume(!(num==2));

__CPROVER_assume(!(num==1));

__CPROVER_assume(!(num==3));

__CPROVER_assume(!(num==5));

__CPROVER_assert(!(o_num==num && o_ip==ip && o_list==list),"OK");
        o_num = num,o_list=list,o_ip=ip;
}
    return 0;
}
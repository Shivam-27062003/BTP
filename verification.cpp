int o_rc;
int o_errno;
int o_size;
int o_pos;
int o_flag;
int flag = 0;
int read(int,int);
int __VERIFIER_nondet_int();

int main()
{
    int pos = 0;
    int size = __VERIFIER_nondet_int();
    flag = 0;
    int errno = 0;
    if( size <= 0 || size > 65536 )
        return 0;
    while( pos < size )
    {
        int rc = read( pos, size - pos);
        if( rc == -1 )
        {
            errno++;
            if( errno == 5 )
                return 0;
            continue;
        }
        pos += rc;
        if(!(rc!=0))break;
    
__CPROVER_assert(!(o_flag==flag && o_pos==pos && o_size==size && o_errno==errno && o_rc==rc),"OK");
o_flag=flag;
o_pos=pos;
o_size=size;
o_errno=errno;
o_rc=rc;
}
    return 0;
}
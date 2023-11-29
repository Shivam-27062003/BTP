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
    
__CPROVER_assume(!(flag==0 && pos==0 && size==1 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==0 && size==1 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-1612454147 && size==65536 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-1880873219 && size==65536 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==42510 && size==65536 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-2120482946 && size==16385 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-2147131391 && size==65536 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-1940914175 && size==32768 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-201260124 && size==1 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-1879035440 && size==2 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==0 && size==16384 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==0 && size==2442 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-404498463 && size==65536 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==0 && size==8 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-820323707 && size==1 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-20922365 && size==1 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==0 && size==65536 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-1929362240 && size==49152 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==0 && size==4 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-18750336 && size==61952 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-1073735542 && size==57344 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==0 && size==2048 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-780664757 && size==4 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==0 && size==128 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-561971329 && size==8193 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-1501503419 && size==53248 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-1010827458 && size==17 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-1881669761 && size==1 && errno==1 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-2147371520 && size==1 && errno==0 && rc==0));

__CPROVER_assume(!(flag==0 && pos==-1031797764 && size==2048 && errno==0 && rc==0));

__CPROVER_assert(!(o_flag==flag && o_pos==pos && o_size==size && o_errno==errno && o_rc==rc),"OK");
o_flag=flag;
o_pos=pos;
o_size=size;
o_errno=errno;
o_rc=rc;
}
    return 0;
}
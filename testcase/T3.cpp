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
            errno++;// abnormal is OK
            if( errno == 5 )
                return 0;
            continue;
        }
        pos += rc;
    }
    return 0;
}
int flag = 0;
int read( int, int);
int __VERIFIER_nondet_int();

int main()
{
    int count =__VERIFIER_nondet_int();
    if( count <= 0 )
        return 0;
    int ret;
    int buf = 0;
    while( count > 0 )
    {
        ret = read( buf, count );
        if( ret < 0 )
            return 0;
        count -= ret;
        buf += ret;
    }
    return 0;
}
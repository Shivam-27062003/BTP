int __VERIFIER_nondet_uint();

int main()
{
    unsigned int n = __VERIFIER_nondet_uint();
    while( n > 0 )
    {
        unsigned int len = n;
        if( len > 16 )
            len = 16;
        n -= 16;
    }
    return 0;
}
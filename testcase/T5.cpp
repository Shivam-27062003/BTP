int __VERIFIER_nondet_int();

int main()
{
    int mask= __VERIFIER_nondet_int();
    while( ( mask & 1 ) == 0 )
    {
        mask >>= 1;
    }
    return 0;
}
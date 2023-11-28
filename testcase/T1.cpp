int __VERIFIER_nondet_int();

int main()
{

    int linesToRead = __VERIFIER_nondet_int();
    if( linesToRead < 0 )
        return 0;
    int h = __VERIFIER_nondet_int();
    while( h > 0 )
    {
        if( linesToRead > h )
            linesToRead = h;
        h -= linesToRead;
    }
    return 0;

}
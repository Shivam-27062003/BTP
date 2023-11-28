int flag = 0;
int ff_subtitles_next_line();
int __VERIFIER_nondet_int();

int main()
{
    int b = __VERIFIER_nondet_int();
    int end = __VERIFIER_nondet_int();
    if( b < 0 || end < 0 )
        return 0;
    while( b < end )
    {
        b += ff_subtitles_next_line();
        if( b >= end - 4 )
        return 0;
    }
    return 0;
}
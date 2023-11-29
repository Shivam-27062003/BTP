/*
Commit Number: 71c3a97142265804d64f443bd1ddb68ac356f8a3
URL: https://github.com/XQuartz/xorg-server/commit/71c3a97142265804d64f443bd1ddb68ac356f8a3
Project Name: xorg-server
License: MIT
termination: false
When mask = 0 , it will be non-terminating.
*/
int __VERIFIER_nondet_int();
int main()
{
    int mask= __VERIFIER_nondet_int();
    int o_mask = mask;
    while( ( mask & 1 ) == 0 )
    {
        mask >>= 1;
__CPROVER_assume(!(mask==0));

__CPROVER_assert(!(o_mask==mask),"OK");
        o_mask = mask;
    }
    return 0;
}
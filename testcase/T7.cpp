/*
Commit Number: c44da115063bfea7ef8b2afd1c9d52737e2b7f70
URL: https://github.com/coreutils/coreutils/commit/c44da115063bfea7ef8b2afd1c9d52737e2b7f70
Project Name: coreutils
License: GPL3
termination: false
This program includes shift overflow : a1 << 31 and bit operation;
This program is non-terminating, when a0 =0 and a1 = 0.
*/
int __VERIFIER_nondet_int();
int main()
{
    int a0 = __VERIFIER_nondet_int();
    int a1 = __VERIFIER_nondet_int();
    int o_a0 = a0,o_a1 = a1;
    while( ( a0 & 1 ) == 0)
    {
        a0 = ( a1 << 31 ) | ( a0 >> 1 );
        a1 = a1 >> 1;
        
__CPROVER_assume(!(a0==-268435455 && a1==0));

__CPROVER_assume(!(a0==-2147483648 && a1==-1));

__CPROVER_assume(!(a0==0 && a1==0));

__CPROVER_assume(!(a0==128 && a1==0));

__CPROVER_assume(!(a0==-1073741824 && a1==0));

__CPROVER_assume(!(a0==-1073741696 && a1==0));

__CPROVER_assume(!(a0==-1073741760 && a1==0));

__CPROVER_assume(!(a0==-1073741632 && a1==0));

__CPROVER_assume(!(a0==-1073741440 && a1==0));

__CPROVER_assume(!(a0==-1073741568 && a1==0));

__CPROVER_assume(!(a0==-1073741056 && a1==0));

__CPROVER_assume(!(a0==-1073741312 && a1==0));

__CPROVER_assume(!(a0==-1073741184 && a1==0));

__CPROVER_assume(!(a0==-1073740928 && a1==0));

__CPROVER_assume(!(a0==-1073739904 && a1==0));

__CPROVER_assume(!(a0==-1073740416 && a1==0));

__CPROVER_assume(!(a0==-1073740288 && a1==0));

__CPROVER_assume(!(a0==-1073740544 && a1==0));

__CPROVER_assume(!(a0==-1073741504 && a1==0));

__CPROVER_assume(!(a0==-1073740992 && a1==0));

__CPROVER_assume(!(a0==384 && a1==0));

__CPROVER_assume(!(a0==-1073741120 && a1==0));

__CPROVER_assume(!(a0==-1073741376 && a1==0));

__CPROVER_assume(!(a0==-1073740800 && a1==0));

__CPROVER_assume(!(a0==-1073740032 && a1==0));

__CPROVER_assume(!(a0==-1073741248 && a1==0));

__CPROVER_assume(!(a0==-1073740864 && a1==0));

__CPROVER_assume(!(a0==-1073740160 && a1==0));

__CPROVER_assume(!(a0==-1073739840 && a1==0));

__CPROVER_assume(!(a0==-1073740672 && a1==0));

__CPROVER_assert(!(o_a0==a0,o_a1==a1),"OK");
        o_a0 = a0,o_a1 = a1;
    }
    return 0;
}
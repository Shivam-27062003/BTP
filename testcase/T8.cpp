/*
Commit Number: 5bec3fff0bac50f4b4d4d3b02e70161a2bf38d0f
URL: https://github.com/brltty/brltty/commit/5bec3fff0bac50f4b4d4d3b02e70161a2bf38d0f
Project Name: brltty
License: LGPL-2.1
termination: false
This program will go into an infinite loop if wc is negative
*/
int __VERIFIER_nondet_int();
int main()
{
    int wc = __VERIFIER_nondet_int();
    int o_wc = wc;
    do{
__CPROVER_assume(!(wc==4194304));

__CPROVER_assume(!(wc==8388609));

__CPROVER_assume(!(wc==8388608));

__CPROVER_assume(!(wc==8388613));

__CPROVER_assume(!(wc==536871237));

__CPROVER_assume(!(wc==536871236));

__CPROVER_assume(!(wc==4259872));

__CPROVER_assume(!(wc==8519713));

__CPROVER_assume(!(wc==262146));

__CPROVER_assume(!(wc==-1));

__CPROVER_assume(!(wc==-2081));

__CPROVER_assume(!(wc==-1065224));

__CPROVER_assume(!(wc==-482688));

__CPROVER_assume(!(wc==-332928));

__CPROVER_assume(!(wc==-382848));

__CPROVER_assume(!(wc==-135));

__CPROVER_assume(!(wc==-590912));

__CPROVER_assume(!(wc==-334976));

__CPROVER_assume(!(wc==-391));

__CPROVER_assume(!(wc==-911));

__CPROVER_assume(!(wc==-536832));

__CPROVER_assume(!(wc==-403684));

__CPROVER_assume(!(wc==-602));

__CPROVER_assume(!(wc==-634));

__CPROVER_assume(!(wc==-12782641));

__CPROVER_assume(!(wc==-1658));

__CPROVER_assume(!(wc==-9595303));

__CPROVER_assume(!(wc==-1073543));

__CPROVER_assume(!(wc==-8530112));

__CPROVER_assume(!(wc==-491008));

__CPROVER_assert(!(o_wc==wc),"OK");
        o_wc=wc;
        //loop;
    }while( wc >>= 6 );
    return 0;
}
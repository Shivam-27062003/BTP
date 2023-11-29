int __VERIFIER_nondet_int();
int flag = 0;
int read( int loc , int len )
{
    int count = 0;
    if( flag == 1 ) //whether EOF or not
        return 0;
    while( loc < len )
    {
        int num =  __VERIFIER_nondet_int();
        if( num == 0 ) //abnormal
        {
            return -1;
}
        else
        {
            if( num < 0 )
                num =  -num;
            num = num % 1000;
            count++;
            if( num < 995 ) //read a char
            {
                loc++;
                continue;
            }
            else // EOF
            {
                flag = 1;
                return count;
            }
        }
    }
    return count;
}
int main()
{
    int count =__VERIFIER_nondet_int();
    if( count <= 0 )
        return 0;
    int ret;
    int buf = 0;
    int o_ret = ret,o_buf = buf,o_count = count,o_flag = flag;
    while( count > 0 )
    {
        ret = read( buf, count );
        if( ret < 0 )
            return 0;
        count -= ret;
        buf += ret;
__CPROVER_assume(!(ret==0 && count==1 && buf==4 && flag==1));

__CPROVER_assume(!(ret==0 && count==2143223807 && buf==5 && flag==1));

__CPROVER_assume(!(ret==0 && count==1 && buf==2 && flag==1));

__CPROVER_assume(!(ret==0 && count==2 && buf==4 && flag==1));

__CPROVER_assume(!(ret==0 && count==3 && buf==4 && flag==1));

__CPROVER_assume(!(ret==0 && count==1 && buf==1 && flag==1));

__CPROVER_assume(!(ret==0 && count==524284 && buf==4 && flag==1));

__CPROVER_assume(!(ret==0 && count==62 && buf==5 && flag==1));

__CPROVER_assume(!(ret==0 && count==2 && buf==5 && flag==1));

__CPROVER_assume(!(ret==0 && count==33 && buf==2 && flag==1));

__CPROVER_assume(!(ret==0 && count==1 && buf==5 && flag==1));

__CPROVER_assume(!(ret==0 && count==268435452 && buf==4 && flag==1));

__CPROVER_assume(!(ret==0 && count==256 && buf==4 && flag==1));

__CPROVER_assume(!(ret==0 && count==2 && buf==1 && flag==1));

__CPROVER_assume(!(ret==0 && count==2 && buf==2 && flag==1));

__CPROVER_assume(!(ret==0 && count==134217724 && buf==5 && flag==1));

__CPROVER_assume(!(ret==0 && count==1026 && buf==4 && flag==1));

__CPROVER_assume(!(ret==0 && count==6 && buf==1 && flag==1));

__CPROVER_assume(!(ret==0 && count==1 && buf==3 && flag==1));

__CPROVER_assume(!(ret==0 && count==536870914 && buf==1 && flag==1));

__CPROVER_assume(!(ret==0 && count==4 && buf==4 && flag==1));

__CPROVER_assume(!(ret==0 && count==268435456 && buf==2 && flag==1));

__CPROVER_assume(!(ret==0 && count==2 && buf==3 && flag==1));

__CPROVER_assume(!(ret==0 && count==4091 && buf==5 && flag==1));

__CPROVER_assume(!(ret==0 && count==268435457 && buf==1 && flag==1));

__CPROVER_assume(!(ret==0 && count==4 && buf==3 && flag==1));

__CPROVER_assume(!(ret==0 && count==9 && buf==2 && flag==1));

__CPROVER_assume(!(ret==0 && count==130 && buf==4 && flag==1));

__CPROVER_assume(!(ret==0 && count==536870912 && buf==1 && flag==1));

__CPROVER_assume(!(ret==0 && count==67108865 && buf==2 && flag==1));

__CPROVER_assert(!(o_ret==ret && o_count==count && o_buf==buf && o_flag==flag),"OK");
        o_ret=ret,o_buf=buf,o_count=count,o_flag=flag;
}
    return 0;
}
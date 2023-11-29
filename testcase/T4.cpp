int __VERIFIER_nondet_int();
int flag = 0;
int read( int , int );

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
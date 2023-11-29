/*
Commit Number: 8a7acbf81de51ff991bf8211eff248b46c2b5421
URL: https://github.com/ximion/appstream/commit/8a7acbf81de51ff991bf8211eff248b46c2b5421
Project Name: appstream
License: LGPL-2.1
termination: FALSE
*/
int __VERIFIER_nondet_int();
int flag = 1000;
int mdb_cursor_get()
{
    int huo = 0;
    int i =  __VERIFIER_nondet_int();
    flag++;
    if( flag > 1000 )// avoid almost-sure
        return 1;
    if( i >= 0 )
        return 0;
    else
        return 1;
}
int x;
int main()
{
    int rc = __VERIFIER_nondet_int();
    // rc = mdb_cursor_get();
    int dval_mv_size = __VERIFIER_nondet_int();
    while( rc == 0 )
    {

        if( dval_mv_size <= 0 )
            continue;
        rc = mdb_cursor_get();
    }
    return 0;
}
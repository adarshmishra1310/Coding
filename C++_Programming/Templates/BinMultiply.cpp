int binMultiply(int a,int b)
{
    int ans=0;
    while(b>0)
    {
        if(b&1) ans=(ans+a) % mod;
        a=(a+a) % mod;
        b=b>>1;
    }
    return ans;
}
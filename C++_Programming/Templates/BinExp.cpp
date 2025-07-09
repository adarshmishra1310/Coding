int binExp(int x,int n)
{
    int ans=1;
    while(n>0)
    {
        if(n&1) ans=ans*x;
        x=x*x;
        n=n>>1;
    }
    return ans;
}
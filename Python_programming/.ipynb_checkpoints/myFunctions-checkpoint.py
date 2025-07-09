def gcd(a,b):
    if(a==0):
        return b
    if(a<b):
        a,b = b,a
    return gcd(a-b,b)

a = int(input("Enter a:"))
b = int(input("Enter b:"))
print(gcd(a,b))
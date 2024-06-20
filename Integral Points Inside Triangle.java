class Solution {
    long InternalCount(long p[], long q[], long r[]) {
        long area = Math.abs(p[0]*(q[1]-r[1]) + q[0]*(r[1]-p[1]) + r[0]*(p[1]-q[1]));
        long b = gcd(p,q) + gcd(q,r) +gcd(r,p);
        return (area-b+2)/2;
    }
    long gcd(long a[],long b[]){
        return calculate(Math.abs(a[0]-b[0]),Math.abs(a[1]-b[1]));
    }
    long calculate(long p1,long p2){
        while(p2!=0){
            long temp=p2;
            p2=p1%p2;
            p1=temp;
        }
        return p1;
    }
};

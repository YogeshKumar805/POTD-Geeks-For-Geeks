class Solution {
  public:
    int orientation(int p[], int q[], int r[]){
        long long val=(long long)(q[1]-p[1])*(r[0]-q[0])-(long long)(r[1]-q[1])*(q[0]-p[0]);
        if(val==0) return 0;
        return (val>0)?1:2;
    }
    
    bool onsegment(int a[],int b[],int c[]){
        if((c[0]>=min(a[0],b[0])&&c[0]<=max(a[0],b[0])) && (c[1]>=min(a[1],b[1])&&c[1]<=max(a[1],b[1]))){
            return true;
        }
        else{
          return false;
        }
        
    }
    
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        // code here
        int o1=orientation(p1,q1,p2);
        int o2=orientation(p1,q1,q2);
        int o3=orientation(p2,q2,p1);
        int o4=orientation(p2,q2,q1);
        
        if(o1!=o2 && o3!=o4) return "true";
        
        if(o1==0 && onsegment(p1,q1,p2)) return "true";
        if(o2==0 && onsegment(p1,q1,q2)) return "true";
        if(o3==0 && onsegment(p2,q2,p1)) return "true";
        if(o4==0 && onsegment(p2,q2,q1)) return "true";
        
        return "false";
    }
};


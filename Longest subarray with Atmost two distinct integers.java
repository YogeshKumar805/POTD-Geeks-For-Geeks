class Solution {
    public int totalElements(int[] arr) {
            int i=0;
            int j=0;
            int n=arr.length;
            int ans=0;
            HashMap<Integer,Integer> map=new HashMap<>();
            while(j<n){
                map.put(arr[j], map.getOrDefault(arr[j],0)+1);
                if(map.size()<2){
                    j++;
                }else if(map.size()==2){
                    int k=j-i+1;
                    ans=Math.max(ans,k);
                    j++;
                }else {
                    while(i<j && j<n && map.size()>2){
                        int temp=arr[i];
                        if(map.get(temp)>1){
                            map.put(temp, map.get(temp)-1);
                        }else {
                            map.remove(temp);
                        }
                        i++;
                    }
                    
                    if(map.size()==2){
                        int k=j-i+1;
                        ans=Math.max(ans,k);
                    }
                    j++;
                }
            }
             if(map.size()==1)return map.get(arr[0]);
             else  return ans;
    }
}

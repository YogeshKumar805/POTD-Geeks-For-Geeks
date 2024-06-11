class Solution {
    public static long maxTip(int n, int x, int y, int[] arr, int[] brr) {
        
        return optimum(arr, brr, x, y, n);
        
    }
    
    // greedy
    static class Order{
        int a_tip;
        int b_tip;
        int diff;
        
        Order(int a_tip, int b_tip){
           this.a_tip = a_tip;
           this.b_tip = b_tip;
           this.diff = Math.abs(a_tip - b_tip);
        }
    }
    
    static long optimum(int arr[], int brr[], int x, int y, int n){
        
        ArrayList<Order> orders = new ArrayList<>();
        for(int i = 0; i < n; i++){
            orders.add(new Order(arr[i], brr[i]));
        }
        
        Collections.sort(orders, (o1, o2) -> Integer.compare(o1.diff, o2.diff));
        
        long ans = 0;
        for(int i = n - 1; i >= 0; i--){
            Order o = orders.get(i);
            if((o.a_tip >= o.b_tip && x > 0) || y <= 0){
                ans += o.a_tip;
                x--;
            }else{
                ans += o.b_tip;
                y--;
            }
            
        }
        
        return ans;
    }
    
}

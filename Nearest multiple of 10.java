class Solution {
    String roundToNearest(String str) {
        // Complete the function
        StringBuilder sb = new StringBuilder();
        int i = str.length()-2;
        int carry = 0;
        if(str.charAt(i+1) > '5'){
            carry = 1;
        }
        sb.append("0");
        while(i>=0 || carry == 1){
            int sum = carry;
            if(i>=0){
                sum += str.charAt(i) - 48;
            }
            sb.append(String.valueOf(sum%10));
            carry = sum / 10;
            i--;
        }
        return sb.reverse().toString();
    }
}

class Solution {
    /**
    * @param string str
    * @param number k

    * @returns boolean
    */
    kPangram(str, k) {
        // code here
        let cnt = 0;
        const arr = new Array(26).fill(0)
        
        for(let i = 0; i < str.length; i++){
            if(str[i] == ' ') continue
            const idx = str.charCodeAt(i) - 97
            arr[idx]++
            cnt++
        }
        
        // console.log(arr, cnt, str.length)
        if(cnt < 26) return false
        
        cnt = 0
        for(const el of arr){
            if(el == 0) cnt++
        }
        return cnt <= k
    }
}

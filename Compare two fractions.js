class Solution {
    /**
    * @param string str

    * @returns string
    */
    compareFrac(str) {
        // code here
        let resp;
        
        let arr = str.replace(' ', '').split(',');
        
        return  (eval(arr[0]) === eval(arr[1])) ?  'equal' : ((eval(arr[0]) > eval(arr[1])) ? arr[0] : arr[1]);
    }
}

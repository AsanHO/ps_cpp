function solution(arr, k) {
    const isDecimal = k%2 ==0
    return arr.map((e)=>{
        if (isDecimal){
            return e+k;
        }
      return e*k;
    })
}
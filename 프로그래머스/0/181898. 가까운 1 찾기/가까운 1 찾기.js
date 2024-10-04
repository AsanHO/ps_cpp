function solution(arr, idx) {
    var answer = 0;
    arr = arr.map((e,i)=>{
            if (i<idx){
                return 0;
            }
            return e;
            });
    console.log(arr);

    return arr.indexOf(1);
}
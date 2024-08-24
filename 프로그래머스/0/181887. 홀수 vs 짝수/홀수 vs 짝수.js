function solution(num_list) {
    let isOdd = true;
    let oddSum = 0;
    let evenSum = 0;
    for (num of num_list){
        if (isOdd) {
            oddSum += num;
        }else{
            evenSum += num;
        }
        isOdd = !isOdd;
    }
    return oddSum >= evenSum ? oddSum : evenSum;
}
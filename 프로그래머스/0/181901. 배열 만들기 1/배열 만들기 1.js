function solution(n, k) {
    var answer = [];
    let number = 1;
    while (n >= number*k){
        answer.push(number*k);
        number += 1;
    }
    return answer;
}
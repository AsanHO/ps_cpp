function solution(numbers, n) {
    answer = 0;
    for (num of numbers){
        console.log(num);
        answer += num;
        if (answer > n) return answer;
    }

}
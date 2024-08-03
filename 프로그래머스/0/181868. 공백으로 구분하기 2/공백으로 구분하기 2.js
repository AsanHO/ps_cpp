function solution(my_string) {
    let answer = my_string.split(' ');
    answer = answer.filter(function(e) { return e !== '' });
    return answer;
}
function solution(my_string, index_list) {
    var answer = '';
    for (index of index_list){
        answer += my_string[index];
    }
    return answer;
}
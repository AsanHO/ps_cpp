function solution(num_list, n) {
    var answer = [...num_list.slice(n,num_list.length),...num_list.slice(0,n),];
    return answer;
}
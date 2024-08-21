function solution(arr, delete_list) {
    var answer = [];
    for (target of arr){
        if (!delete_list.includes(target)){
            answer.push(target)
        }
    }
    return answer;
}
function solution(todo_list, finished) {
    let answer = [];
    for (i = 0; i < finished.length; i++){
        const result = finished[i];
        if (!result){
            answer.push(todo_list[i]);
        }
    }
    return answer;
}
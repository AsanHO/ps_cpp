function solution(names) {
    var answer = [];
    let count = 5;
    for (i=0; i<names.length ;i++){
        if (count == 5){
            answer.push(names[i]);   
            count = 1;
            continue;
        }
        count +=1;
    }
    return answer;
}
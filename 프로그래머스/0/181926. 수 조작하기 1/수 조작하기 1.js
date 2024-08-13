function solution(n, control) {
    var answer = n;
    for (char of control){
        if (char == "w"){
            answer += 1;
        }
        if (char == "s"){
            answer -= 1;
        }
        if (char == "d"){
            answer += 10;
        }
        if (char == "a"){
            answer -= 10;
        }
        
    }
    return answer;
}
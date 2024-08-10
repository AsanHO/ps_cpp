function solution(my_string, is_prefix) {
    var answer = 0;
    for (i=0;i<is_prefix.length;i++){
        if(my_string[i] == is_prefix[i]){
            answer = 1;
        }else{
            answer = 0;
            break;
        }
    }
    return answer;
}
function solution(strArr) {
    var answer = [];
    for(let i = 0; i<strArr.length;i++) {
        let newStr = "";
        if (i % 2 === 0){
            newStr = strArr[i].toLowerCase();
        }else{
            newStr = strArr[i].toUpperCase();
        }
      answer.push(newStr);
    }
    return answer;
}
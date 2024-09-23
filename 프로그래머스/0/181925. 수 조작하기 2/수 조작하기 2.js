function solution(numLog) {
    let result = ""
    let curNum = numLog.shift();
    for (num of numLog){
        switch (num-curNum) {
            case 1:
                result += "w";
                break;
            case 10:
                result += "d";
                break;
            case -1:
                result += "s";
                break;
            case -10 :
                result += "a";
                break;
        }
        curNum = num;
    }
    return result;
    
}
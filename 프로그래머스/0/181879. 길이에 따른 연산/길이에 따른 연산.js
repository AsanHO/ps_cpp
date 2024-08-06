function solution(num_list) {
    result = 0;
    if (num_list.length > 10){
        num_list.forEach((e) => result += e);
    }else{
        result =1;
        num_list.forEach((e) => result *=e);
    }
    return result;
}
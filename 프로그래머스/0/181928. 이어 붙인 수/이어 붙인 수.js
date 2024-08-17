function solution(num_list) {
    
    let num1 = "";
    let num2 = "";
    for (num of num_list){
        if(num % 2 !==0){
            num1 += num.toString();
        }else{
            num2 += num.toString();
        }
    }
    return num1*1+num2*1;
}
function solution(num_list, n) {
    for (num of num_list){
        if (num == n){
            return 1;
        }
    }
    return 0;
}
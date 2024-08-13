function solution(num_list) {
    const last = num_list[num_list.length-1];
    const forwardLast = num_list[num_list.length-2];
    last > forwardLast ?num_list.push(last-forwardLast):num_list.push(last*2);
    return num_list;
}
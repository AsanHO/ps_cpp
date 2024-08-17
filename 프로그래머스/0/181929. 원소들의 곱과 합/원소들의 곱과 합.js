function getmulti(num_list){
    return num_list.reduce((accumulator, currentValue) => accumulator * currentValue, 1);
}
function getSumSqr(num_list){
    return num_list.reduce((accumulator, currentValue) => accumulator + currentValue, 0)**2;
}
function solution(num_list) {  
    return getmulti(num_list) < getSumSqr(num_list) ? 1:0;
}

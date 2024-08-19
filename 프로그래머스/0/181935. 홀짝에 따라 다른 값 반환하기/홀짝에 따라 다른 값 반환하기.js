function hol(n){
    let sum = 0;
    for (i=1;i<=n;i+=2){
        sum+=i;
    }
    return sum;
}
function zzac(n){
    let sum = 0;
    for (i=2;i<=n;i+=2){
        sum+=i**2;
    }
    return sum;
}
function solution(n) {
    const answer = n % 2 ==0?zzac(n):hol(n);
    return answer;
}
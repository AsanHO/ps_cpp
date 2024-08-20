function solution(a, b) {
    const num1 = Number(a+""+b);
    const num2 = Number(b+""+a);
    return num1 >= num2 ? num1 :num2 ;
}
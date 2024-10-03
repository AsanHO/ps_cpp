function solution(numbers) {
    // 1. 음수중에서 최댓값 나오는 경우
    // 2. 양수중에서 최댓값 나오는 경우
    // 3. 수개 2개인경우
    if (numbers.length == 2){
        return numbers[0]*numbers[1];
    }
    negas = numbers.filter((a)=>a<0);
    numbers.sort((a, b) => a - b);
    negas.sort((a, b) => a - b);
    
    nega = negas.length > 1 ? (negas[0]*negas[1])??0 : 0;
    console.log(numbers);
    posi = numbers[numbers.length-1]*numbers[numbers.length-2]
    console.log(nega,posi);
    return posi > nega ? posi : nega;
}
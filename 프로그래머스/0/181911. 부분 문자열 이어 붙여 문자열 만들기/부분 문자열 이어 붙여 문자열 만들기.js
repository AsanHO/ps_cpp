function solution(my_strings, parts) {
    var answer = '';
    for (let [index, word] of my_strings.entries()) {
        const part = word.slice(parts[index][0],parts[index][1]+1);
        answer+=part
    }
    return answer;
}
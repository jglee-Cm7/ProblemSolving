function solution(s) {
    let arr = s.split(" ");
    let mx = Math.max(...arr);
    let mn = Math.min(...arr);
    let answer = `${mn} ${mx}`;
    return answer;
}
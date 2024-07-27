# ProblemSolving

- 언제나 범위 조심.!
- error test 충분히 잘하자.

## Check

### greedy
Greedy는 그냥 일단 드리박는게 중요.

- 13305
- 1931

### Dynamic Programming
 - 2839
   - -1 대신 INF값을 넣어서 min 값 판별 잘하게 하는 편법이 좋았다.
 - 2579
   - 문제를 잘 읽자.. 연속된 3개의 계단이라는 말은 1칸을 2번 오르는 행위도 안된다는 것이다..
 - 11053
   - N^2이더라도 그냥 풀어볼것.
 - 11055
   - 매번 다 비교하는 것도 괜찮다.? 1억번 안넘으면 N^2 의심해보셈
   - *max_element(DP.begin(), DP.end())
 - 9465
   - dp를 2개 만들어서 하는 게 좋음
 - 1890
   - for문 두개로 차례대로 계산해도 문제없
 - 2156
   - 점화식을 잘세워야해 XO or XOO로 생각먼저하자

### Two Pointers
 - 20922
   - 포인터 두개 쓴다. start, end

### Graph
 - 1324
   - memset(vis, false, sizeof(vis));
   - *max_element(counts + 1, counts + 1 + size);
     - 1번째부터 셀 때는 마지막 사이즈 착각하면 안됨
   - 그리고 다 전부 체크하는 쪽이 맞다. (중간에 사이클이라던지, 다른 형태의 트리로 계산 틀림)

### Binary Search
 - 19 < S < 20 인경우
   - l = 19, r = 20
   - l = 19, r = 19
   - l = 20, r = 19
   - 가 되게 조건문을 짜자.
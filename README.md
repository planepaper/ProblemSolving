# ProblemSolving

- 언제나 범위 조심.!
- error test 충분히 잘하자.

## Check

### array
- 2로 나누는 올림시에는 ceil 함수보다 그냥 (n+1)/2가 효율적
- vector는 크기를 넘어서면 전체 크기를 재할당함. 

### dfs & bfs
- dfs : 스택 or 재귀
  - 스택 넣어놓음과 동시 방문처리
- bfs : 큐
  - 큐에 갈 장소 넣어놓고 
### list
- 삽입삭제후 커서 어디에 위치하는지 알아야함.
  - insert는 해당 커서 위치의 전에다가 삽입함.
    - A B C 가 있는 곳에서 B가 가리키는 곳에 insert 호출시
      - A D B C 가 되고. 커서는 여전히 B를 가리킴
- queue는 크기 넘어서면 전체 크기를 재할당하지 않고 적당히 메모리블록을 할당후, 거기에 채워넣음

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

### stack
 - 1874
   - vector.data()로 전체 출력가능
 - ⭐2493 : 너무 좋은 문제. 
   - 정방향 순회 한 번만으로 풀어봐라 (hint: 팬케이크)
   - pair 코드로 보기 좋다.
   - { 1, 1 }로 단순히 pair 선언 가능
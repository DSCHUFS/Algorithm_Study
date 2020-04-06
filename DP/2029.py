'''
집합의 개수
DP문제

1. 파이썬으로 푸는건 매우 비추천...
2. C언어 코드도 추가함.

'''
#10000000으로 나누라고 해서 만들어 놓은 값
MOD = 10**6
#파이썬에서 인풋값 직접 전달을 위해 쓰는 코드이니 무시하셔도 됩니다.
import sys
input = sys.stdin.readline

#변수를 입력받습니다.
t, a, s, b = map(int, input().split())
arr = list(map(int, input().split()))


dp = [0] * (t + 1)

'''
우리가 가진 숫자들의 모음이 각 1, 2, 3 별로 몇개씩 있는지
나타내기 위한 DP입니다.
'''
for i in arr:
    dp[i] += 1


'''
ar배열이 결국은 res배열인데,
집합의 갯수가 0개인 경우는 1가지 경우뿐임.
'''
ar = [1]

for k in dp:
    #해당 숫자가 없으면 당연히 반복문의 처음으로 돌아갑니다.
    if k == 0:
        continue
    '''
    k = 개별 함수의 최대 길이
    len_arr + k - 1 = 현재 나올 수 ar의 최대함수 길이 
    ex) 예제에서는 5개가 된다.
    br = ar에 추가해줄 임시 list
    r = br에 추가할 임시 함수의 개수
    변수가 중요하게, 구조가 조금 복잡합니다.
    이유는 파이썬이다보니 런타임 아웃이 너무 많이 발생해서 
    연산횟수를 줄이기 위해서 많은 변수를 호출했습니다.
    '''
    k += 1
    len_arr = len(ar)
    br = []
    r = 0

    for i in range(len_arr + k - 1):
        if i < len_arr:
            r += ar[i]
            #미리 MOD를 안하면 마지막에
            #연산오류 제거를 위해 미리 값을 빼줌.(값이 너무 커서)
            if r >= MOD:
                r-= MOD
        if i >= k:
            r -= ar[i - k]
            #비슷한 이유로 연산오류 제거를 위해
            #미리 값을 더해 줌(값이 너무 작아서)
            if r < 0:
                r += MOD
        #함수가 n개일 때, 나오는 r값을 br에 append 해준다.
        br.append(r)
    #매 반복마다, n개의 함수의 개수를 갱신해준다.
    ar = br

#파이썬식 연산.
print(sum(ar[s:b+1]) % MOD)


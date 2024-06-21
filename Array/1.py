def reverse_sublist(lst, start, end):
    while start < end:
        lst[start], lst[end] = lst[end], lst[start]
        start += 1
        end -= 1


def process_sequence(n, sequence, flip_info):
    for start, end in flip_info:
        reverse_sublist(sequence, start, end)
    return sequence


# 입력 예시 1
n = 10
sequence = [3, 81, 9, 12, 0, -9, 36, 33, 91, 10]
flip_info = [(3, 7), (4, 5), (0, 4)]

# 입력 예시 2
# n = 6
# sequence = [30, 10, 20, 0, 40, 50]
# flip_info = [(1, 2), (0, 3)]

# 뒤집기 정보 처리
result_sequence = process_sequence(n, sequence, flip_info)

# 결과 출력
print(" ", end="")
print(" ".join(map(str, result_sequence)))

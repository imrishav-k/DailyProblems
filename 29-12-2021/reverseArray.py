arr = [1,2,3,4,5,6]

def reverseArrIterative(arr):
    start = 0
    end = len(arr) - 1
    while start<end:
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1

def reverseArrRecursive(arr, start, end):
    if start>end:
        return
    arr[start], arr[end] = arr[end], arr[start]
    reverseArrRecursive(arr, start+1, end-1)

print(arr)
reverseArrRecursive(arr, 0, len(arr) - 1)
print(arr)
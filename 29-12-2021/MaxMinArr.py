class Pair:
    def __init__(self):
        self.min = 0
        self.max = 0

def getMinMax(arr:list, n:int) -> Pair:
    minmax = Pair()

    if n == 1:
        minmax.min = arr[0]
        minmax.max = arr[1]
        return minmax
    if arr[0] > arr[1]:
        minmax.min = arr[1]
        minmax.max = arr[0]
    else:
        minmax.min = arr[0]
        minmax.max = arr[1]

    for i in range(2, n):
        if arr[i]<minmax.min:
            minmax.min = arr[i]
        elif arr[i]>minmax.max:
            minmax.max = arr[i]
    return minmax

if __name__ == "__main__":
    arr = [1000, 11, 445, 1, 330, 3000]
    minmax = getMinMax(arr, len(arr))
    print(f"minimum : {minmax.min}")
    print(f"maximum : {minmax.max}")
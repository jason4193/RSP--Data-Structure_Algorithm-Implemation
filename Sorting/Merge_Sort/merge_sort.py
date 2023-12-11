import random

def merge(array, h, mid, e):
    buffer_1 = []
    buffer_2 = []
    for i in range(h,mid+1):
        buffer_1.append(array[i])
    for i in range(mid, e):
        buffer_2.append(array[i+1])
    
    print(f'Buffer1 {buffer_1}\nBuffer2 {buffer_2}')    
    c = h
    while len(buffer_1) != 0 and len(buffer_2) != 0:
        if buffer_1[0] <= buffer_2[0]:
            array[c] = buffer_1[0]
            buffer_1.remove(buffer_1[0])
            c += 1
        else:
            array[c] = buffer_2[0]
            buffer_2.remove(buffer_2[0])
            c += 1
    while len(buffer_1) != 0:
        array[c] = buffer_1[0]
        buffer_1.remove(buffer_1[0])
        c += 1
    while len(buffer_2) != 0:
        array[c] = buffer_2[0]
        buffer_2.remove(buffer_2[0])
        c += 1

def merge_sort(array, h, e):
    if (h < e):
        mid = int((h+e)/2)
        merge_sort(array, h, mid)
        merge_sort(array, mid+1, e)
        print(f"{h},{mid},{e}")
        merge(array, h, mid, e)

size = 4
array = [random.randint(0, size) for i in range(size)]
print(array)


merge_sort(array, 0, size-1)
print(array)


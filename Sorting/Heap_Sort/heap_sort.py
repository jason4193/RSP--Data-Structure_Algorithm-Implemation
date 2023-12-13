def heapify(arr, n, i):
    # Initialize smallest as root
    smallest = i

    # Left child
    l = 2 * i + 1
    # Right child
    r = 2 * i + 2

    # Check left child < root
    if l < n and arr[l] < arr[smallest]:
        smallest = l

    # Check right child < root
    if r < n and arr[r] < arr[smallest]:
        smallest = r

    # Change root if needed
    if smallest != i:
        arr[i], arr[smallest] = arr[smallest], arr[i]
        # Heapify the root
        heapify(arr, n, smallest)
    


def heap_sort(arr):
    N = len(arr)

    # Min heap tree
    for i in range(N//2 - 1, -1, -1):
        heapify(arr, N, i)

    # Extract elements from heap
    for i in range(N-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

# Driver code
arr = [12, 11, 13, 5, 6, 7]
print(arr)
heap_sort(arr)
print(arr)









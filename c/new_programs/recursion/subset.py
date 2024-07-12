def print_subsets(arr):
    n = len(arr)
    for i in range(2**n):
        subset = []
        for j in range(n):
            if (i & (1 << j)) > 0:
                subset.append(arr[j])
        print(subset)

my_set = [1, 2, 3]
print_subsets(my_set)


def quickSort(array):
    if len(array) < 2:
        return array
    else:
        pivot = array[0]
        less = [i for i in array[1:] if i < pivot]
        greater = [i for i in array[1:] if i >= pivot]

        return quickSort(less) + [pivot] + quickSort(greater)


def main():
    print(quickSort([10,10,5,2,3]))

if __name__ == "__main__":
    main()
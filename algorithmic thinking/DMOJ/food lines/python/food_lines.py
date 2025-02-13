from array import array
import sys
import os

        
def main():
    n, m = input().split(" ")
    n, m = int(n), int(m)
    queues = array('b', (int(ppl_num) for ppl_num in input().split()))
    for i in range(m):
        index_min = min(range(len(queues)), key=queues.__getitem__)
        print(queues[index_min])
        queues[index_min] += 1


if __name__ == "__main__":
    print(os.getcwd())
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open("output.txt", 'w')
    main()
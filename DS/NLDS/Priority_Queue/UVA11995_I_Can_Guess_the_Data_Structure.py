import sys
import heapq
import queue


def rl():
    return sys.stdin.readline().strip()


def rn():
    return list(map(int, sys.stdin.readline().split()))


if __name__ == '__main__':
    cas = 0
    for line in sys.stdin:
        cas += 1
        line = line.strip()
        n = int(line)
        stack = []
        heap = []
        queue_tab = queue.Queue()
        status = [1] * 3
        no2 = True
        for _ in range(n):
            op, val = map(int, rn())
            if op == 1:
                stack.append(val)
                heapq.heappush(heap, -val)
                queue_tab.put(val)
            else:
                out_stack, out_heap, out_queue = -1, -1, -1
                no2 = False
                if stack:
                    out_stack = stack.pop()
                if heap:
                    out_heap = -heapq.heappop(heap)
                if not queue_tab.empty():
                    out_queue = queue_tab.get()
                if out_stack != val:
                    status[0] = 0
                if out_heap != val:
                    status[1] = 0
                if out_queue != val:
                    status[2] = 0
        unsure = sum(status)
        if unsure >= 2:
            print('not sure')
        elif unsure == 0:
            print('impossible')
        elif status[0] == 1:
            print('stack')
        elif status[1] == 1:
            print('priority queue')
        elif status[2] == 1:
            print('queue')

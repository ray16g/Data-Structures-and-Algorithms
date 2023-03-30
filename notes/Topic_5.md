# Topic 5

## Heap

### Rules of a heap
- It is a binary tree
- It is complete

### Rules of a max heap
- Key of parent >= Key of child for all nodes
- Max heap is a heap

### Rules of a min heap
- Key of child >= Key of parent for all nodes
- Min heap is a heap

### Heapify
- subscript of the last non-leaf node is ceil((n-1)/2)
    - for last non-leaf subscript to root
        - call downheap
- int idx{ (n - 1) >> 1}
- idx += (((n-1) & 1)) ? 1 : 0;
# Description

Implementations of various datastructrues as described in Open Data Structures (in C++) by Pat Morin [http://opendatastructures.org/ods-cpp.pdf](http://opendatastructures.org/ods-cpp.pdf).

There are some modifications from the implementations described by Morin. For example, the Array member of ArrayStack is private here, so the DualArrayDeque can't modify that data directly.


## Interfaces

### Queue, Stack, Deque

  - add(x)/enqueue(x)
  - remove()/dequeue()

### List

  - size()
  - get(i)
  - set(i,x)
  - add(i,x)
  - remove(i)

### USet

  - size()
  - add(x)
  - remove(x)
  - find(x)

### SSet

  - size()
  - add(x)
  - remove(x)
  - find(x) return smallest element that is greater than or equal to x

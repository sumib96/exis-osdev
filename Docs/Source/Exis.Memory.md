# Managing Operational Memory
BLOCK CHAIN+!++!!! MINI FS

## Allocators

### Bump (Static)
Simple, allocating memory continuously, and we free all the allocated memory if we want.
We dont need single deallocation here, bcs nonsense.
### Pool (Free List)
We allocate memory, store the information of free blocks, we can reallocate / free any allocated area,
and using an algorithm to decide what free memory blocks we should allocate (Best - Worts - First fit).
Problems: Fragmentation, depends on the allocation method used.
### Heap Allocators (Kernel Root Allocator)
Should have functions for Reallocation, Zeroing memory, can be dynamic allocator.
### Dynamic Allocator
Other name (Virtual Memory Manager), obviously transparent for the User Space or upper priv. level, slow,
but fragmentation should be totally solved, used allocations can be reallocated if needed for any allocation,
may works with Virtual Address Space (Paging).
### Slab Allocator
Using a determined block size for Structs / Variables / Data, may use those Sizes (any possible) for Allocation,
we will never have problem with Fragmentation on freed blocks, but have to built with the Task itself.

## Memory Allocator Principles for Optimalizations
- We should have never touch the Base Address of an allocated space what currently being used (Killer)
- Never copy any memory block in Allocation or Freeing time (Killer)
- But, these 2 things will cause a new problem: Fragmentation (We can run out of memory)

## The Fragmentation Problem
- Try to find what fits the best:
Can be fucking slow if we manage too much small allocations, or too big memory area of any sizes)
- Try use blocks, at the same size, (List or Block chains iteration faster bcs the Block Size makes the whole thing
maximal block number is not that big), but makes the allocations use false memory, we have to test this method with different block sizes
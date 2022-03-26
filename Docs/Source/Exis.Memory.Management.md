## Operational Memory Management
### The Basic Idea
If the physical memory splitted to physical frames (Pages), and the frame has a size (4K, or any), then if
I use a Bitmap for storing the frame allocation data, the size it takes is minimal, also we can easily
calculate how much space the Bitmap takes. The general use of this Physical Frame Allocator, to provide
frames and track them for the advanced kernel functionality, and portable for micro systems, where we have
little memory in the computer (Note that: I didnt determine what is "Memory", really should be by architectural
meaning, because if something called "General", that is applicable for any type of memory).

### Calculations
The addressable 64 bit physical memory size is really big (and doesnt matter due to design limitations of x86), also I have to prepare the future use, of N bit CPU.
The memory can be splitted up to pages. The page size used mostly is 4K, which equals 4096 bytes, which equals? 32768 bits. It means we can store 32768 - 1 frames with a Bitmap, because one is used by the Bitmap itself, which is exatly 1 frame too.

- If PageFrameSize = 4K (32768) Then PhysicalMemorySize / 4K (327680) = BitmapSize, right?
- BitmapSize / 4K = Number of the unusable 4K frames what bitmap takes, right?
- Note: Check, the full physical memory size must be divisable to integer with 4K, otherwise realign the memory layout somehow (yes the physical memory always aligned to frames, right? general by the way, but can I trust?)

This makes an easy frame allocator, which can work with any size of frames in theory. Just recalculate with 2MB, or 1K, whatever.

### Visuals
```
                Frame Size 4K
     ________ ________ ________ _______
    |   1    |   2    |    3   |  32768 ...
    |  Frame | Bitmap |        |
    |________|________|________|_______
                 |
                 |        ____________________
                  -----> |  1, 2, 3 ... 32768 |
                         |                    |
                         |  Bits for storing  |
                         |  allocated frames  |
                         |____________________|
```

### Implementation


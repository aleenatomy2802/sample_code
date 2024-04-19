
## Search Algorithm:
- Binary Search: Time Complexity?
    - Precondition: 
        - Sorted array or vector (over head)
    - Logic
    function binary_search(array, value)
        if (array.size == 0): 
            return -1

        left = 0
        right = arr size - 1

        while (left <= right)
            midpoint = left + (right-left) / 2
            if array[midpoint] == value:
                return midpoint
            
            if array[midpoint] < value:
                // go right
                left = mid + 1
            
            else 
                // go left
                right = mid - 1

        return -1



- Linear Search: Time Complexity O(n)
```cplus
for (){
    for(){ //O(n^2)
        for() //O(n^3)
        { do st} 
    }
}
```
## Tree Questions:


### Tree Traversal
    - Depth First Search (Constructing the list, Code)
    - Bread First Search 
```
`-- Graph/
    `-- Tree/
        `-- Binary Tree/ (balance, complete, B(n)<=1)
            |-- Traversal/
            |   |-- Bread First Traversal
            |   `-- Depth First Traversal/
            `-- Binary Search Tree/ (left data < right data)
               |-- Traversal/
               |   |-- Bread First Traversal
               |   `-- Depth First Traversal/
               |       |-- In-order Traversal: Left - Root - Right (LEFT, DATA, RIGHT) (SORTED LIST)
               |       |-- Pre-order Traversal: Root - Left - Right (DATA, LEFT, RIGHT)
               |       `-- Post-order Traversal: Left - Right - Root (LEFT, RIGHT, DATA)
               `-- AVL Tree/ (left data < right data; self rotation)
                  |-- Traversal/
                  |   |-- Bread First Traversal
                  |   `-- Depth First Traversal
                  `-- Tree Rotations/ (B(n)>1)
                     |-- Left Heavy/
                     |  |-- Right Rotation (-2,-1)
                     |  `-- Left-Right Rotation
                     `-- Right Heavy/
                        |-- Left Rotation
                        `-- Right-Left Rotation
```
Hashing:
## What is Hashing:

Hashing is a process used to transform a given input (or 'message') into a fixed-size string of bytes. The output, known as the hash value, digest, or hash code, typically is a sequence of numbers and letters that uniquely represents the input data. Hashing is used in various applications like data retrieval, integrity verification, and cryptography. 

Questions:
- Dictionary (key:{value} machenisim) varient of hashing put a key (string) into a hash function to create a location in memory
- Understand what is a hash function
- Why it can achive O(1)
- Collision detection and handling (pseudocode)
- Why use prime number for hashing
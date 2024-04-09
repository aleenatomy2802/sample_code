# Hashing

## What is Hashing:

Hashing is a process used to transform a given input (or 'message') into a fixed-size string of bytes. The output, known as the hash value, digest, or hash code, typically is a sequence of numbers and letters that uniquely represents the input data. Hashing is used in various applications like data retrieval, integrity verification, and cryptography. 

A hash function has certain important properties:
1. **Deterministic**: The same input will always produce the same output.
2. **Fast computation**: The hash value is quick to calculate for any given input.
3. **Non-invertible**: It should be computationally infeasible to reverse the process and recreate the input data from its hash value.
4. **Collision-resistant**: It should be unlikely for two different inputs to produce the same output hash.

**Use Case**: Hashing is primarily used for securely storing data like passwords. When a password is hashed, the hash value is stored instead of the plaintext password. Upon authentication, the provided password is hashed again, and the resulting hash is compared with the stored hash.

Here's a simple example of a hashing algorithm in C++ that uses a basic hash function to convert a string into an integer hash value.

```cpp
#include <iostream>
#include <string>

unsigned long simpleHash(const std::string& input) {
    unsigned long hash = 0;
    for(char c : input) {
        hash = hash * 31 + c;
    }
    return hash;
}

int main() {
    std::string data = "Hello, world!";
    unsigned long hashValue = simpleHash(data);
    std::cout << "Hash Value: " << hashValue << std::endl;
    return 0;
}
```

This function iterates over each character in the input string, combining its ASCII value into a cumulative hash value. The choice of `31` as a multiplier is somewhat arbitrary but is a commonly used prime number in hashing algorithms to reduce the chance of collisions.

## Hashing vs. Encryption:

Hashing and encryption are both techniques used in the field of cryptography, but they serve different purposes and operate in distinct ways:

- **Encryption** is designed to securely encode information, making it unreadable without the correct decryption key. Its purpose is to ensure confidentiality. Encryption is a reversible process; given the correct key, the original data can be retrieved from the encrypted content.

- **Hashing**, on the other hand, is used to verify the integrity or authenticity of data. It is a one-way function that converts any size input into a fixed-size output. Unlike encryption, hashing is designed to be irreversible; you cannot obtain the original input from the hash value.

While both hashing and encryption add layers of security, they do so in different contexts. Encryption is about securing data against unauthorized access, while hashing is about validating the integrity of data, ensuring it has not been altered.

Hashing and salting are both techniques used in the process of storing and verifying data, especially passwords, securely. Although they are used together for enhancing security, they serve different purposes and function in complementary ways.

## Salting

- **Purpose**: Salting is a technique used in conjunction with hashing to enhance security. A salt is a random value that is added to the input of a hash function (e.g., a password) before the hash is computed.
- **Properties**: The salt is unique for each use of the hash function, typically unique for each user's password. It is stored in plaintext alongside the hash value in the database. The same password by two different users or the same user at two different times will produce different hash values due to different salts.
- **Use Case**: Salting prevents attackers from using precomputed dictionaries of hashed values (rainbow tables) to crack passwords. It also ensures that if two users have the same password, their hash values will be different due to the unique salts, making it harder for attackers to guess passwords based on hash values.

### Hashing vs. Salting: The Relationship

- **Integration**: Salting and hashing are often used together. First, a unique salt is generated and added to the plaintext password. Then, this salted password is passed through a hash function, and the resulting hash (along with the salt) is stored in the database.
- **Security Enhancement**: While hashing provides a basic level of security by obscuring the plaintext, salting adds an extra layer by making each hash unique. This approach significantly increases the difficulty of cracking passwords through brute force or precomputed attacks.

In summary, while hashing is the fundamental process of converting plaintext into a secure format, salting is an additional step that enhances the security of the hashed data by ensuring that the output is unique even for identical inputs. Together, they provide a robust mechanism for securing sensitive data like passwords.

## Simple Encryption and Decryption with Caesar Cipher

Below is a simple example of encryption and decryption in C++ using a basic and not secure method known as the Caesar cipher for demonstration purposes. For actual security purposes, you should use established libraries and algorithms like AES, RSA, or libraries that handle these securely.

The Caesar cipher is a substitution cipher that shifts the characters of the plaintext by a fixed number of positions down the alphabet. This shift value acts as the key. For simplicity, this example will only work with lowercase letters and will not include salting or hashing since they're not applicable to reversible encryption/decryption processes.

```cpp
#include <iostream>
#include <string>

// Function to encrypt the plaintext
std::string encrypt(const std::string& plaintext, int key) {
    std::string ciphertext = "";

    for (char c : plaintext) {
        if (isalpha(c) && islower(c)) {
            // Encrypt lowercase letters only
            char encryptedChar = ((c - 'a') + key) % 26 + 'a';
            ciphertext += encryptedChar;
        } else {
            // Directly add non-alphabet characters
            ciphertext += c;
        }
    }

    return ciphertext;
}

// Function to decrypt the ciphertext
std::string decrypt(const std::string& ciphertext, int key) {
    return encrypt(ciphertext, 26 - (key % 26)); // Decrypting is just the reverse operation
}

int main() {
    std::string message = "hello, world!";
    int key = 3; // Example shift value for Caesar cipher

    std::string encryptedMessage = encrypt(message, key);
    std::string decryptedMessage = decrypt(encryptedMessage, key);

    std::cout << "Original: " << message << std::endl;
    std::cout << "Encrypted: " << encryptedMessage << std::endl;
    std::cout << "Decrypted: " << decryptedMessage << std::endl;

    return 0;
}
```

This example demonstrates basic encryption and decryption using a very simple algorithm. Note that the Caesar cipher is not secure by modern standards and should not be used for protecting sensitive information. For real-world applications, it's crucial to use established cryptographic standards and libraries that offer robust security features, including secure handling of keys, hashing, salting, and encryption/decryption mechanisms.

## Map vs. Unordermap

In C++, both `std::map` and `std::unordered_map` are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order. However, there are fundamental differences in their internal workings, performance characteristics, and the order in which elements are stored.

### `std::map`
- **Internal Structure**: `std::map` is typically implemented as a balanced binary tree (like a Red-Black Tree). 
- **Ordering**: It stores elements in a sorted order based on the key. The sorting criteria can be specified by a comparison function (less than by default).
- **Search Time**: Lookup operations (find, insert, delete) have logarithmic complexity (`O(log n)`).
- **Usage Scenario**: Use `std::map` when you need ordered data, or you frequently perform operations that require the container to be sorted.

### `std::unordered_map`
- **Internal Structure**: `std::unordered_map` is implemented using a hash table.
- **Ordering**: It does not store elements in any specific order. The order depends on the hash function and may change when rehashing occurs.
- **Search Time**: Provides average constant-time complexity (`O(1)`) for search operations, although this can degrade to linear (`O(n)`) in the worst case if there are many hash collisions.
- **Usage Scenario**: Use `std::unordered_map` when you need faster access and insertion and the order of elements is not important.

### Sample Code

#### Using `std::map`

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> phoneBook;
    phoneBook["Alice"] = 1234;
    phoneBook["Bob"] = 5678;
    phoneBook["Charlie"] = 91011;

    // Elements will be printed in alphabetical order based on the key
    for(const auto& pair : phoneBook) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```

Output:
```
Alice: 1234
Bob: 5678
Charlie: 91011
```

#### Using `std::unordered_map`

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> phoneBook;
    phoneBook["Alice"] = 1234;
    phoneBook["Bob"] = 5678;
    phoneBook["Charlie"] = 91011;

    // The order of elements is not guaranteed
    for(const auto& pair : phoneBook) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```

The output order may vary because `std::unordered_map` does not maintain the order of its elements.

When deciding between `std::map` and `std::unordered_map`, consider whether the order of elements is important for your application and the performance characteristics you require. `std::unordered_map` is generally faster for accessing elements by key, but `std::map` maintains a sorted order which can be beneficial for certain algorithms or when you need to print elements in order.

## Relationship Between Hashing and Dictionaries

Hashing is a fundamental concept that underpins the implementation of dictionaries (or hash tables). When you add a key-value pair to a dictionary, the dictionary uses a hash function to convert the key into a hash code. This hash code then determines where the key-value pair is stored in the dictionary's underlying data structure. This process enables the fast retrieval of values based on their keys, as the hash function provides a quick way to go from the key to its associated value.

In summary, hashing is a process or technique, while a dictionary is a data structure. Hashing enables the efficient operation of dictionaries, especially in terms of data retrieval, addition, and deletion based on keys.

## Open Addressing

Open addressing stores all entries directly within the array slots of the hash table itself. When a collision occurs, open addressing finds another slot for the colliding entry through a process called probing. There are several probing techniques, including linear probing, quadratic probing, and double hashing.

Implementing a complete hash table with linear probing, quadratic probing, and double hashing in C++ can be quite involved, but I'll provide simplified examples to illustrate the concepts. These examples are educational and meant to demonstrate the probing techniques. A fully-featured hash table suitable for production use would need more comprehensive error handling, dynamic resizing, and possibly templating for general-purpose use.

### Linear Probing

Linear probing resolves collisions by moving sequentially through the hash table until an empty slot is found.

```cpp
#include <iostream>
#include <vector>
#include <optional>

class LinearProbingHashTable {
    std::vector<std::optional<int>> table;
    int capacity;

public:
    LinearProbingHashTable(int size) : capacity(size) {
        table.resize(size);
    }

    int hash(int key) {
        return key % capacity;
    }

    void insert(int key) {
        int index = hash(key);
        while (table[index].has_value()) {
            index = (index + 1) % capacity;
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = hash(key);
        int start = index;
        while (table[index].has_value()) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % capacity;
            if (index == start) break; // Avoid infinite loop
        }
        return false;
    }
};
```

### Quadratic Probing

Quadratic probing reduces clustering by using a quadratic function to calculate the probe sequence.

```cpp
#include <vector>
#include <optional>

class QuadraticProbingHashTable {
    std::vector<std::optional<int>> table;
    int capacity;

public:
    QuadraticProbingHashTable(int size) : capacity(size) {
        table.resize(size);
    }

    int hash(int key) {
        return key % capacity;
    }

    void insert(int key) {
        int index = hash(key);
        int i = 0;
        while (table[index].has_value()) {
            index = (index + i * i) % capacity;
            i++;
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = hash(key);
        int i = 0;
        while (table[(index + i * i) % capacity].has_value()) {
            if (table[(index + i * i) % capacity] == key) {
                return true;
            }
            i++;
        }
        return false;
    }
};
```

### Double Hashing

Double hashing uses a second hash function to determine the step size after a collision.

```cpp
#include <vector>
#include <optional>

class DoubleHashingHashTable {
    std::vector<std::optional<int>> table;
    int capacity;

    int hash1(int key) {
        return key % capacity;
    }

    int hash2(int key) {
        return 1 + (key % (capacity - 1));
    }

public:
    DoubleHashingHashTable(int size) : capacity(size) {
        table.resize(size);
    }

    void insert(int key) {
        int index = hash1(key);
        int stepSize = hash2(key);
        while (table[index].has_value()) {
            index = (index + stepSize) % capacity;
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = hash1(key);
        int stepSize = hash2(key);
        while (table[index].has_value()) {
            if (table[index] == key) {
                return true;
            }
            index = (index + stepSize) % capacity;
        }
        return false;
    }
};
```

Each of these examples demonstrates the core concept of the respective probing strategy. Remember, these are simplified versions to illustrate the probing methods. A complete and robust implementation would include additional features like handling deletion (possibly with a special marker for deleted items), dynamically resizing the hash table when it gets too full, and generic programming to store any type of key-value pairs, not just integers.

## Hash Table vs Dictionary:
 
The terms "hash table" and "dictionary" are often used interchangeably in the context of data structures, but they can have distinct meanings depending on the programming language or the specific implementation context. Here's a breakdown of how they are generally understood and used:

### Hash Table

- **Definition**: A hash table is a data structure that implements an associative array abstract data type, a structure that can map keys to values. It uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.
- **Key Characteristics**:
    - Uses a hash function to determine where to store each key-value pair.
    - Handles collisions through various methods like chaining (where each bucket is a linked list of entries that hash to the same index) or open addressing (where a collision triggers a search for another bucket according to a predefined sequence).
    - Efficiency: Ideally offers \(O(1)\) average time complexity for insert, delete, and search operations, although this can degrade to \(O(n)\) in the worst case (e.g., when all keys hash to the same index).
- **Use Cases**: Used internally by many programming languages for their dictionary or map implementations. Directly used in low-level programming or when specific customizations are needed.

### Dictionary

- **Definition**: A dictionary is an abstract data type that represents a collection of keys and values, with each key being unique within the collection. In many languages, dictionaries are implemented using hash tables, but this is not universally true.
- **Key Characteristics**:
    - Provides a high-level interface to add, remove, and access elements by keys.
    - The implementation may vary: while many languages use hash tables, others might use trees or other data structures to ensure order or provide different performance guarantees.
    - Efficiency: The performance of a dictionary depends on its underlying implementation but often aims for \(O(1)\) average time complexity for standard operations.
- **Use Cases**: Dictionaries are used in a wide range of applications, from storing simple configurations to complex data processing. They are a fundamental data structure in many high-level programming languages like Python (`dict`), JavaScript (objects as associative arrays), and C# (`Dictionary`).

### Comparison and Relation

- **Implementation vs. Concept**: The term "hash table" is often used to refer to a specific implementation technique for dictionaries. In contrast, "dictionary" is a more abstract term that refers to the concept of mapping keys to values, regardless of the underlying implementation.
- **Performance Characteristics**: The performance of a dictionary can vary based on its implementation. Hash tables are generally chosen for their ability to provide fast lookups, insertions, and deletions.
- **Ordering**: Standard hash tables do not maintain any order of the keys. However, some dictionary implementations, like Python's `OrderedDict` or the standard `dict` in Python 3.7 and later, maintain keys in insertion order or sorted order, using different underlying mechanisms than a plain hash table.

In summary, while the terms can sometimes be used interchangeably, "hash table" refers more to the specific data structure and its implementation, whereas "dictionary" refers to the abstract data type and its interface for mapping keys to values. The choice between using the term "hash table" or "dictionary" often depends on the level of abstraction being discussed and the specific language or context.
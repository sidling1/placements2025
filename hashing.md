- all three operations (search, insert and delete) in O(1) time on average.
- Collision : The situation where the newly inserted key maps to an already occupied
- Hashing refers to the process of generating a fixed-size output from an input of variable size using the mathematical formulas known as hash functions
- The hash function creates a mapping between key and value
- load factor(number of items in the table divided by the size of the table).
- Hash provides better synchronization than other data structures.
- Hash tables are more efficient than search trees or other data structures
- Hash does not allow null values.
- used in databases for indexing, disk-based data structures and  data compression
- Rolling hash function, update the hash value for a new substring by removing contri of old char and add contri of new char.


# Hash Functions
- Division Method : `h(k) = k mod m where m is prime and size of table ` , Poor distribution if 𝑚m is not chosen wisely.
- Mid Square Method : ` the key is squared, and the middle digits of the result are taken as the hash value. `, good distribution, computationaly less eff
- Folding Method : ` dividing the key into equal parts, summing the parts, and then taking the modulo with respect to 𝑚m. `, Depends on the choice of partitioning scheme.
- Multiplication Method : ` h(k)=⌊m(kA mod 1)⌋ where m is size of table `, Less sensitive to the choice of m.
- Cryptographic Hash Functions : High Security, Computationally intensive , MD5, SHA-1, and SHA-256.
- Universal Hashing : ` h(k)=((a⋅k+b) mod p) mod m `, p is a prime number greater than m , Reduces the probability of collisions.
- Perfect Hashing : Perfect hashing aims to create a collision-free hash function for a static set of keys. It guarantees that no two keys will hash to the same value.

Properties:
- Deterministic: A hash function must consistently produce the same output for the same input.
- Fixed Output Size: The output of a hash function should have a fixed size, regardless of the size of the input.
- Efficiency: The hash function should be able to process input quickly.
- Uniformity
- Collision Resistance: It should be difficult to find two different inputs that produce the same hash value.
- Avalanche Effect: A small change in the input should produce a significantly different hash value.

# Handle Collisions
- Separate Chaining : make each cell of the hash table point to a linked list of records , simple but requires additional memory outside the table.
- Open Adressing : In open addressing, all elements are stored in the hash table itself. 
    - Linear Probing : 
    - Quadratic Probing : adding successive values of an arbitrary quadratic polynomial until an open slot is found.
    - Double Hashing : ` h(k, i) = (h1(k) + i * h2(k)) % n `

# Load Factor
- rehashing means hashing again. when load factor > predefined value (default 0.75), the complexity increases. size increased (doubled) and all the values are hashed again and stored in the new double-sized array to maintain a low load factor and low complexity.

# Bloom Filters
- A Bloom filter is a space-efficient probabilistic data structure that is used to test whether an element is a member of a set. 
- https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/

# Index Mapping
- For large number of queries in an array having limited range integers


# Open Adressing vs Separate Chaining
1. Chaining is Simpler to implement.	Open Addressing requires more computation.
2.	In chaining, Hash table never fills up, we can always add more elements to chain.	In open addressing, table may become full.
3.	Chaining is Less sensitive to the hash function or load factors.	Open addressing requires extra care to avoid clustering and load factor.
4.	Chaining is mostly used when it is unknown how many and how frequently keys may be inserted or deleted.	Open addressing is used when the frequency and number of keys is known.
5.	Cache performance of chaining is not good as keys are stored using linked list.	Open addressing provides better cache performance as everything is stored in the same table.
6.	Wastage of Space (Some Parts of hash table in chaining are never used).	In Open addressing, a slot can be used even if an input doesn’t map to it.
7.	Chaining uses extra space for links.	No links in Open addressing

assumption that each key is equally likely to be hashed to any slot of the table (Simple Uniform Hashing)

Separate Chaining:

```
m = Number of slots in hash table
n = Number of keys to be inserted in hash table


Load factor α = n/m
Expected time to search = O(1 + α)
Expected time to delete = O(1 + α)


Time to insert = O(1)
Time complexity of search insert and delete is O(1) if  α is O(1)
```

Open Addressing:
```
m = Number of slots in the hash table
n = Number of keys to be inserted in the hash table
Load factor α = n/m  ( < 1 )
Expected time to search/insert/delete < 1/(1 – α) 
So Search, Insert and Delete take (1/(1 – α)) time
```

# Double Hashing
The advantage of Double hashing is that it is one of the best forms of probing, producing a uniform distribution of records throughout a hash table.
This technique does not yield any clusters.
It is one of the effective methods for resolving collisions.

```
hash1(key) = key % TABLE_SIZE
hash2(key) = PRIME – (key % PRIME)
```


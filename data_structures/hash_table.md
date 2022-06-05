filename : hash_table.md

author : Catherine Chen ccrchen@ucdavis.edu

brief : exploring the basic understanding & usage of hash tables

date : 06/04/2022


# Hash Table

## What is a hash table?

A hash table, or hash map, is a data structure that maps keys to values. It's underlying implementation is an array of _m_ buckets (_m_ number of buckets). By using hash functions, the hash table converts keys to indexes to be stored in the hash table. The overall goal of a hash table is to distribute the keys in the hash table as evenly as possible.


## Creating a hash table in C

When creating a hash table, the number of buckets should always be a prime number to prevent infinite looping to insert an element without collisions. 

The following code instantiates a bucket struct of a hash table and a hash table struct:

```c
struct Bucket 
{
int key;
const void* value; // const void* can be any type
int flag; // OR char* flag;

// flag to mark if the bucket:
//     1) has never been filled, 
//     2) contains an element, or 
//     3) has been deleted
};

struct hashTable 
{
    struct* Bucket; // a hash table is made of many buckets
    // include other members that you want to have in a hash table
}
```
Hash tables are made of many buckets. The hash table struct contains the array of bucket structs depending on its table size. To create a hash table in C, you can dynamically allocate space in memory to make a hash table array with malloc(). Using dynamic memory allocation is neccessary for changing the table size during a rehash to make the hash table as efficient as possible. The hash table will consist of as many buckets as the table size mentions. Remember: table size is always a prime number!

## Basic operations of a hash table

###**Insert**
Insert an element into a hash table by their key

#### Hash function

Assuming keys are integers in this instance, a typical hash function is `hash(key) = key % m`, in which _m_ is the number of buckets. The result of this function will be the hash value, or index of the bucket the key will be placed in.

For example: 

`insert(84) -> 84 % 10 = 4`
This places key 14 at bucket 4.

`insert(33) -> 33 % 10 = 3`
This places key 33 at bucket 3.

`insert(1) -> 1 % 10 = 1`
This places key 1 at bucket 1.

The implementation code would be 
```c
int hashFunction(int key)
{
   return key % table_size;
}
```
#### Collision Resolution

When inserting elements, collisions can happen, when elements are mapped to the same bucket index as other elements.

For example:

`insert(84) -> 84 % 10 = 4`
`insert(24) -> 24 % 10 = 4`

Here, 84 and 24 both map to bucket 4. However, 84 is already stored in bucket 4, so 24 cannot be stored in it. Therefore, it needs to be placed in the next available empty bucket. This can be found with quadratic probing.

##### Quadratic Probing

Quadratic probing is a method of open-address collision resolution that searches for the i^2th bucket in the ith iteration based on the original hash value index. This method prevents clustering of values in one section of the hash table.

The concept of quadratic probing is if the bucket `hashFunction(key) % table_size` is full, then we try the next bucket, which is  `(hashFunction + 1*1) % table_size`. If that is full, then we try `(hashFunction + 2*2) % table_size`. In general, the function for quadratic probing is `(hashFunction + i*i) % table_size`, in which i is the number of iterations it takes to find an empty bucket. 

Another way to think about quadratic probing is to look at the bucket after `hashFunction(key)`, then if that is full, then check 3 buckets after that bucket, then check 5 buckets later, then 7 buckets later, etc. 

###**Search**
Searching for an element in a hash table can be implemented in the same way with inserting an element with the hash function. When searching for an element, the hash value or the value through probing should be the index of the element. When coming across a deleted element, you should keep searching the next buckets to see if the element is later on in the hash table. 

If you come across an empty bucket, that means that the element that you are searching for is not in the table, otherwise the element you are searching for would have been stored in the empty bucket. 

###**Delete**
To delete an element in a hash table, you can use the hashFunction and quadratic probing to find the element in the hash table. Once you have found the element, you can lazily delete mark the value in the bucket as deleted using the `flag` that is stored in your bucket struct. With lazy deletion, you are not actually deleting the value from the hash table. Just by marking that the element was deleted, this signals the search function that a value was here before, but has been deleted, so there is a chance that the element you are searching for is in a later bucket. This is to prevent the search function from stopping prematurely and falsely reporting that the element is not in the table.

```c
for (int i = 0; ; i++) 
{
    if (bucket[i].key == key) 
    {
        flag = deleted; // mark bucket as being deleted
        break;
    } 
    else 
        //continue searching for the element with quadratic probing;
}
```


## Load size
Load size, or λ (lambda), is the ratio of elements in the hash table and the total number of buckets in the hash table. 
`λ = n elements / hash table size`

To make the hash table efficient, the load size should always be less than 1/2. If the load size exceeds 1/2, then the table needs to be rehashed and the table size needs to be increased.

## Rehashing
If the load factor is too high (λ > 1/2), your hash table needs to rehash. This means that you need to increase your table size by doubling your current table size and find the next largest prime number. 

**These are the steps you needs to do to rehash:**
Let `m` be the old table size and `m'` be the new table size.

1) Evaluate the new table size where `m' = nextPrime(2m)`, in which `nextPrime(x)` returns the next biggest prime number greater than 2 times the old table size.
2) Move elements from the old table into the new table with its new hash value of `hashFunction(key) % m'`




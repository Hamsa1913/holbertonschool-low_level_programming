# 0x1A. C - Hash tables

This directory contains my solutions for the **Hash tables** project in the `holbertonschool-low_level_programming` repository.

## Learning Objectives

By the end of this project, I should be able to explain (without Google):

- What is a hash function
- What makes a good hash function
- What is a hash table, how it works and how to use it
- What is a collision and the main ways to handle collisions
- Advantages and drawbacks of using hash tables
- The most common use cases of hash tables

## Data Structures

The project uses the following structures:

```c
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;


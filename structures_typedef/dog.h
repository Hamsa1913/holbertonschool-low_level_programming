#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog's basic info
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 */
struct dog
{
    char *name;
    float age;
    char *owner;
};

/**
 * dog_t - typedef for struct dog
 */
typedef struct dog dog_t;

#endif /* DOG_H */

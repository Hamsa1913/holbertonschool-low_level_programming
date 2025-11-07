#ifndef DOG_H
#define DOG_H

/**
 * struct dog - information about a dog
 * @name: pointer to the dog's name (string)
 * @age: dog's age (float)
 * @owner: pointer to the dog's owner (string)
 *
 * Description: Defines a struct that stores info about a dog.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/* Function prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_H */

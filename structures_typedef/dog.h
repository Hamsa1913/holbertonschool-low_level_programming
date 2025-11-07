#ifndef DOG_H
#define DOG_H

/**
 * struct dog - structure for dog info
 * @name: pointer to dog's name
 * @age: dog's age
 * @owner: pointer to owner's name
 *
 * Description: structure that stores info about a dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif /* DOG_H */

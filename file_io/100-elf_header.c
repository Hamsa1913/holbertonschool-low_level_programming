#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * error_exit - prints an error message and exits with status 98
 * @msg: error message
 */
void error_exit(char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * print_magic - prints the ELF magic bytes
 * @h: pointer to ELF header
 */
void print_magic(Elf64_Ehdr *h)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", h->e_ident[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * print_class_data_version - prints class, data and version fields
 * @h: pointer to ELF header
 */
void print_class_data_version(Elf64_Ehdr *h)
{
	printf("  Class:                             ");
	if (h->e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (h->e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown>\n");

	printf("  Data:                              ");
	if (h->e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (h->e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown>\n");

	printf("  Version:                           %d (current)\n",
		h->e_ident[EI_VERSION]);
}

/**
 * print_osabi_type_entry - prints OS/ABI, ABI version, type and entry point
 * @h: pointer to ELF header
 */
void print_osabi_type_entry(Elf64_Ehdr *h)
{
	printf("  OS/ABI:                            ");
	switch (h->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %x>\n", h->e_ident[EI_OSABI]);
		break;
	}

	printf("  ABI Version:                       %d\n",
		h->e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	if (h->e_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (h->e_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (h->e_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else
		printf("<unknown: %x>\n", h->e_type);

	printf("  Entry point address:               0x%lx\n",
		(unsigned long)h->e_entry);
}

/**
 * main - displays ELF header information
 * @ac: argument count
 * @av: argument values
 * Return: 0 on success, 98 on error
 */
int main(int ac, char **av)
{
	int fd;
	ssize_t r;
	Elf64_Ehdr h;

	if (ac != 2)
		error_exit("Usage: elf_header elf_filename");

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Can't read file");

	r = read(fd, &h, sizeof(h));
	if (r != sizeof(h))
		error_exit("Error: Can't read ELF header");

	if (h.e_ident[EI_MAG0] != ELFMAG0 ||
	    h.e_ident[EI_MAG1] != ELFMAG1 ||
	    h.e_ident[EI_MAG2] != ELFMAG2 ||
	    h.e_ident[EI_MAG3] != ELFMAG3)
		error_exit("Error: Not an ELF file");

	print_magic(&h);
	print_class_data_version(&h);
	print_osabi_type_entry(&h);

	if (close(fd) == -1)
		error_exit("Error: Can't close fd");

	return (0);
}


#include <stdio.h>

#define length(a) (sizeof a / sizeof *a)
char arr[10] = {'0','1','2','2','4','5','6','7','8','9'};

static size_t hash(const char key)
{
    return key - '0';
}

static void fill_table(char table[]);
static void show_table(const char table[], size_t size);

int main(void)
{
    /* This is our hash table */
    char table[10] = { 0 };

    fill_table(table);
    show_table(table, length(table));

    return 0;
}


/* Populate the hash table */
void fill_table(char table[])
{
    unsigned char x = 0;

    while (x < 10) {
        unsigned i = hash(arr[x]);

        if (table[i] != 0) {
            /* Duplicate indexes are called collisions */
            printf("That index %d has been filled\n", i);
        } else {
            /* The element is empty; fill it in */
            table[i] = arr[x];
        }
        x++;
    }
}

/* Display the contents of the hash table */
void show_table(const char table[], size_t size)
{
    size_t i;

    for (i = 0; i < size; i++) {
        /* Mark empty elements as 'null' with the ~ character */
        printf("%c\n", table[i] != 0 ? table[i] : '~');
    }
}

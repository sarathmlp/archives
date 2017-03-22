#include <stdio.h>

#define DUPLICATED -1
#define ADDED      0
#define OUT_OF_MEM 1

struct data
{
    int value;
    unsigned char used;
};

int check_duplicate(int value);
void print(struct data list[]);

struct data duplicate_list[5] =  {{12,1}, {2,1}, {0, 0}, {24, 1}, {3,1}};
int duplicate_list_size = 5;

int main()
{
    print(duplicate_list);

    check_duplicate(2);
    check_duplicate(9);
    print(duplicate_list);

    return 0;
}

void print(struct data list[]) 
{
    int i;
    for (i=0; i < 5; i++) {
        printf("%3d %3u\n", list[i].value, list[i].used);
    }
    printf("\n");
}

#if 1
int check_duplicate(int value) {
    int freeSlot = -1;

    for (int i=0; i<duplicate_list_size; i++) {
        if(duplicate_list[i].used && duplicate_list[i].value == value) {
            return DUPLICATED;
        } else if (!duplicate_list[i].used && (freeSlot == -1)) {
            freeSlot = i;
        }
    }
    if (freeSlot != -1) {
        duplicate_list[freeSlot].used = 1;
        duplicate_list[freeSlot].value = value;
        return ADDED;
    }
    return OUT_OF_MEM;
}
#endif
#if 0
int check_duplicate(int value) {
  for(int i=0; i<duplicate_list_size; i++) {
    if(duplicate_list[i].used && duplicate_list[i].value == value)
      return -1;
  }
  for(int i=0; i<duplicate_list_size; i++) {
    if(!duplicate_list[i].used) {
      duplicate_list[i].used = 1;
      duplicate_list[i].value = value;
      return 0;
    }
  }
  return 1;
}
#endif

#include <stdio.h>
#define MAX 128

int main()
{
    char *s="thisara isrtixngs ta es sring";
    char *f="str";

    int charlist[MAX]   = {0};
    int foundlist[MAX]  = {0};
    int totalchar       = 0;
    int start           = -1;
    int start_pos       = -1;
    int min_len         = 0;
    int i;

    for (i=0; f[i]; i++) {
        if (charlist[f[i]] == 0) {
            totalchar++;
        }
        charlist[f[i]]++;
    }

    for (i=0; s[i]; i++) {
        if (charlist[s[i]]) {
            if (start == -1) {
                start = i;
            }
            foundlist[s[i]]++;

            if (foundlist[s[i]] == charlist[s[i]]) {
                totalchar--;
            }
        }

        if (totalchar == 0 && start_pos == -1) {
            min_len = i - start +1;
            start_pos = start;
        }
        if (totalchar == 0 && (foundlist[s[start]] > charlist[s[start]])) {
            while (charlist[s[start]] == 0 || (foundlist[s[start]] > charlist[s[start]])) {
                if (charlist[s[start]]) {
                    foundlist[s[start]]--;
                }
                start++;
            }
            if (min_len > (i-start+1)) {
                min_len = i-start+1;
                start_pos = start;
            }
        }
    }

    for (i=start_pos; i < start_pos + min_len; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}

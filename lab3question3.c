#include <stdio.h>
#include <string.h>
int main() {
    char s[1000];
    int freq[256] = {0};
    printf("Enter a string: ");
    scanf("%s", s);
    for(int i = 0; s[i] != '\0'; i++)
        freq[(unsigned char)s[i]]++;
    while(1) {
        int max = 0;
        int ch = -1;
        for(int i = 0; i < 256; i++) {
            if(freq[i] > max) {
                max = freq[i];
                ch = i;
            }
        }
        if(ch == -1)
            break;
        for(int i = 0; i < max; i++)
            printf("%c", ch);
        freq[ch] = 0;
    }
    return 0;
}

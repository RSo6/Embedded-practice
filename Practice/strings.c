#include <stdio.h>

#define MAXLINE 1000

void oddElimination(char [], int);

int main(void) {

    char line[MAXLINE];
    int i = 0, c;
    printf("Enter the line to eliminate odd sequence characters, \"~\" - to quit\n");
    while ((c = getchar()) != EOF && c != '~') {
        if (c != '\n' && i < MAXLINE - 1) {
            line[i] = (char) c;
            ++i;
        } else {
            line[i] = '\0';
            printf("The entered line --> %s\n", line);
            oddElimination(line, i);
            printf("The line without eliminated odd characters --> %s\n", line) ;
            i = 0;
        }

    }

    return 0;
}

void oddElimination(char line [], int const length) {
    int eliminated = 0;
    char copy[length + 1];

    for (int i = 0; i < length; ++i) {
        if (i % 2 == 1) {
            ++eliminated;
            continue;
        }

        copy[i - eliminated] = line[i];
    }

    int const new_length = length - eliminated;

    for (int i = 0; i < new_length; ++i)
        line[i] = copy[i];

    line[new_length] = '\0';

}
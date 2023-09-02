#include <stdio.h>
#include <unistd.h>

int main() {
    int Number;
    printf("Enter number: ");
    scanf("%d", &Number);

    for (int i = Number; i >= 1; i--) {
        printf("%d\n", i);
        sleep(1);
    }
    printf("Blast off to the moon!\n");
    return 0;
}
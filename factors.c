#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: ./program <filename>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        unsigned long long number = atoi(buffer);
        unsigned long long divisor = 0;
        
        if (number % 2 == 0) {
            divisor = 2;
        }
        else if (number % 3 == 0) {
            divisor = 3;
        }
        else {
            int i = 6;
            while (i <= sqrt(number) + 1 && divisor == 0) {
                if (number % (i - 1) == 0) {
                    divisor = i - 1;
                }
                if (number % (i + 1) == 0) {
                    divisor = i + 1;
                }
                i += 6;
            }
            if (divisor == 0) {
                divisor = 1;
            }
        }
        
        printf("%lld=%lld*%lld\n", number, number / divisor, divisor);
    }
    
    fclose(file);
    return 0;
}

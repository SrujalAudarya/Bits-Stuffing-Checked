#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to perform bit stuffing
void bitStuffing(char data[], char stuffed[]) {
    int i, j = 0, count = 0;
    for (i = 0; data[i] != '\0'; i++) {
        stuffed[j++] = data[i];
        if (data[i] == '1') {
            count++;
            if (count == 5) {  // After 5 consecutive 1s, insert a 0
                stuffed[j++] = '0';
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    stuffed[j] = '\0';
}

// Function to perform bit destuffing
void bitDestuffing(char stuffed[], char destuffed[]) {
    int i, j = 0, count = 0;
    for (i = 0; stuffed[i] != '\0'; i++) {
        destuffed[j++] = stuffed[i];
        if (stuffed[i] == '1') {
            count++;
            if (count == 5 && stuffed[i + 1] == '0') {  // If 5 ones are found, skip next 0
                i++; 
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    destuffed[j] = '\0';
}

// Main function
int main() {
    char data[MAX], stuffed[MAX], destuffed[MAX];

    printf("Enter binary data: ");
    scanf("%s", data);

    bitStuffing(data, stuffed);
    printf("Bit Stuffed Data:   %s\n", stuffed);

    bitDestuffing(stuffed, destuffed);
    printf("Bit Destuffed Data: %s\n", destuffed);

    return 0;
}

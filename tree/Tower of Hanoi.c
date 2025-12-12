#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source → auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move nth disk from source → destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move n-1 disks from auxiliary → destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n = 3; // You can change this value
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}

sample output
/*
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
*/

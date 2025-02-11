#include <stdio.h>
#include <stdint.h>

void switchL(uint8_t *state, int room) {
    if (room < 1 || room > 8) {
        printf("Invalid room number!!!\n");
        return;
    }
    *state ^= (1 << (room - 1));
}

void print_state(uint8_t state) {
    printf("There are turned on lights in rooms: ");
    for (int i = 0; i < 8; i++) {
        if (state & (1 << i)) {
            printf("%d ", i + 1);
        }
    }
}

int main() {
    uint8_t light_state = 0; 
    int choice, room;
    while (1) {
        printf("\nMenu:\n1. Say state\n2. Switch the lights\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print_state(light_state);
                break;
            case 2:
                printf("Enter room number (1-8): ");
                scanf("%d", &room);
                switchL(&light_state, room);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!!!\n");
        }
    }
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for each hotel room
typedef struct {
    int room_no;
    int occupied;
    char guest_name[30];
    float rate;
} Room;

// Function to initialize all rooms as unoccupied
void init_rooms(Room rooms[], int n) {
    for (int i = 0; i < n; i++) {
        rooms[i].room_no = i + 1;
        rooms[i].occupied = 0;
        rooms[i].rate = 100.0;
    }
}

// Function to display all rooms
void display_rooms(Room rooms[], int n) {
    printf("Room No.\tOccupied\tGuest Name\tRate\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t", rooms[i].room_no);
        if (rooms[i].occupied) {
            printf("Yes\t\t%s\t\t%.2f\n", rooms[i].guest_name, rooms[i].rate);
        } else {
            printf("No\t\t---\t\t%.2f\n", rooms[i].rate);
        }
    }
}

// Function to find an available room
int find_room(Room rooms[], int n) {
    for (int i = 0; i < n; i++) {
        if (!rooms[i].occupied) {
            return i;
        }
    }
    return -1;
}

// Function to book a room
void book_room(Room rooms[], int n) {
    int room_index = find_room(rooms, n);
    if (room_index == -1) {
        printf("Sorry, no rooms are available at the moment.\n");
        return;
    }
    printf("Enter guest name: ");
    scanf("%s", rooms[room_index].guest_name);
    rooms[room_index].occupied = 1;
    printf("Room booked successfully!\n");
}

// Function to check out of a room and calculate the bill
void checkout_room(Room rooms[], int n) {
    int room_no;
    printf("Enter room no.: ");
    scanf("%d", &room_no);
    if (room_no < 1 || room_no > n) {
        printf("Invalid room no.\n");
        return;
    }
    Room* room = &rooms[room_no - 1];
    if (!room->occupied) {
        printf("Room is not occupied.\n");
        return;
    }
    float days;
    printf("Enter number of days stayed: ");
    scanf("%f", &days);
    float bill = room->rate * days;
    printf("Guest Name: %s\n", room->guest_name);
    printf("Room Rate: %.2f\n", room->rate);
    printf("Number of days stayed: %.2f\n", days);
    printf("Total bill: %.2f\n", bill);
    strcpy(room->guest_name, "");
    room->occupied = 0;
}
// Main function
int main() {
    int n = 10;
    Room rooms[n];
    init_rooms(rooms, n);
    int choice;
    do {
        printf("\n");
        printf("1. Display all rooms\n");
        printf("2. Book a room\n");
        printf("3. Check out of a room\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                display_rooms(rooms, n);
                break;
            case 2 :
            	find_room(rooms, n);
                break;
//hi
                

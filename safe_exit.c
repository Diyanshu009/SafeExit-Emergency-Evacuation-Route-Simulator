#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constants for array sizes
#define MAX_ROUTES  200   // Maximum number of room entries
#define MAX_ROOM     16   // Maximum length for a room number
#define MAX_PATH    256   // Maximum length for a path description
#define MAX_LINE    512   // Maximum length for a line in the file

// Arrays to store room numbers and their exit paths
char rooms[MAX_ROUTES][MAX_ROOM];
char paths[MAX_ROUTES][MAX_PATH];

// Function to remove newline character from input string
void trim_newline(char *s) 
{
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[len - 1] = '\0';
}

// Function to convert a string to uppercase
// Helps with case-insensitive comparison
void to_uppercase(char *s) 
{
    for (int i = 0; s[i]; ++i)
        s[i] = toupper((unsigned char)s[i]);
}

// Function to load routes from a text file
// Returns number of entries loaded, or -1 if error
int load_routes(const char *filename) 
{
    FILE *fp = fopen(filename, "r");
    if (!fp) 
    {
        printf("Error: Could not open the file '%s'.\n", filename);
        return -1;
    }

    char line[MAX_LINE];
    int count = 0;

    // Read each line and extract room and exit path
    while (count < MAX_ROUTES && fgets(line, sizeof(line), fp)) 
    {
        trim_newline(line);
        sscanf(line, "%s %[^\n]", rooms[count], paths[count]);
        to_uppercase(rooms[count]);  // store room names in uppercase for uniformity
        count++;
    }

    fclose(fp);
    return count;
}

// Function to print all rooms and exit paths
// Also prints emergency contact numbers
void list_all_routes(int total) 
{
    printf("\n====== ALL EXIT ROUTES ======\n");
    for (int i = 0; i < total; ++i)
        printf("Room %-10s → %s\n", rooms[i], paths[i]);

    printf("\nEmergency Contacts:\n");
    printf(" 911            - General Emergency\n");
    printf(" 817-272-3381   - Campus Police\n");
    printf(" 817-272-2000   - Facilities Emergency\n\n");
}

// Function to find and display route for a specific room
void find_route(const char *room, int total) 
{
    char upper_room[MAX_ROOM];
    strncpy(upper_room, room, MAX_ROOM);
    to_uppercase(upper_room);

    // Compare input room with list of stored rooms
    for (int i = 0; i < total; ++i) 
    {
        if (strcmp(upper_room, rooms[i]) == 0) 
        {
            printf("\nNearest exit for room %s:\n  %s\n\n", room, paths[i]);
            return;
        }
    }

    // If not found
    printf("\n⚠️  No route found for room %s. Type HELP to see all routes.\n\n", room);
}

int main(int argc, char *argv[]) 
{
    // Check if file name was provided
    if (argc != 2) 
    {
        printf("Usage: %s <routes-file>\n", argv[0]);
        return 1;
    }

    // Load the routes from the file
    int total_routes = load_routes(argv[1]);
    if (total_routes <= 0) return 1;

    char input[64];

    // Welcome message
    printf("\n=== SafeExit System ===\n");
    printf("Enter your room number (e.g., 204A).\n");
    printf("Type HELP to see all routes or QUIT to exit.\n\n");

    // Loop to keep asking the user for input
    while (1) 
    {
        printf("Enter room or command > ");
        if (!fgets(input, sizeof(input), stdin)) break;

        trim_newline(input);
        to_uppercase(input);

        if (strcmp(input, "QUIT") == 0) break;
        else if (strcmp(input, "HELP") == 0)
            list_all_routes(total_routes);
        else
            find_route(input, total_routes);

        // Ask if user wants to continue or exit
        printf("Do you want to search another room? (yes/no): ");
        if (!fgets(input, sizeof(input), stdin)) break;
        trim_newline(input);
        to_uppercase(input);
        if (strcmp(input, "NO") == 0) break;
    }

    // Exit message
    printf("\nThank you for using SafeExit. Stay safe!\n");
    return 0;
}

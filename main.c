#include <stdio.h>
#include <string.h>

// Maximum message length
#define MAX_MSG_LENGTH 1024
// Maximum ASCII art size
#define MAX_ASCII_LENGTH 4096
// Maximum message line length for word wrapping
#define MAX_LINE_LENGTH 64

// Word wrap for the message
void wrap_msg(char *message) {
  int len = strlen(message);
  if (len > MAX_LINE_LENGTH) {
    for (int i = MAX_LINE_LENGTH; i < len; i += MAX_LINE_LENGTH) {
      memmove(&message[i + 1], &message[i], len - i);
      message[i] = '\n';
      len++;
    }
  }
}
int main(int argc, char *argv[]) {
    if (argc == 3) { // Expecting two arguments: message and file path
        char msg[MAX_MSG_LENGTH];

        if (strlen(argv[1]) < MAX_MSG_LENGTH) {
            strcpy(msg, argv[1]);
            wrap_msg(msg);
            FILE *file;
            char buffer[MAX_ASCII_LENGTH];

            file = fopen(argv[2], "r");
            if (file == NULL) {
                printf("Error opening file\n");
                return 1;
            }

            size_t asciiArtLength = fread(buffer, 1, sizeof(buffer), file);
            if (asciiArtLength > MAX_ASCII_LENGTH) {
                printf("ASCII art length overflow: Expected %i, got %zu\n", MAX_ASCII_LENGTH, asciiArtLength);
                return 1;
            }

            fclose(file);

            // Print the modified ASCII art with the message
            printf(buffer, msg);
            printf("\n");
        } else {
            printf("Error: Message too long. Expected length %i, got %zu\n", MAX_MSG_LENGTH, strlen(argv[1]));
            return 1;
        }
    } else {
        printf("Error: Missing arguments\n");
    }
    
    return 0;
}

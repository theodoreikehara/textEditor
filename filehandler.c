#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int displayFileContents(const char *filename) {
    FILE *file = fopen(filename, "r"); // Open the file in read mode
    if (file == NULL) { // Check if the file opened successfully
        perror("Could not open file");
        return 1;
    }

    char line[256]; // Buffer to store each line
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line); // Print each line to the console
    }

    fclose(file); // Close the file after reading

    return 0;
}

int modifyCharInFile(const char *filename, long position, char new_char) {
    FILE *file = fopen(filename, "r+"); // Open the file in read/write mode
    if (file == NULL) { // Check if the file opened successfully
        perror("Could not open file");
        return 1;
    }

    // Get the current size of the file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);

    // If the position is beyond the end of the file, pad with spaces
    if (position > file_size) {
        for (long i = file_size; i < position; i++) {
            fputc(' ', file); // Fill with spaces up to the specified position
        }
    }

    // Move to the specified position and write the new character
    fseek(file, position, SEEK_SET);
    fputc(new_char, file);

    fclose(file); // Close the file after modification

    return 0;
}

int deleteCharInFile(const char *filename, long position) {
    FILE *file = fopen(filename, "r+"); // Open the file in read/write mode
    if (file == NULL) { // Check if the file opened successfully
        perror("Could not open file");
        return 1;
    }

    // Get the current size of the file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);

    // Check if the position is valid
    if (position >= file_size) {
        fclose(file);
        return 1; // Invalid position, cannot delete
    }

    // Allocate memory for the buffer to hold the rest of the file from the position
    char *buffer = malloc(file_size - position);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    // Move to the position and read the rest of the file into the buffer
    fseek(file, position + 1, SEEK_SET);
    fread(buffer, 1, file_size - position - 1, file);

    // Move back to the position and overwrite starting from there (shifting left)
    fseek(file, position, SEEK_SET);
    fwrite(buffer, 1, file_size - position - 1, file);

    // Truncate the file to remove the last character
    ftruncate(fileno(file), file_size - 1);

    // Free the buffer and close the file
    free(buffer);
    fclose(file);

    return 0; // Success
}

int main() {
    displayFileContents("testfile.txt");

    deleteCharInFile("testfile.txt", 0);

    displayFileContents("testfile.txt");

    return 0;
}
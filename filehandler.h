#ifndef PROGRAM_H    

// Function to display the contents of a file
// filename: the file to display
// Returns: 0 on success, 1 on error
int displayFileContents(const char *filename);

// Function to modify a character in a file at a specified position
// filename: the file to modify
// position: the index of the character to modify
// new_char: the character to insert at the specified position
// Returns: 0 on success, 1 on error
int modifyCharInFile(const char *filename, long position, char new_char);

// Function to delete a character at a specified position in a file
// filename: the file to modify
// position: the index of the character to delete
// Returns: 0 on success, 1 on error
int deleteCharInFile(const char *filename, long position);

#endif  // End of include guard
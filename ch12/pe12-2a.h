/* By using the extern qualifier, the functions are not defined 
    here but rather just referenced from somewhere else. This is
    a better practice to avoid multiple (although probably identical)
    definitions of the same functions.
*/

/* Header file naming
    Here the header file name coincides with the implementation *.c
    file name. This is good practice but not a must. Usually the header
    file reflects the implementation in a source code file, so it is
    conventient to keep the name the same. But the compiler treats these
    two files as separate and completely unrelated files by default.
    Compiler does not do name-matching between header and source files.
*/
extern void set_mode(int mode);
extern void get_info(void);
extern void show_info(void);
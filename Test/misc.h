#ifndef MISC
#define MISC

#define YELLOW_COLOR "\033[0;33m"
#define GREEN_COLOR "\033[0;32m"
#define BLUE_COLOR "\033[0;34m"
#define RED_COLOR "\033[0;31m"
#define NO_COLOR "\033[0m"

#define set_text_color(color) printf(color)

void* int_to_ptr(int data);
void* char_to_ptr(char data);
int ptr_to_int(void* pointer);
char ptr_to_char(void* pointer);
int ptr_to_int_free(void* pointer);
char ptr_to_char_free(void* pointer);

void print_int_index(void* data, unsigned long index);
void print_char_index(void* data, unsigned long index);
void print_int(void* data);
void print_char(void* data);

#endif // MISC
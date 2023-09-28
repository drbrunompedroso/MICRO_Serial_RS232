#include<xc.h>

void eusart_init(void);
void eusart_write(char c);
void eusart_string(char *str);
char eusart_read(void);
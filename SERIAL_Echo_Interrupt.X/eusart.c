#include "eusart.h"

//********************* InicializaÁ„o do MÛdulo EUSART*************************************//
void eusart_init(void)
{
    TXSTAbits.TXEN = 1;                     // Habilita Transmiss√£o pela EUSART
    RCSTAbits.CREN = 1;                     // Habilita Recp√ß√£o pela EUSART
    TXSTAbits.SYNC = 0;                     // Habilita modo Ass√≠ncrono
    RCSTAbits.SPEN = 1;                     // Configura pinosRC6 e RC7 como TX e RX
    TXSTAbits.BRGH = 0;                     // Controle de Baund Rate
    BAUDCTLbits.BRG16 = 0;                  
    SPBRG = 12;                             // Defini√ß√£o do Baund Rate (12 - 9600 bps)
}

//*************************** Transmiss„o de caracteres via EUSART*********************************//
void eusart_write(char c)
{
    while(!TRMT);                           // Aguarda a finaliza√ß√£o do envio de caracteres
    TXREG = c;                              // Carrega em TXREG e transmite o caractere via EUSART
}

//*************************** Transmiss„o de Strings pela SERIAL************************************//
void eusart_string(char *str)
{
    while(*str!='\0')
    {
        eusart_write(*str);
        str++;
    }
}

//**************************** Faz a leitura do caractere recebido pelo SERIAL**************************//
char eusart_read(void)
{
    while(!RCIF);                           // Enquanto RCIF == 0, aguarda a chegada de um caractere
    return RCREG;                           // Retorna o caractere recebido
}
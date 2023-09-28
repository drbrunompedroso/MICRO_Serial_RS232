#include "eusart.h"

//********************* Inicialização do Módulo EUSART*************************************//
void eusart_init(void)
{
    TXSTAbits.TXEN = 1;                     // Habilita Transmissão pela EUSART
    RCSTAbits.CREN = 1;                     // Habilita Recpção pela EUSART
    TXSTAbits.SYNC = 0;                     // Habilita modo Assíncrono
    RCSTAbits.SPEN = 1;                     // Configura pinosRC6 e RC7 como TX e RX
    TXSTAbits.BRGH = 0;                     // Controle de Baund Rate
    BAUDCTLbits.BRG16 = 0;                  
    SPBRG = 12;                             // Definição do Baund Rate (12 - 9600 bps)
}

//*************************** Transmissão de caracteres via EUSART*********************************//
void eusart_write(char c)
{
    while(!TRMT);                           // Aguarda a finalização do envio de caracteres
    TXREG = c;                              // Carrega em TXREG e transmite o caractere via EUSART
}

//*************************** Transmissão de Strings pela SERIAL************************************//
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
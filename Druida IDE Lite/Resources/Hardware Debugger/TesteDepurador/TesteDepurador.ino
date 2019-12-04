//*************************************************************************************************/
//   Projeto    : Teste Depurador
//   Arquivo    : TesteDepurador.ino
//   Descri��o  : Configura��es e loop principal
//   Data       : 07/05/2019
//*************************************************************************************************/

#include "HardwareDebugger.h"
HardwareDebugger Debugger;
#define delay Debugger.delay

void setup()
{
    // coloque aqui o seu c�digo de configura��o para ser executado uma vez:
    Debugger.begin();
}

void loop()
{
    // coloque seu c�digo principal aqui, para executar repetidamente:
    Debugger.main();
}
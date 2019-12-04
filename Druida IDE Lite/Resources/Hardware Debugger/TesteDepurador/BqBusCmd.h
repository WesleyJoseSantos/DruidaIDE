#ifndef BqbusCmd_h
#define BqbusCmd_h
#include <Arduino.h>

#define BqPort Serial                                                   //Porta serial utilizada no protocolo BqBusCmd. \nPode ser alterada diretamente na biblioteca para uso das portas Serial1, 2, 3, etc.

class BqBusCmd                                                          //Classe para controle do protocolo BqBusCmd.
{
public:
    BqBusCmd();
    BqBusCmd(byte _numMaxRegs);                                         //Construtor da classe\n\nPar�metros:\n_numMaxTrans: N�mero de var�veis compartilhadas na rede.
    void begin(long vel);                                               //Inicializa a porta serial na velocidade especificada.
    void comunicacao();                                                 //Realiza um ciclo completo da comunica��o, que consiste em verificar dados da porta serial\ne agrup�-los nos registradores, e reenviar os dados atualizados para o computador.
    int  getReg(unsigned int reg);                                      //Obt�m o valor de uma das vari�veis compartilhadas na rede.\n\nPar�metros:\npos: endere�o/posi��o da vari�vel desejada.
    void setReg(unsigned int reg, unsigned int val);                    //Modifica o valor de uma das vari�veis compartilhadas na rede.\n\nPar�metros:\npos: endere�o da vari�vel desejada.\nval: valor a ser escrito na vari�vel.
    int getRegBit(unsigned int reg, byte bit);                          //Obt�m um bit de um valor de uma das vari�veis compartilhadas na rede.\n\nPar�metros:\npos: endere�o da vari�vel desejada.\nbit: o d�gito bin�rio desejado\n\nNOTA: Ao utilizar um registrador para leitura ou escrita de bit, o mesmo n�o pode ser utilizado\npara leitura ou escrita de valores inteiros.
    void setRegBit(unsigned int reg, byte bit, bool state);             //Modifica um bit de um valor de uma das vari�veis compartilhadas na rede.\n\nPar�metros:\npos: endere�o da vari�vel desejada.\nbit: o d�gito bin�rio desejado\nstate: estado a ser escrito no bit.\n\nNOTA: Ao utilizar um registrador para leitura ou escrita de bit, o mesmo n�o pode ser utilizado\npara leitura ou escrita de valores inteiros.
private:
    void escrita(); 
    void escrita(byte num);                                             
    void varMonitor(unsigned int regAddress, unsigned int var);
    void bitMonitor(unsigned int regAddress, byte regBit, bool var);
    void leitura(char digito);
    bool escritaRealizada;
    void zeraFuncao();
    bool escritaCompleta();
    int  vel;
    int  setControle[10];
    byte numMaxTrans;
    long regToChange[8];
    unsigned int* regs;
};

#endif
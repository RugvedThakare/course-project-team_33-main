#include"semanticParser.h"

void executeCommand();

void executeCLEAR();
void executeCROSS();
void executeDISTINCT();
void executeEXPORT();
void executeINDEX();
void executeJOIN();
void executeLIST();
void executeLOAD();
void executePRINT();
void executePROJECTION();
void executeRENAME();
void executeSELECTION();
void executeSORT();
void executeSOURCE();
void executeLOADMATRIX();
void executePRINTMATRIX();
void executeEXPORTMATRIX();
void executeROTATEMATRIX();
void executeCROSSTRANSPOSEMATRIX();
void executeCHECKANTISYM();

bool evaluateBinOp(int value1, int value2, BinaryOperator binaryOperator);
void printRowCount(int rowCount);
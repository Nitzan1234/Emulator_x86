#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Assembly_x86_Functions_Instructions.c"
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct
{
    uint32_t EAX,
    uint32_t EBX,
    uint32_t ECX,
    uint32_t EDX,
    uint32_t ESI,
    uint32_t EDI,
    uint32_t EBP,
    uint32_t ESP,
    uint32_t ECS,
    uint32_t EDS,
    uint32_t EES,
    uint32_t ESS,
    uint32_t EIP,
    uint32_t EFLAGS,
}CPU_REGISTERS;

typedef enum
{
MOV,
CMOV,
XCHG,
BSWAP,
XADD,
CMPXCHG,
PUSH,
POP,
IN,
OUT,
CBW,
CWDE,
CWD,
CDQ,
MOVSX,
MOVZX,
ADD,
ADC,
SUB,
SBB,
MUL,
DIV,
INC,
DEC,
NEG,
CMP,
DAA,
DAS,
AAA,
AAS,
AAM,
AAD,
AND,
OR,
XOR,
NOT,
SHL,
SHR,
SAL,
SAR,
ROR,
ROL,
RCL,
RCR,
BTS,
BTR,
BTC,
BSF,
BSR,
SET,
TEST,
JMP,
JN,
JE,
LOOP,
CALL,
RET,
INT,
IRET,
ENTER,
LEAVE,
BOUND,
MOVS,
CMPS,
SCAS,
LODS,
STOS,
INS,
OUTS,
REP,
STC,
CLC,
CMC,
STD,
CLD,
STI,
CLI,
LAHF,
SAHF,
PUSHF,
POPF,
LDS,
LES,
LFS,
LGS,
LSS,
LEA,
NOP,
UD2,
XLAT,
CPUID,
}Integer_Assembly_Commands;

typedef enum
{
LGDT,
SGDT,
LLDT,
SLDT,
LTR,
STR,
LIDT,
SIDT,
LMSW,
SMSW,
CLTS,
ARPL,
LAR,
LSL,
VERR,
VERW,
INVD,
WBINVD,
INVLPG,
LOCK,
HLT,
RSM,
RDMSR,
WRMSR,
RDPMC,
RDTSC,
SYSENTER,
SYSEXIT,
}System_Assembly_Commands

typedef enum
{
VMPTRLD,
VPTRST,
VMCLEAR,
VMREAD,
VMWRITE,
VMCALL,
VMLAUNCH,
VMRESUME,
VMXOFF,
VMXON,
INVEPT,
INVVPID
}VirtualMachine_Assembly_Commands;

typedef struct
{
   int* RAM;
}RAM_Struct;

void* Return_Memory_RAM_Address(uint16_t size)
{
    RAM_Struct RAM1;
    RAM1.RAM = &RAM1;
    return RAM1.RAM;
}

char* getFileName(const char* path) {
    char* fileName = strrchr(path, '/');
    if (fileName == NULL)
        fileName = strrchr(path, '\\');
    if (fileName == NULL)
        fileName = (char*)path;
    else
        fileName++;

    return fileName;
}

int main(int argc, char* argv[])
{
    FILE *file;
    char line[MAX_LINE_LENGTH];
     if (argc < 1)
     {
        printf("No command-line arguments provided.\n");
        return 1;
     }

    char* fileName = getFileName(argv[0]);
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file) == != NULL)
        {
            Instruction_Executer(line);
        }
    fclose(file);
    return 0;
}

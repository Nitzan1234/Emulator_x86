#include <stdio.h>
#include <stdint.h>

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
MOV : "MOV",
CMOV :"CMOV",
XCHG :"XCHG",
BSWAP :"BSWAP",
XADD :"XADD",
CMPXCHG :"CMPXCHG",
PUSH :"PUSH",
POP :"POP",
IN :"IN",
OUT :"OUT",
CBW :"CBW",
CWDE :"CWDE",
CWD :"CWD",
CDQ :"CDQ",
MOVSX :"MOVSX",
MOVZX:"MOVZX",
ADD:"ADD",
ADC:"ADC",
SUB:"SUB",
SBB:"SBB",
MUL:"MUL",
DIV:"DIV",
INC:"INC",
DEC:"DEC",
NEG:"NEG",
CMP:"CMP",
DAA:"DAA",
DAS:"DAS",
AAA:"AAA",
AAS:"AAS",
AAM:"AAM",
AAD:"AAD",
AND:"AND",
OR:"OR",
XOR:"XOR",
NOT:"NOT",
SHL:"SHL",
SHR:"SHR",
SAL:"SAL",
SAR:"SAR",
ROR:"ROR",
ROL:"ROL",
RCL:"RCL",
RCR:"RCR",
BTS:"BTS",
BTR:"BTR",
BTC:"BTC",
BSF:"BSF",
BSR:"BSR",
SET:"SET",
TEST:"TEST",
JMP:"JMP",
JN:"JN",
JE:"JE",
LOOP:"LOOP",
CALL:"CALL",
RET:"RET",
INT:"INT",
IRET:"IRET",
ENTER:"ENTER",
LEAVE:"LEAVE",
BOUND:"BOUND",
MOVS:"MOVS",
CMPS:"CMPS",
SCAS:"SCAS",
LODS:"LODS",
STOS:"STOS",
INS:"INS",
OUTS:"OUTS",
REP:"REP",
STC:"STC",
CLC:"CLC",
CMC:"CMC",
STD:"STD",
CLD:"CLD",
STI:"STI",
CLI:"CLI",
LAHF:"LAHF",
SAHF:"SAHF",
PUSHF:"PUSHF",
POPF:"POPF",
LDS:"LDS",
LES:"LES",
LFS:"LFS",
LGS:"LGS",
LSS:"LSS",
LEA:"LEA",
NOP:"NOP",
UD2:"UD2",
XLAT:"XLAT",
CPUID:"CPUID"
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

void Instruction_Executer(char* Command)
{
        asm [ volatile ] (Command);
}
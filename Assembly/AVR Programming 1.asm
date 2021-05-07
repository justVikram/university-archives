; Swap contents of memory locations [200, 209] with [300, 309].

LDI R26, 0x00;
LDI R27, 0x02;

LDI R28, 0x00;
LDI R29, 0x03;

LDI R20, 0x09;

LOOP_9_TIMES: 
LD R16, X;
LD R17, Y;

ST X+, R17;
ST Y+, R16;

DEC R20;
BRNE LOOP_9_TIMES;


; Swap contents of R16 and 0x100;

LD XL, 0x00;
LD XH, 0x01;

MOV R17, R16;

LD R16, X;
ST X, R17;

    ; Using XCH

    LD ZL, 0x00;
    LD ZH, 0x01;

    XCH Z, R16;


; Exchange contents of 0x100 and 0x200.

LD XL, $00;
LD XH, $01;

LD YL, $00;
LD YH, $02;

LD R16, X;
LD R17, Y;

ST X, R17;
ST Y, R16;


; Biggest of [PORTB] and [0x100] and move it into R10.

LDI R20, $0;
OUT DDRB, R20;  ; To make PINB (PORTB act as I/P port)

LDS R16, $100;
IN  R17, PINB;

CP R16, R17;
BRGE R16_GREATER;
MOV R10, R17;

R16_GREATER:
MOV R10, R16;


; Read [PORTB] and check if it is even or odd. Store $00 in PORTC if even, else store $FF.

LDI R20, $0;
OUT DDRB, R20;

LDI R20, $FF;
OUT DDRC, R20;

IN R16, PINB;

LSR R16
BRCS ODD;
LDI R21, $0;
OUT PINC, R21;
JMP TERMINATE;

ODD:
LDI R21, $FF;
OUT PINC, R21;

TERMINATE: 
NOP;


; Sum of array elements from $100 to $110.

LDI XH, $01;

LDI R16, $10;    //COUNTER
LDI R20, $0;    //Hold sum of array elements

LOOP_10_TIMES:
LD R17, X+;
ADD R20, R17;

DEC R16;
BRNE LOOP_10_TIMES;

TERMINATE: JMP TERMINATE;







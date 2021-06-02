; Create square wave of 50% DC on the PORTB.5 bit. Timer0 is used to generate the time delay.

    ; --INITSTACK DEF--
    LDI R20, HIGH (RAMEND);
    OUT  SPH, R20;
    LDI R20, LOW (RAMEND);
    OUT SPL, R20;
    ; --INITSTACK DEF--

    SBI DDRB, 5;
    
    LDI R16, $00;
    LDI R17, $20;
    OUT PORTB, R17;
    
    TRANSITION:
        CALL MAKE_DELAY;

        ; --TOGGLE THE BITS--
        EOR R17, R16;
        OUT PORTB, R17;
        ; --TOGGLE THE BITS--

        JMP TRANSITION;

    MAKE_DELAY:
        ; --LOADING TCNT--
        LDI R20, $F2;
        OUT TCNT0, R20;
        ; --LOADING TNCT--

        ; --CONFIGURING TIFR--
        LDI R20, $01;   NORMAL MODE
        OUT TCCR, R20;
        ; --CONFIGURING TIFR--

        ; --CHECKING VALUE OF TOV--
        CHECK:
            LDI R20, TIFR;
            SBRS R20, TOV0;
            JMP CHECK;
        ; --CHECKING VALUE OF TOV--

        ; --STOP TIMER--
        LDI R20, $0;
        OUT TCCR, R20;
        ; --STOP TIMER--

        ; --CLEARING TOV FLAG--
        LDI R20, (1<<TOV0);
        OUT TIFR, R20;
        RET;
        ; --CLEARING TOV FLAG--
MYCODE SEGMENT 'CODE'
    ASSUME CS:MYCODE
START:
; ����㧪� ᥣ���⭮�� ॣ���� ������ DS
     PUSH CS
     POP  DS    
; �뢮� ᨬ����� � ��ॢ�� ��ப�
     MOV DL , '�'
     CALL PUTCH
     CALL CLRF 
     MOV DL , '�'
     CALL PUTCH                  	
     CALL CLRF             
     MOV DL , '�'
     CALL PUTCH
; �������� �����襭�� �ணࠬ��
     CALL GETCH               
; �뢮� �� �ணࠬ��
     MOV AL , 0
     MOV AH , 4CH
     INT 21H
; ��楤���:     
; ��ॢ�� �� ����� ��ப�
CLRF PROC
    MOV DL , 10
    CALL PUTCH
    MOV DL , 13
    CALL PUTCH
    RET 
CLRF ENDP
; �뢮� ������ ᨬ���� �� �࠭
PUTCH PROC
    MOV AH , 02H
    INT 021H
    RETN 
PUTCH ENDP
; ���� ᨬ���� � ���������� � AL
GETCH PROC
    MOV AH , 08H
    INT 021H
    RET 
GETCH ENDP 
MYCODE ENDS
END START
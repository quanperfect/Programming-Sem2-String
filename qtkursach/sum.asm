.686
.MODEL FLAT, C
PUBLIC sum
_DATA SEGMENT
_DATA ENDS
_TEXT SEGMENT
sum PROC a:dword, b:dword
mov EAX, a
mov EBX, b
add EAX, EBX
ret
sum ENDP
_TEXT ENDS
END
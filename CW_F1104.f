!F1104
!3430302/90003
!Biga V.S.

Program CW_F1104
!Implicit NONE
INTEGER  X1,Y1,X2,Y2
open (7, file="input1104.txt")
read (7,*) X1,Y1,X2,Y2
close (7)
IF ( abs( (X1-X2)*(Y1-Y2) ) == 2 ) THEN
  print *, 'YES'
ELSE
  print *,'NO'
END IF
END

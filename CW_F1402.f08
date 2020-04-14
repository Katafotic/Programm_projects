 	  PROGRAM F1402
 	  IMPLICIT NONE
 	  INTEGER :: M, N, S1, S2, tmp=0
 	  INTEGER i, j
 	  INTEGER, allocatable :: D(:,:)

	  PRINT *, 'F1402'
	  PRINT *, '3430302/90003'
	  PRINT *, 'Biga V.S.'
	  PRINT *, ''

	  OPEN (7, FILE='input1402.txt', ACTION='READ', IOSTAT=tmp)
	  IF (tmp .NE. 0 ) THEN
	 		PRINT *,'ERROR. Cannot open file.'
			STOP
	  END IF

	  READ (7,*) M, N, S1, S2
	  ALLOCATE (D(M,N))

 	  DO i=1,M
		 READ(7, *) (D(i,j), j = 1,N)
	  END DO

	  CALL Printer(M, N, D)
	  DO i=1,N
		 	tmp = D(S1,i)
			D(S1,i) = D(S2,i)
			D(S2,i) = tmp
	  END DO
	  PRINT *, ''

	  CALL Printer(M, N, D)
	  DEALLOCATE (D)

          END PROGRAM


          SUBROUTINE Printer (M, N, D)
	  INTEGER D(M,N)
	  PRINT *, ''
	  DO i=1,M
	 		PRINT *, (D(i, j), j = 1, N)
	  END DO
          END SUBROUTINE Printer

IDENTIFICATION DIVISION.
PROGRAM-ID. Jutta.
ENVIRONMENT DIVISION.
DATA DIVISION.
WORKING-STORAGE SECTION.
           01 erste PICTURE IS 9999.
           01 zweite PICTURE IS 9999.
           01 summe PICTURE IS 99999999.
LINKAGE SECTION.
PROCEDURE DIVISION.
        ACCEPT erste.
        ACCEPT zweite.
        COMPUTE summe = erste + zweite
        DISPLAY summe.
STOP RUN.

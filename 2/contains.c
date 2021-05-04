    #include <stdlib.h> // for atoi() and friends
    #include <stdio.h>
    #include <string.h>
    // takes two arguments: an integer followed by a float
    int main( int argc, char* argv[] )
    {

if (strstr(argv[1], argv[2] ) != NULL) {
    printf("true\n");
    }
    else {
    printf("false\n");
      }
return 0;
    }
#include <stdio.h>
#include <pthread.h>

// ccp source target

// threaded:
// - different threads read/write different sections of the file

// clayton read
int cread(FILE * srcf) {

    int c;
    while ( ( c = fgetc(srcf) ) != EOF ) {
        printf("%c", c);
    }

}

int main(int argc, char *argv[]) {
    
    pthread_t thread_id;
    
    char * srcfn = argv[1];
    char * tarfn = argv[2];
    
    FILE * srcf;
    FILE * tarf;
    
    srcf = fopen(srcfn, "r");
    
    pthread_create(&thread_id, NULL, cread, srcf);
    //pthread_join(thread_id, NULL);
    
    // close files
    fclose(srcf);
    //fclose(tarf);

    return 0;
}
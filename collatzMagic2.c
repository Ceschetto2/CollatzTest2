#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int collatz(mpz_t n_org);
int collatz_condition(mpz_t n, mpz_t n_org); 

int main()
{
    //curses no buffered input
    initscr();
    noecho();
    raw();
    timeout(0);
    cbreak();

    mpz_t n_org;
    mpz_init(n_org);

    FILE * fp;
    fp = fopen("zippero.txt", "r+");
    if (fp == NULL)
    {
        puts("Errore. File non trovato.");
        exit(1);
    }

    gmp_fscanf(fp, "%Zd", n_org);
    fclose(fp);

    printw("Premenre un tasto qualsiasi per terminare e salvare\nTesting in corso...\n");
    while (getch() == EOF)
    {
        mpz_add_ui(n_org, n_org, 1);

        collatz(n_org);
    }

    endwin();
    
    fp = fopen("zippero.txt", "r+");
    if(gmp_fprintf(fp, "%Zd", n_org) == -1) gmp_printf("Errore, non è stato possibile scrivere su file");

    gmp_printf("Ultimo numero controllato: %Zd", n_org);

    return 0;
 

}

int collatz(mpz_t n_org)
{
    mpz_t n;

    mpz_init(n);
    mpz_set(n, n_org);
    do
    {

        while (!mpz_odd_p(n))
            mpz_fdiv_q_2exp( n, n, 2);
        
        
        
        mpz_addmul_ui(n, n, 2);
        mpz_add_ui(n, n, 1);
    

    }while(collatz_condition(n, n_org));


    mpz_clear(n);
            
}

int collatz_condition(mpz_t n, mpz_t n_org)
{
    int cmp = 0;
    if ( (cmp = mpz_cmp(n, n_org)) > 0)
    {
        return 1;
    }
    else
    {
        if (cmp == 0)
        {
            puts("Complimenti, sei milionario");
            gmp_printf("%Zd", n_org);
            exit(0);
        }
        return 0;
    }
        
}

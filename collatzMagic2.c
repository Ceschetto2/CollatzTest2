#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

int collatz(mpz_t n_org);
int collatz_condition(mpz_t n, mpz_t n_org);

int main()
{
    mpz_t n_org;
    mpz_init_set_str(n_org, "29514791000000000000", 10);

    while (1)
    {
        mpz_add_ui(n_org, n_org, 1);
        gmp_printf("testing: %Zd\n", n_org);
        collatz(n_org);
    }
    


    

}

int collatz(mpz_t n_org)
{
    mpz_t n;

    mpz_init(n);
    mpz_set(n, n_org);
    do
    {

        if (!mpz_odd_p(n))
        {
            mpz_div_ui(n, n, 2);
        }
        else
        {
            mpz_addmul_ui(n, n, 2);
            mpz_add_ui(n, n, 1);
        }
        
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

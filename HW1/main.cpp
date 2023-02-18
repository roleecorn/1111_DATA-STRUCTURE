
#include <time.h>
#include "v1.h"
#include "v2.h"
int main()
{
    float START, END1, END2;
    std::ofstream outfile;
    string outf = "h1.out";
    string infile = "h1.in";
    outfile.open(outf, std::ios_base::app); // append instead of overwrite
    outfile<< "method1"<< endl;
	START = clock();
    
    transpose1(infile = infile, outf = outf);
    END1 = clock();
    outfile<< "method2"<< endl;
    transpose2(infile = infile, outf = outf);
    END2 = clock();
    

    
    outfile<< "method1 "<<1000*(END1-START) / CLOCKS_PER_SEC << "(ms)"<< endl;
    outfile<< "method2 "<<1000*(END2-END1) / CLOCKS_PER_SEC << "(ms)"<< endl;
    return 0;
}

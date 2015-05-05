typedef double (*RegraEscolhida)(double,double);

double IntegracaoNumerica(double pontoInicial, double pontoFinal, int numeroDePartes, RegraEscolhida regraEscolhida);

double regraDoTrapezioFechado(double a, double b);
double regraDoTrapezioAberto(double a, double b);

double regraDeSimpsonUmTercoFechado(double a, double b);
double regraDeSimpsonUmTercoAberto(double a, double b);

double regraDeSimpsonTresOitavosFechado(double a, double b);
double regraDeSimpsonTresOitavosAberto(double a, double b);

double funcaoPolinomial(double x);

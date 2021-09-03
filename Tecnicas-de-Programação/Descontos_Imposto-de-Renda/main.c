#include <stdio.h>

int main ()
{
  float salario, desconto;

  printf ("Digite seu salario: ");
  scanf ("%f", &salario);

  if (salario <= 1903.98)
    {
      desconto = 0;
    }
  else if((salario >= 1903.99) && (salario <= 2826.65))
    {
      desconto = salario * 0.075;
    }
  else if((salario >= 2826.66) && (salario <= 3751.05))
  {
    desconto = salario * 0.15;
  }
  else if((salario >= 3751.06) && (salario <= 4664.68))
  {
    desconto = salario * 0.225;
  }
  else if(salario > 4664.68)
  {
    desconto = salario * 0.275; 
  }

  printf ("salario= %.2f\tDesconto IRRF: %.2f", salario, desconto);
  return 0;

}
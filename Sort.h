#pragma once
#include <Arduino.h>
namespace Sort
{
  namespace Utility
  {
    	template<typename T> inline void swap(T & d1,T & d2)
	{
	  d1^=d2^d1^d2;
	}
	template<typename T>void fusion(T * tableau,int deb1,int fin1,int fin2)
	{
	  int *table1;
	  int deb2=fin1+1;
	  int compt1=deb1;
	  int compt2=deb2;
	  int i;

	  table1=new int[fin1-deb1+1];

	  //on recopie les éléments du début du tableau
	  for(i=deb1;i<=fin1;i++)
	    table1[i-deb1]=tableau[i];
	  

	  for(i=deb1;i<=fin2;i++)
	  {
	    if (compt1==deb2) //c'est que tous les éléments du premier tableau ont été utilisés
	      break; //tous les éléments ont donc été classés
	    
	    else if (compt2==(fin2+1)) //c'est que tous les éléments du second tableau ont été utilisés
	    {
	      tableau[i]=table1[compt1-deb1]; //on ajoute les éléments restants du premier tableau
	      compt1++;
	    }
	    else if (table1[compt1-deb1]<tableau[compt2])
	    {
	      tableau[i]=table1[compt1-deb1]; //on ajoute un élément du premier tableau
	      compt1++;
	    }
	    else
	    {
	      tableau[i]=tableau[compt2]; //on ajoute un élément du second tableau
	      compt2++;
	    }
	  }

	  delete [] table1;
	  table1=NULL;
	}
	template<typename T,int const deb,int const fin>void merge_bis(T *tableau)
	{
	  if (deb!=fin)
	  {
	    const int milieu=(fin+deb)/2;
	    Sort::Utility::merge_bis<T,deb,milieu>(tableau);
	    Sort::Utility::merge_bis<T,milieu+1,fin>(tableau);
	    Sort::Utility::fusion<T>(tableau,deb,milieu,fin);
	  }
	}
  }

  	template<typename T, int const n>void Buble(T *data)
	{
	  bool inversion;
	  int t=n;
	  do
	  {
	     inversion=false;

	     for(auto i=0;i<t-1;i++)
	     {
		if (data[i]>data[i+1])
		{
		   Sort::Utility::swap<short int>(data[i],data[i+1]);
		   inversion=true;
		}
	     }
	     t--;
	  }
	  while(inversion);
	}

	template<typename T,int const n>void Merge(T *data)
	{
	  if(n>0)
	     Sort::Utility::merge_bis<T,0,n-1>(data);
	}
}

#pragma once

namespace Sort
{
  namespace Utility
  {
    namespace Heavy
    {
        template<typename T> inline void swap(T & d1,T & d2)
        {
          d1^=d2^d1^d2;
        }
        template<typename T,int deb1,int fin1,int fin2>void fusion(T * tableau)
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
            Sort::Utility::Heavy::merge_bis<T,deb,milieu>(tableau);
            Sort::Utility::Heavy::merge_bis<T,milieu+1,fin>(tableau);
            Sort::Utility::Heavy::fusion<T,deb,milieu,fin>(tableau);
          }
        }
    }
    namespace Light
    {
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
        template<typename T>void merge_bis(T *tableau,int const deb,int const fin)
        {
          if (deb!=fin)
          {
            const int milieu=(fin+deb)/2;
            Sort::Utility::Light::merge_bis<T>(tableau,deb,milieu);
            Sort::Utility::Light::merge_bis<T>(tableau,milieu+1,fin);
            Sort::Utility::Light::fusion<T>(tableau,deb,milieu,fin);
          }
        }
        template<typename T> void swap(T & d1,T & d2)
        {
          d1^=d2^d1^d2;
        }
    }
  }
    namespace Heavy
    {
        template<typename T, int const n>void Bubble(T *data)
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
               Sort::Utility::Heavy::swap<short int>(data[i],data[i+1]);
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
             Sort::Utility::Heavy::merge_bis<T,0,n-1>(data);
        }
    }
    namespace Light
    {
        template<typename T>void Bubble(T *data,int const n)
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
                   Sort::Utility::Light::swap<short int>(data[i],data[i+1]);
                   inversion=true;
                }
             }
             t--;
          }
          while(inversion);
        }

        template<typename T>void Merge(T *data,int const n)
        {
          if(n>0)
             Sort::Utility::Light::merge_bis<T>(data,0,n-1);
        }
    }
}

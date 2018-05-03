/*
Ali Ozturk - 150114061
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include "BSTKutuphane.h"
int toplamDugumBST=0;


//____________________________________________BST Library_________________________________________________\\


dugumBST *dosyaOkuBST(dugumBST *kokAgac,char dosyaIsmi[42])
{
	
    FILE *dosya;
	dosya=fopen(dosyaIsmi,"r");    
    char veriKutusu[42];
  
    
		while(fscanf(dosya,"%s",veriKutusu)!=EOF)
		{    
	      kokAgac=dugumEkle(kokAgac,veriKutusu);							      
		}
		
	fclose(dosya);
	return 	kokAgac;
}


void sayiciBST(dugumBST *liste) 
{
			
	if (liste!=NULL)
	{
				
		sayiciBST(liste->solKol);		       
		sayiciBST(liste->sagKol);
		toplamDugumBST++;
			
		
	}

	
}

// <!-----------------new node add to available tree -----------------!>
dugumBST *dugumEkle(dugumBST *kokAgac,char veriKutusu[42])
{

		dugumBST *seyyah=kokAgac;
					
		if (seyyah == NULL) { 
		
	
			seyyah=(dugumBST*)malloc(sizeof(dugumBST));	
			strcpy(seyyah->veri,veriKutusu);	
			seyyah->solKol=seyyah->sagKol=NULL;
		    
			return seyyah;
	    
		}
		else 
		{
			if (strcmp(seyyah->veri,veriKutusu)>0) 
			{
				
				seyyah->solKol=dugumEkle(seyyah->solKol,veriKutusu);
				
			}
			else if (strcmp(seyyah->veri,veriKutusu)<0) 
			{
				
			   seyyah->sagKol =dugumEkle(seyyah->sagKol,veriKutusu);	
			
			}
		}	
		return seyyah;
							
}



dugumBST *dugumSil(dugumBST *kokAgac,char veri[42])
{
	

        dugumBST *kutu;	

		if (strcmp(veri, kokAgac->veri)<0){
			
		
	     kokAgac->solKol=dugumSil(kokAgac->solKol,veri);
		
	    }
		else if(strcmp(veri, kokAgac->veri)>0)
		 {
		
		kokAgac->sagKol=dugumSil(kokAgac->sagKol,veri);
		}
		
		
		else //node with key found!!!
		if (kokAgac->sagKol && kokAgac->solKol) { //if node has two children
		kutu=bulMin(kokAgac->sagKol); //find smallest key of right subtree of node with key
		strcpy(kokAgac->veri,kutu->veri); //replace removed data by smallest key of right subtree
		kokAgac->sagKol=dugumSil(kokAgac->sagKol,kokAgac->veri);
		}
		else { //if node has less than two children
		kutu=kokAgac;
		if (kokAgac->solKol == NULL) kokAgac=kokAgac->sagKol;
		else if (kokAgac->sagKol == NULL) kokAgac=kokAgac->solKol;
		free(kutu);
		}
		
		//sayiciBST(kokAgac); // node sayýsýný bilmek icin
		
		return kokAgac;
		
	
		
}

dugumBST *bulMin (dugumBST *agac)
{
// returns a pointer to node with the minimum key in the BST.
// which one is the node with the minimum key in a BST?
		if (agac != NULL){
		while (agac->solKol != NULL)
		agac=agac->solKol;	
		}
		
		
		return agac;

}

void ilkCumleyiSilBST(dugumBST *kokAgac){
	
	FILE *dosya;
	dosya=fopen("file1.txt","r");    
    char veriKutusu[42];
    int sayac=0;
    int i;
    while(fscanf(dosya,"%s",veriKutusu)!=EOF)
	{    
	      
		kokAgac=dugumSil(kokAgac,veriKutusu);
		
	          for(i=0;veriKutusu[i]!=0;i++){  
	          	  if(veriKutusu[i]<=47 && veriKutusu[i]>=33){
	          	  	
	          	  	 sayac=1;
					}
			  }	
			  
			  if(sayac==1){
					break;
			  }		  						      
	}		
	fclose(dosya);
}

// ------------------------Memory Space -------------
void memoryUsage_BST(dugumBST *dugum)
{
	
	 sayiciBST(dugum);
	int numberOfMallocs_BST = 0;
	int i;
	for( i = 0; i < toplamDugumBST; i++)
	{
		numberOfMallocs_BST += sizeof(dugum->veri);
		numberOfMallocs_BST += sizeof(dugum->solKol);
		numberOfMallocs_BST += sizeof(dugum->sagKol);
	}
	 printf("\nMemory Space : %d\n",numberOfMallocs_BST);
}











